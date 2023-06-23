/*****************************************************************//**
 * File: Source.cpp
 * Author: Leong Yah Xuan
 * Create Date: April 21, 2023
 * Update Date: April 21, 2023
 * Description: This C++ program is to implement edge detection of Sobel.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

#define THRESHOLD 180
#define SIZE 3

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.jpg", cv::IMREAD_GRAYSCALE);	// η顶瓜
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	// Filling your code here

	float kernelX[SIZE][SIZE] = { {-1, 0, 1},
					{-2, 0, 2},
					{-1, 0, 1} };

	float kernelY[SIZE][SIZE] = { {-1,-2,-1},
					{ 0, 0, 0},
					{ 1, 2, 1} };

	Mat gradX, gradY;
	int padSize = SIZE / 2;
	for (int i = padSize; i < src.rows - padSize; i++)
	{
		for (int j = padSize; j < src.cols - padSize; j++)
		{
			int gradientX = 0, gradientY = 0;
			for (int k = 0; k < SIZE; k++)
			{
				for (int h = 0; h < SIZE; h++)
				{
					int row = i + k - 1;
					int col = j + h - 1;

					gradientX += src.at<uchar>(row, col) * kernelX[k][h];
					gradientY += src.at<uchar>(row, col) * kernelY[k][h];
				}
			}

			int gradient = abs(gradientX) + abs(gradientY);

			if (gradient >= THRESHOLD) gradient = 255;
			else gradient = 0;

			dst.at<uchar>(i, j) = static_cast<uchar>(gradient);
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
}
