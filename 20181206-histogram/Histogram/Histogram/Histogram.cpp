// Histogram.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int main()
{
	AboutHistogram ah;

	Mat img = ah.openPic("E:\\DigitalImageProcessing\\20181206-histogram\\Histogram\\1.bmp");

	ah.showImg(img);

	img = ah.paintHistogram(img);
	ah.showImg(img);
	waitKey(0);
    return 0;
}

