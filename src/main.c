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

int main(){
	int result;
	result=Init(rgbmat);
	result=PLGaussianBlur(rgbmat,rgbmat,GaussianR);
	result=PLDeColor(rgbmat,amat);
	result=PLSobel(amat,amat,1);
	result=PrintAMat(amat,"test.out");
	printf("hello\n");
	return 0;
}