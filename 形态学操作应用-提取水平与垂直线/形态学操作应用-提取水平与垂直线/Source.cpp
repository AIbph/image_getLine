#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv){
	// 形态学操作应用-提取水平与垂直线	
	// 读取图片
	Mat src = imread("D:/OpenCVProject/day1212/形态学操作应用-提取水平与垂直线/形态学操作应用-提取水平与垂直线/test.jpg");
	imshow("origin image", src);

	Mat gray_src;
	cvtColor(src, gray_src, CV_BGR2GRAY);
	imshow("gray image", gray_src);

	Mat bin_src;
	// 自适应阈值化   阈值化操作在图像处理中是一种常用的算法，比如图像的二值化就是一种最常见的一种阈值化操作
	/*
		cv::InputArray src, // 输入图像
		cv::OutputArray dst, // 输出图像
		double maxValue, // 向上最大值
		int adaptiveMethod, // 自适应方法，平均或高斯
		int thresholdType // 阈值化类型
		int blockSize, // 块大小
		double C // 常量
	*/
	adaptiveThreshold(gray_src, bin_src, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, 2);
	imshow("binary image", bin_src);

	// 水平结构元素
	Mat hline = getStructuringElement(MORPH_RECT, Size(src.cols / 24, 1), Point(-1, -1));
	// 垂直结构元素
	Mat vline = getStructuringElement(MORPH_RECT, Size(1, src.rows / 24), Point(-1, -1));
	// 矩形结构
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	Mat temp, dst;
	// 闭操作提取线
	morphologyEx(bin_src, dst, CV_MOP_CLOSE, vline);
	imshow("open methgod image", dst);

	waitKey(0);
	return 0;
}