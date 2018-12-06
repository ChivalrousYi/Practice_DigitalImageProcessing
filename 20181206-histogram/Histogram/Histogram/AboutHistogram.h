#pragma once

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class AboutHistogram
{
public:

	Mat openPic(String picPath);	//打开图片
	void showImg(Mat &img);			//显示图片
	Mat paintHistogram(Mat &img);	//绘制直方图

	AboutHistogram();				//构造函数
	~AboutHistogram();				//析构函数


private:
	Mat *mat_origin;
};

