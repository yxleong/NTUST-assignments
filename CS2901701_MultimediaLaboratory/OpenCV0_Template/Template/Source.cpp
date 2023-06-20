#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.jpg", cv::IMREAD_GRAYSCALE);	// �Ƕ���
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	// Filling your code here
	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}