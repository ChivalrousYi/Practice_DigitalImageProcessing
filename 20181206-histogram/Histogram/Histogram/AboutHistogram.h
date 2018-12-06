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

	Mat openPic(String picPath);	//��ͼƬ
	void showImg(Mat &img);			//��ʾͼƬ
	Mat paintHistogram(Mat &img);	//����ֱ��ͼ

	AboutHistogram();				//���캯��
	~AboutHistogram();				//��������


private:
	Mat *mat_origin;
};

