/*****************************************************************//**
 * File: median.cpp
 * Author: Leong Yah Xuan
 * Create Date: March 17, 2023
 * Update Date: March 23, 2023
 * Description: This C++ program is to implement 3x3 Median Filtering without processing around.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>
#include<algorithm>

using namespace cv;
using namespace std;

#define KERNEL_SIZE 3

int main()
{
	Mat src = imread("src2.jpg", cv::IMREAD_GRAYSCALE);	// η顶瓜
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	// Filling your code here

	int padSize = KERNEL_SIZE / 2; // for frame

	for (int i = padSize; i < src.rows - padSize; i++)
	{
		for (int j = padSize; j < src.cols - padSize; j++)
		{
			Mat kernel = (Mat_<uchar>(KERNEL_SIZE, KERNEL_SIZE) <<
				src.at<uchar>(i - 1, j - 1), src.at<uchar>(i - 1, j), src.at<uchar>(i - 1, j + 1),
				src.at<uchar>(i, j - 1), src.at<uchar>(i, j), src.at<uchar>(i, j + 1),
				src.at<uchar>(i + 1, j - 1), src.at<uchar>(i + 1, j), src.at<uchar>(i + 1, j + 1));

			std::sort(kernel.begin<uchar>(), kernel.end<uchar>());

			int median = KERNEL_SIZE * KERNEL_SIZE / 2;
			dst.at<uchar>(i, j) = kernel.at<uchar>(median);
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	imwrite("result2.png", dst);
	waitKey();
}