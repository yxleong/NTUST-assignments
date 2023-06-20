/*****************************************************************//**
 * File: smooth.cpp
 * Author: Leong Yah Xuan
 * Create Date: March 17, 2023
 * Update Date: March 23, 2023
 * Description: This C++ program is to implement 5x5 smoothing method without processing around.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

#define KERNEL_SIZE 5

int main()
{
	Mat src = imread("src1.jpg", cv::IMREAD_GRAYSCALE);	// η顶瓜
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	// Filling your code here

	int padSize = KERNEL_SIZE / 2; // for frame
	double weight = 1.0 / (KERNEL_SIZE * KERNEL_SIZE);

	for (int i = padSize; i < src.rows - padSize; i++)
	{
		for (int j = padSize; j < src.cols - padSize; j++)
		{
			double sum = 0.0;
			// uint16_t sum = 0.0;
			for (int k = -padSize; k <= padSize; k++)
			{
				for (int h = -padSize; h <= padSize; h++)
				{
					int row = i + k, col = j + h;
					uchar pixel = (double)src.at<uchar>(row, col);
					sum += weight * pixel;
				}
			}
			dst.at<uchar>(i, j) = static_cast<uchar>(sum);
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	imwrite("result1.png", dst);
	waitKey();
}