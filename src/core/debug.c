//debug

#include "../include/prep.h"
#include "../include/debug.h"

int ADIInit(RGBPoint *mat,char matyuv[480][640][2]){
	int i,j;
	double y=1;
	double u=1;
	double v=1;
	char handle=1;
	for (j=0;j<MAT_WIDTH;j++){
		for (i=0;i<MAT_HEIGHT;i++){
			y=matyuv[i][j][0];
			if (handle){
				u=matyuv[i][j][1];
				handle=0;
			}else{
				v=matyuv[i][j][1];
				handle=1;
			}
			(*(mat+i*(MAT_WIDTH)+j)).r=y+1.4075*v;
			(*(mat+i*(MAT_WIDTH)+j)).g=y-0.455*u-0.7169*v;
			(*(mat+i*(MAT_WIDTH)+j)).b=y+1.779*u;
		}
	}
	return 0;
}

int Init(RGBPoint *mat){
	FILE *in;
	in=fopen(DEFAULT_INPUT,"r");
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			fscanf(in,"%lf",&((*(mat+i*(MAT_WIDTH)+j)).r));
			fscanf(in,"%lf",&((*(mat+i*(MAT_WIDTH)+j)).g));
			fscanf(in,"%lf",&((*(mat+i*(MAT_WIDTH)+j)).b));
		}
	}
	fclose(in);
	return 0;
}

int PrintRGBMat(RGBPoint *mat,char name[]){
	FILE *out;
	char path[]=DEFAULT_OUTPUT;
	strcat(path,name);
	out=fopen(path,"w");
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			fprintf(out,"%lf %lf %lf\n",(*(mat+i*(MAT_WIDTH)+j)).r,(*(mat+i*(MAT_WIDTH)+j)).g,(*(mat+i*(MAT_WIDTH)+j)).b);
		}
	}
	fclose(out);
	return 0;
}

int PrintAMat(APoint *mat,char name[]){
	FILE *out;
	char path[]=DEFAULT_OUTPUT;
	strcat(path,name);
	out=fopen(path,"w");
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			fprintf(out,"%lf %lf %lf\n",(*(mat+i*(MAT_WIDTH)+j)),(*(mat+i*(MAT_WIDTH)+j)),(*(mat+i*(MAT_WIDTH)+j)));
		}
	}
	fclose(out);
	return 0;
}

int PrintMat(Point *mat,char name[]){
	FILE *out;
	char path[]=DEFAULT_OUTPUT;
	strcat(path,name);
	out=fopen(path,"w");
	int i,j;
	for (i=0;i<MAT_HEIGHT;i++){
		for (j=0;j<MAT_WIDTH;j++){
			fprintf(out,"%lf %lf %lf\n",(*(mat+i*(MAT_WIDTH)+j))*255,(*(mat+i*(MAT_WIDTH)+j))*255,(*(mat+i*(MAT_WIDTH)+j))*255);
		}
	}
	fclose(out);
	return 0;
}