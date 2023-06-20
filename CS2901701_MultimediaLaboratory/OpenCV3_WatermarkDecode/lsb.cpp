/*****************************************************************//**
 * File: lsb.cpp
 * Author: Leong Yah Xuan
 * Create Date: March 24, 2023
 * Update Date: March 30, 2023
 * Description: This C++ program is to decipher the QR Code hidden in the LSB.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("src1.png", cv::IMREAD_GRAYSCALE);	// η顶瓜
	// Filling your code here

	Mat dst = imread("src1.png", cv::IMREAD_GRAYSCALE);

	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			// & 0b00000001: AND
			// (1) get the lowest bit
			// (0) else will be force to 0
			if ((dst.at<uchar>(i, j) & 0b00000001))
			{
				// if the lowest bit is 1
				// then result after AND also be 1
				// set to white
				dst.at<uchar>(i, j) = 255;
			}
			else
			{
				// if the lowest bit is 0
				// then result after AND will be 0
				// set to black
				dst.at<uchar>(i, j) = 0;
			}
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	imwrite("result1.png", dst);

	waitKey();
}