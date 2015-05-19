//plate

#include "../include/prep.h"
#include "../include/plate.h"

RGBMat trgbmat;
AMat tamat;
Mat tmat;
Mat tmat2;

//gaussian function
double plGaussian(int x,int y,double sigma){
	return exp(-(x*x+y*y)/(2*sigma*sigma))/(2*PI*sigma*sigma);
}

//gaussian mat
int plCalcGaussianMat(double *gaussianmat,int r,double sigma){
	int i,j;
	double sum=0;
	for (i=0;i<2*r+1;i++){
		for (j=0;j<2*r+1;j++){
			if ((i<=r)&&(j<=r)){
				*(gaussianmat+i*(2*r+1)+j)=plGaussian(i-r,j-r,sigma);
			}else{
				int i0=r-abs(i-r);
				int j0=r-abs(j-r);
				*(gaussianmat+i*(2*r+1)+j)=*(gaussianmat+i0*(2*r+1)+j0);
			}
			sum+=*(gaussianmat+i*(2*r+1)+j);
		}
	}
	for (i=0;i<2*r+1;i++){
		for (j=0;j<2*r+1;j++){
			*(gaussianmat+i*(2*r+1)+j)=*(gaussianmat+i*(2*r+1)+j)/sum;
		}
	}
	return 0;
}

//gaussian blur
int PLGaussianBlur(RGBPoint *rgbmat,RGBPoint *rgbmat_target,int r){

	double sigma=(GaussianD==0)?0.3*((GaussianR-1)*0.5-1)+0.8:GaussianD;	//sigma default function from opencv
	double gaussianmat[2*r+1][2*r+1];
	int result;
	result=plCalcGaussianMat(gaussianmat,r,sigma);

	int i,j,k,l;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			for (k=0;k<2*r+1;k++){
				for (l=0;l<2*r+1;l++){
					int i0=((k-r+i>=MAT_HEIGHT)||(k-r+i<0))?r-k+i:k-r+i;
					int j0=((l-r+j>=MAT_WIDTH)||(l-r+j<0))?r-l+j:l-r+j;
					trgbmat[i][j].r+=gaussianmat[k][l]*(*(rgbmat+i0+j0*(MAT_HEIGHT))).r;
					trgbmat[i][j].g+=gaussianmat[k][l]*(*(rgbmat+i0+j0*(MAT_HEIGHT))).g;
					trgbmat[i][j].b+=gaussianmat[k][l]*(*(rgbmat+i0+j0*(MAT_HEIGHT))).b;
				}
			}
		}
	}
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(rgbmat_target+i+j*(MAT_HEIGHT))=trgbmat[i][j];
		}
	}
}

//gray function
double plCalcGray(double r,double g,double b){
	return r*DeColorR+g*DeColorG+b*DeColorB;
}

//decolor filter
int PLDeColor(RGBPoint *rgbmat,APoint *amat){

	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(amat+i+j*(MAT_HEIGHT))=plCalcGray((*(rgbmat+i+j*(MAT_HEIGHT))).r,(*(rgbmat+i+j*(MAT_HEIGHT))).g,(*(rgbmat+i+j*(MAT_HEIGHT))).b);
		}
	}
}

//sobel function
double plCalcSobel(int x,int y,APoint *amat,double SobleModule[3][3]){
	double sum=0;
	int i,j;
	for (i=0;i<3;i++){
		for (j=0;j<3;j++){
			int i0=((x+i-1>=MAT_HEIGHT)||(x+i-1<0))?x-i+1:x+i-1;
			int j0=((y+j-1>=MAT_WIDTH)||(y+j-1<0))?y-j+1:y+j-1;
			sum+=SobleModule[i][j]*(*(amat+i0+j0*(MAT_HEIGHT)));
		}
	}
	return sum;
}

//Sobel filter
int PLSobel(APoint *amat,APoint *amat_target,char direction){
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			tamat[i][j]=plCalcSobel(i,j,amat,(direction==PLSobel_X)?SobleModuleX:SobleModuleY);
		}
	}
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(amat_target+i+j*(MAT_HEIGHT))=tamat[i][j];
		}
	}
}

//ConvertScaleAbs filter
int PLConvertScaleAbs(APoint *amat,APoint *amat_target){
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			if (*(amat+i+j*(MAT_HEIGHT))>255){
				tamat[i][j]=255;
			}else if (*(amat+i+j*(MAT_HEIGHT))<0){
				tamat[i][j]=0;
			}
		}
	}

	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(amat_target+i+j*(MAT_HEIGHT))=tamat[i][j];
		}
	}
}

