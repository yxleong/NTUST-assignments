/*****************************************************************//**
 * File: biLinear.cpp
 * Author: Leong Yah Xuan
 * Create Date: March 24, 2023
 * Update Date: March 30, 2023
 * Description: This C++ program is to magnify image 2 times by implementing Bilinear Interpolation scaling.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;
#define ZOOM 2

int main()
{
	Mat src = imread("src2.jpg", cv::IMREAD_GRAYSCALE);	// η顶瓜
	// Filling your code here

	int width = src.cols * ZOOM;
	int height = src.rows * ZOOM;
	Mat dst = Mat::zeros(Size(width, height), src.type());

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int x1 = floor(x / 2);
			int y1 = floor(y / 2);
			int x2 = ceil(x / 2);
			int y2 = ceil(y / 2);

			double alpha = (double)x / 2 - x1;
			double beta = (double)y / 2 - y1;

			uchar p1 = src.at<uchar>(y1, x1);
			uchar p2 = src.at<uchar>(y1, x2);
			uchar p3 = src.at<uchar>(y2, x1);
			uchar p4 = src.at<uchar>(y2, x2);

			uchar pixel = (1 - alpha) * (1 - beta) * p1 +
				alpha * (1 - beta) * p2 +
				(1 - alpha) * beta * p3 +
				alpha * beta * p4;

			dst.at<uchar>(y, x) = pixel;
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	imwrite("result2.png", dst);

	waitKey();
}