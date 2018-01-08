#include<opencv2\opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	Mat imageSource = imread("E:\\train\\301\\1_4_0.jpg");
	//imshow("srcImage", imageSource);
	vector<Mat>imageRGB;
	//RGB��ͨ������
	split(imageSource, imageRGB);
	//��ԭʼͼ���RGB�����ľ�ֵ
	double R, G, B;
	B = mean(imageRGB[0])[0];
	G = mean(imageRGB[1])[0];
	R = mean(imageRGB[2])[0];
	//��Ҫ������RGB����������
	double KR, KG, KB;
	KB = (R + G + B) / (3 * B);
	KG = (R + G + B) / (3 * G);
	KR = (R + G + B) / (3 * R);
	//����RGB��ͨ�����Ե�ֵ
	imageRGB[0] = imageRGB[0] * KB;
	imageRGB[1] = imageRGB[1] * KG;
	imageRGB[2] = imageRGB[2] * KR;
	//RGB��ͨ��ͼ��ϲ�
	merge(imageRGB, imageSource);
	imshow("dstImage", imageSource);
}