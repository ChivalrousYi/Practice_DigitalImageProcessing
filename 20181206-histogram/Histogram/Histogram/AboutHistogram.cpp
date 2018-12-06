/***********************************/
/**图像操作中的图像直方图相关功能实现**/
/**作者：倚大侠**********************/
/***********************************/


#include "stdafx.h"
#include "AboutHistogram.h"



AboutHistogram::AboutHistogram()
{
	mat_origin = new Mat;
}

/**************************************************
*Mat AboutHistogram::openPic(string picPath)
*功能：		打开图片，并以Mat形式存储
*参数：		string picPath：图片路径
*返回值：	Mat:打开图片的存储区域
**************************************************/
Mat AboutHistogram::openPic(String picPath)
{
	Mat img = imread(picPath);
	if (img.empty()) 
	{
		printf("img is empty\n");
		return Mat();
	}

	*mat_origin = img;
	return img;
}

/**************************************************
*void AboutHistogram::showImg(Mat &img)
*功能：		显示图片
*参数：		Mat &img：需要显示的图片
*返回值：	void
**************************************************/
void AboutHistogram::showImg(Mat &img) 
{
	//cvNamedWindow("图片", 0);

	cv:namedWindow("图片", WINDOW_NORMAL);
	cv::imshow("图片", img);
	//cv::waitKey(0);
}

/**************************************************
*Mat AboutHistogram::paintHistogram(Mat &img)
*功能：		绘制灰度直方图
*参数：		Mat &img：需要绘制的图片
*返回值：	Mat：返回灰度直方图
**************************************************/
Mat AboutHistogram::paintHistogram(Mat &img)
{
	//首先肯定是读取图片，转换为灰度图并且在一个窗口上面显示
	cv::Mat sourcePic = img;
	//cv::imshow("Source Picture", sourcePic);

	//定义函数需要的一些变量
	//图片数量nimages
	int nimages = 1;
	//通道数量,我们总是习惯用数组来表示，后面会讲原因
	int channels[1] = { 0 };
	//输出直方图
	cv::Mat outputHist;
	//维数
	int dims = 1;
	//存放每个维度直方图尺寸（bin数量）的数组histSize
	int histSize[1] = { 256 };
	//每一维数值的取值范围ranges
	float hranges[2] = { 0, 255 };
	//值范围的指针
	const float *ranges[1] = { hranges };
	//是否均匀
	bool uni = true;
	//是否累积
	bool accum = false;

	//计算图像的直方图
	cv::calcHist(&sourcePic, nimages, channels, cv::Mat(), outputHist, dims, histSize, ranges, uni, accum);

	//遍历每个箱子(bin)检验，这里的是在控制台输出的。
	for (int i = 0; i < 256; i++)
		printf("bin/value: %d = %f\n", i, outputHist.at<float>(i));
		//std::cout << "bin/value:" << i << "=" << outputHist.at<float>(i) << std::endl;

	//画出直方图
	int scale = 1;
	//直方图的图片
	cv::Mat histPic(histSize[0] * scale, histSize[0], CV_8U, cv::Scalar(255)); \
		//找到最大值和最小值
	double maxValue = 0;
	double minValue = 0;
	cv::minMaxLoc(outputHist, &minValue, &maxValue, NULL, NULL);


	//纵坐标缩放比例
	double rate = (histSize[0] / maxValue)*1.0;

	for (int i = 0; i < histSize[0]; i++)
	{
		//得到每个i和箱子的值
		float value = outputHist.at<float>(i);
		//画直线
		cv::line(histPic, cv::Point(i*scale, histSize[0]), cv::Point(i*scale, histSize[0] - value*rate), cv::Scalar(0));
	}

	return histPic;
}


AboutHistogram::~AboutHistogram()
{
}
