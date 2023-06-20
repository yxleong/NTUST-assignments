/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: March 10, 2023
 * Update Date: March 10, 2023
 * Description: This C++ program is to convert image from RGB to Gray.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

//int main()
//{
//	Mat src = imread("lenna.jpg", cv::IMREAD_GRAYSCALE);	// ¦Ç¶¥¹Ï
//	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
//	// Filling your code here
//	imshow("src", src);
//	imshow("dst", dst);
//	waitKey();
//}

int main()
{
	Mat src = imread("lenna.jpg", cv::IMREAD_COLOR); /* read RGB */
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1); 

	double ration[3] = { 0.114, 0.587, 0.299 }; /* BGR */
	// Convert the image provided by the Data page to grayscale
	for (int i = 0; i < dst.rows; i++) { /* vertical */
		for (int j = 0; j < dst.cols; j++) { /* horizontal */
			/* get pixel value*/
			Vec3b pixel = src.at<Vec3b>(i, j);

			double Gray = 0;
			for (int c = 0; c < 3; c++) {
				// Gray = 0.299 * Red + 0.587 * Green + 0.114 * Blue
				Gray += pixel[c] * ration[c];
			}
			dst.at<char>(i, j) = (char)Gray;
		}
	}

	imshow("src", src);
	// Output the converted grayscale image
	imshow("dst", dst);

	// save it as a.png type image file
	imwrite("lenna_converted.png", dst);

	waitKey();
}