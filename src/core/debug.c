//debug

#include "../include/prep.h"
#include "../include/debug.h"

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