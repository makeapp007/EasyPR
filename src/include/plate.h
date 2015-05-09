//plate

int PLGaussianBlur(RGBPoint *rgbmat,RGBPoint *rgbmat_target,int r);
int PLDeColor(RGBPoint *rgbmat,APoint *amat);
int PLSobel(APoint *amat,APoint *amat_target,char direction);
int PLConvertScaleAbs(APoint *amat,APoint *amat_target);
int PlThreshold(APoint *amat,Point *mat_target,char pros);
int PLMopClode();
int PLMopOpen();
int PLFindRect();
int PLVerifySize();
int PLVerifyRotation();
int PLRotate();
int PLResize();
