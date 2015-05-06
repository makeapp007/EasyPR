//plate

int PLGaussianBlur(RGBPoint *rgbmat,RGBPoint *rgbmat_target,int r);
int PLDeColor(RGBPoint *rgbmat,APoint *amat);
int PLSobel(APoint *amat,APoint *amat_target,char direction);
int PlThreshold();
int PLMopClode();
int PLMopOpen();
int PLFindRect();
int PLVerifySize();
int PLVerifyRotation();
int PLRotate();
int PLResize();
