/***********************************/
/**ͼ������е�ͼ��ֱ��ͼ��ع���ʵ��**/
/**���ߣ��д���**********************/
/***********************************/


#include "stdafx.h"
#include "AboutHistogram.h"



AboutHistogram::AboutHistogram()
{
	mat_origin = new Mat;
}

/**************************************************
*Mat AboutHistogram::openPic(string picPath)
*���ܣ�		��ͼƬ������Mat��ʽ�洢
*������		string picPath��ͼƬ·��
*����ֵ��	Mat:��ͼƬ�Ĵ洢����
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
*���ܣ�		��ʾͼƬ
*������		Mat &img����Ҫ��ʾ��ͼƬ
*����ֵ��	void
**************************************************/
void AboutHistogram::showImg(Mat &img) 
{
	//cvNamedWindow("ͼƬ", 0);

	cv:namedWindow("ͼƬ", WINDOW_NORMAL);
	cv::imshow("ͼƬ", img);
	//cv::waitKey(0);
}

/**************************************************
*Mat AboutHistogram::paintHistogram(Mat &img)
*���ܣ�		���ƻҶ�ֱ��ͼ
*������		Mat &img����Ҫ���Ƶ�ͼƬ
*����ֵ��	Mat�����ػҶ�ֱ��ͼ
**************************************************/
Mat AboutHistogram::paintHistogram(Mat &img)
{
	//���ȿ϶��Ƕ�ȡͼƬ��ת��Ϊ�Ҷ�ͼ������һ������������ʾ
	cv::Mat sourcePic = img;
	//cv::imshow("Source Picture", sourcePic);

	//���庯����Ҫ��һЩ����
	//ͼƬ����nimages
	int nimages = 1;
	//ͨ������,��������ϰ������������ʾ������ὲԭ��
	int channels[1] = { 0 };
	//���ֱ��ͼ
	cv::Mat outputHist;
	//ά��
	int dims = 1;
	//���ÿ��ά��ֱ��ͼ�ߴ磨bin������������histSize
	int histSize[1] = { 256 };
	//ÿһά��ֵ��ȡֵ��Χranges
	float hranges[2] = { 0, 255 };
	//ֵ��Χ��ָ��
	const float *ranges[1] = { hranges };
	//�Ƿ����
	bool uni = true;
	//�Ƿ��ۻ�
	bool accum = false;

	//����ͼ���ֱ��ͼ
	cv::calcHist(&sourcePic, nimages, channels, cv::Mat(), outputHist, dims, histSize, ranges, uni, accum);

	//����ÿ������(bin)���飬��������ڿ���̨����ġ�
	for (int i = 0; i < 256; i++)
		printf("bin/value: %d = %f\n", i, outputHist.at<float>(i));
		//std::cout << "bin/value:" << i << "=" << outputHist.at<float>(i) << std::endl;

	//����ֱ��ͼ
	int scale = 1;
	//ֱ��ͼ��ͼƬ
	cv::Mat histPic(histSize[0] * scale, histSize[0], CV_8U, cv::Scalar(255)); \
		//�ҵ����ֵ����Сֵ
	double maxValue = 0;
	double minValue = 0;
	cv::minMaxLoc(outputHist, &minValue, &maxValue, NULL, NULL);


	//���������ű���
	double rate = (histSize[0] / maxValue)*1.0;

	for (int i = 0; i < histSize[0]; i++)
	{
		//�õ�ÿ��i�����ӵ�ֵ
		float value = outputHist.at<float>(i);
		//��ֱ��
		cv::line(histPic, cv::Point(i*scale, histSize[0]), cv::Point(i*scale, histSize[0] - value*rate), cv::Scalar(0));
	}

	return histPic;
}


AboutHistogram::~AboutHistogram()
{
}
