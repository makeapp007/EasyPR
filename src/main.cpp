#include "include/plate_recognize.h"
#include "include/util.h"
#include "include/feature.h"
#include "include/CParser.h"

using namespace easypr;

//标准读入地址
extern const string NATIVE_RECG_PATH = "RECG";

int show_dialog(Mat src);
int plat_locatte_main(vector<Mat>& resultDT);
int plate_judge_main(vector<Mat>& src, vector<Mat>& resultDT);

// "--test_plate_locate    [ -tpl ]    车牌定位                ",
// "--test_plate_judge     [ -tpj ]    车牌判断                ",
// "--test_plate_detect    [ -tpd ]    车牌检测                ",
// "--test_chars_segment   [ -tcs ]    字符分隔                ",
// "--test_chars_identify  [ -tci ]    字符鉴别                ",
// "--test_chars_recognize [ -tcr ]    字符识别                ",
// "--test_plate_recognize [ -tpr ]    车牌识别                ",
// "--test_all             [ -ta  ]    测试全部                ",
// "--general_test         [ -gt  ]    批量测试-general_test   ",
// "--native_test   

int main(){
	vector<Mat> DT;
	int result = plat_locatte_main(DT);
	result = plate_judge_main(DT, DT);
}

int show_dialog(Mat src){
	imshow("RECG_show", src);
	waitKey(0);
    destroyWindow("plate_locate");
}

int plat_locatte_main(vector<Mat>& resultDT){
	cout << "process plat_locatte_main...";

	Mat src = imread(NATIVE_RECG_PATH+"/test.jpg");

	CPlateLocate plate;
	plate.setDebug(1);
	plate.setLifemode(true);

	int result = plate.plateLocate(src, resultDT);
	if (result == 0)
	{
		int num = resultDT.size();
		for (int j = 0; j < num; j++)
		{
			Mat resultMat = resultDT[j];
			show_dialog(resultMat);
		}
		cout << "OK";
	}

	cout << endl;
	return result;
}

int plate_judge_main(vector<Mat>& src, vector<Mat>& resultDT){
	cout << "process plate_judge_main...";

	//可能是车牌的图块集合
	vector<Mat> resultVec;

	CPlateJudge ju;
	int resultJu = ju.plateJudge(src, resultVec);

	if (0 != resultJu)
		return -1;

	cout << "plate_judge_img" << endl;
	if (resultJu == 0)
	{
		int num = resultVec.size();
		for (int j = 0; j < num; j++)
		{
			Mat resultMat = resultVec[j];
			show_dialog(resultMat);
		}
		cout << "OK";
	}

	cout << endl;
	return resultJu;
}