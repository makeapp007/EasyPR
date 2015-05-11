//plate

int PLGaussianBlur(RGBPoint *rgbmat,RGBPoint *rgbmat_target,int r);
int PLDeColor(RGBPoint *rgbmat,APoint *amat);
int PLSobel(APoint *amat,APoint *amat_target,char direction);
int PLConvertScaleAbs(APoint *amat,APoint *amat_target);
int PlThreshold(APoint *amat,Point *mat_target,char pros);
int PLExpand(Point *mat,Point *mat_target,int height,int width);
int PLCorrode(Point *mat,Point *mat_target,int height,int width);
int PLMop(Point *mat,Point *mat_target,int height,int width,char direction);
int PLFindRect();
int PLVerifySize();
int PLVerifyRotation();
int PLRotate();
int PLResize();
