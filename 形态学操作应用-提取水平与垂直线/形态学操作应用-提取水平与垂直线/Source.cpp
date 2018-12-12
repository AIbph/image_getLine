#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// ��̬ѧ����Ӧ��-��ȡˮƽ�봹ֱ��	
	// ��ȡͼƬ
	Mat src = imread("D:/OpenCVProject/day1212/��̬ѧ����Ӧ��-��ȡˮƽ�봹ֱ��/��̬ѧ����Ӧ��-��ȡˮƽ�봹ֱ��/test.jpg");
	imshow("origin image", src);

	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);

	Mat bin_src;
	// ����Ӧ��ֵ��   ��ֵ��������ͼ��������һ�ֳ��õ��㷨������ͼ��Ķ�ֵ������һ�������һ����ֵ������
	/*
		cv::InputArray src, // ����ͼ��
		cv::OutputArray dst, // ���ͼ��
		double maxValue, // �������ֵ
		int adaptiveMethod, // ����Ӧ������ƽ�����˹
		int thresholdType // ��ֵ������
		int blockSize, // ���С
		double C // ����
	*/
	adaptiveThreshold(gray_src, bin_src, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 2);
	imshow("binary image", bin_src);

	// ˮƽ�ṹԪ��
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 24, 1), Point(-1, -1));
	// ��ֱ�ṹԪ��
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 24), Point(-1, -1));
	// ���νṹ
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	Mat temp, dst;
	// �ղ�����ȡ��
	morphologyEx(bin_src, dst, CV_MOP_CLOSE, vline);
	imshow("open methgod image", dst);

	waitKey(0);
	return 0;
}