//pr

#include "../include/prep.h"
#include "../include/debug.h"
#include "../include/plate.h"
#include "../include/pr.h"
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

int PL(){
	int result;

	result=Init(rgbmat);
	// result=PrintRGBMat(rgbmat,"000_Init.out");

	result=PLGaussianBlur(rgbmat,rgbmat,GaussianR);
	// result=PrintRGBMat(rgbmat,"001_PLGaussianBlur.out");

	result=PLDeColor(rgbmat,amat);
	// result=PrintAMat(amat,"002_PLDeColor.out");

	result=PLSobel(amat,amat,PLSobel_X);
	// result=PrintAMat(amat,"003_PLSobel.out");

	result=PLConvertScaleAbs(amat,amat);
	// result=PrintAMat(amat,"004_PLConvertScaleAbs.out");

	result=PlThreshold(amat,mat,PlThreshold_POSITIVE);
	// result=PrintMat(mat,"005_PlThreshold.out");

	result=PLMop(mat,mat,PLMOP_HEIGHTR,PLMOP_WIDTHR,PLMOP_CLOSE);
	result=PrintMat(mat,"006_PLMop.out");

	printf("finish\n");
	return 0;
}