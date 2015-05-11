//dlobal

#define MAT_WIDTH 640
#define MAT_HEIGHT 480

#define GaussianR 5
#define GaussianD 0.3	//0 for default function from GaussianR

#define DeColorR 0.299
#define DeColorG 0.587
#define DeColorB 0.244

#define PLSobel_X 1
#define PLSobel_Y 0

#define PlThreshold_POSITIVE 1
#define PlThreshold_NAGARIVE 0

#define PLMOP_HEIGHTR 1
#define PLMOP_WIDTHR 8
#define PLMOP_CLOSE 1
#define PLMOP_OPEN 0

extern const double SobleModuleX[3][3];
extern const double SobleModuleY[3][3];

#define DEFAULT_INPUT "RECG/img.data"
#define DEFAULT_OUTPUT "DEBUG/"