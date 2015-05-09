//main

#include "include/prep.h"
#include "include/debug.h"
#include "include/plate.h"

// Left Top point is (0,0)
// Rgith Bottom point is (MAT_HEIGHT,MAT_WIDTH)
//
//  |——————>y
//  |
// \|/
//  x

RGBMat rgbmat;
AMat amat;
Mat mat;

int main(){
	int result;
	result=Init(rgbmat);
	// result=PrintRGBMat(rgbmat,"000_Init.out");

	result=PLGaussianBlur(rgbmat,rgbmat,GaussianR);
	// result=PrintRGBMat(rgbmat,"001_PLGaussianBlur.out");

	result=PLDeColor(rgbmat,amat);
	// result=PrintAMat(amat,"002_PLDeColor.out");

	result=PLSobel(amat,amat,1);
	// result=PrintAMat(amat,"003_PLSobel.out");

	result=PLConvertScaleAbs(amat,amat);
	// result=PrintAMat(amat,"004_PLConvertScaleAbs.out");

	result=PlThreshold(amat,mat,1);
	result=PrintMat(mat,"005_PlThreshold.out");

	printf("finish\n");
	return 0;
}