//float mat to int mat function
void plClacIntMat(APoint *amat){
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(amat+i+j*(MAT_HEIGHT))=(int)(*(amat+i+j*(MAT_HEIGHT)));
		}
	}
}

//OTSU function
int plClacOTSU(APoint *amat){
	int matcount[256];
	int matWeighting[256];
	int i,j;
	for (i=0;i<=255;i++){
		matcount[i]=0;
		matWeighting[i]=0;
	}
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			matcount[(int)(*(amat+i+j*(MAT_HEIGHT)))]+=1;
			matWeighting[(int)(*(amat+i+j*(MAT_HEIGHT)))]+=(int)(*(amat+i+j*(MAT_HEIGHT)));
		}
	}
	for (i=1;i<=255;i++){
		matcount[i]+=matcount[i-1];	//前向和
		matWeighting[i]+=matWeighting[i-1];	//前向和
	}
	double maxG=0;
	int threshold;
	//平均加权灰度
	double u=1.0*matWeighting[255]/matcount[255];
	for (i=1;i<=255;i++){
		//正向阀值占比
		double w1=1.0*(matcount[255]-matcount[i-1])/matcount[255];
		//平均加权灰度
		double u1=1.0*(matWeighting[255]-matWeighting[i-1])/(matcount[255]-matcount[i-1]);
		//反向阀值占比
		double w2=1-w1;
		//平均加权灰度
		double u2=1.0*matWeighting[i-1]/matcount[i-1];

		double G=w1*(u1-u)*(u1-u)+w2*(u2-u)*(u2-u);
		if (G>maxG){
			maxG=G;
			threshold=i;
		}
	}
	return(threshold);
}

//PlThreshold filter & OTSU
int PlThreshold(APoint *amat,Point *mat_target,char pros){
	plClacIntMat(amat);
	int threshold=plClacOTSU(amat);
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			if (pros==PlThreshold_POSITIVE){
				*(mat_target+i+j*(MAT_HEIGHT))=((*(amat+i+j*(MAT_HEIGHT)))>threshold);
			}else{
				*(mat_target+i+j*(MAT_HEIGHT))=((*(amat+i+j*(MAT_HEIGHT)))<threshold);
			}
		}
	}
}

int PLExpand(Point *mat,Point *mat_target,int height,int width){
	int i,j,k,l;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			tmat2[i][j]=0;
			for (k=-height;k<=height;k++){
				for (l=-width;l<=width;l++){
					if ((i+k<0)|(i+k>=MAT_HEIGHT)|(j+l<0)|(j+l>=MAT_WIDTH)){
						continue;
					}
					if (*(mat+i+k+(j+l)*(MAT_HEIGHT))>tmat2[i][j]){
						tmat2[i][j]=*(mat+i+k+(j+l)*(MAT_HEIGHT));
					}
				}
			}
		}
	}
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(mat_target+i+j*(MAT_HEIGHT))=tmat2[i][j];
		}
	}
}

int PLCorrode(Point *mat,Point *mat_target,int height,int width){
	int i,j,k,l;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			tmat2[i][j]=255;
			for (k=-height;k<=height;k++){
				for (l=-width;l<=width;l++){
					if ((i+k<0)|(i+k>=MAT_HEIGHT)|(j+l<0)|(j+l>=MAT_WIDTH)){
						continue;
					}
					if (*(mat+i+k+(j+l)*(MAT_HEIGHT))<tmat2[i][j]){
						tmat2[i][j]=*(mat+i+k+(j+l)*(MAT_HEIGHT));
					}
				}
			}
		}
	}
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(mat_target+i+j*(MAT_HEIGHT))=tmat2[i][j];
		}
	}
}

int PLMop(Point *mat,Point *mat_target,int height,int width,char direction){
	int result;
	if (direction==PLMOP_CLOSE){
		result=PLExpand(mat,tmat,height,width);
		result=PLCorrode(tmat,tmat,height,width);
	}else{
		result=PLCorrode(mat,tmat,height,width);	
		result=PLExpand(tmat,tmat,height,width);	
	}

	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			*(mat_target+i*(MAT_WIDTH)+j)=tmat[i][j];
		}
	}
}

int PLFindRect(){}
int PLVerifySize(){}
int PLVerifyRotation(){}
int PLRotate(){}
int PLResize(){}