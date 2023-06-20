/*****************************************************************//**
 * File : Source.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 14, 2023
 * Update Date : April 21, 2023
 * Description : This C++ program utilizes opencv functions to count the chess pieces in a sample image.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(void)
{
	// read the sample image as grayscale image
	Mat src = imread("src.jpg", cv::IMREAD_GRAYSCALE);

	// small the size of the given image to see full image
	Mat resizeSrc;
	resize(src, resizeSrc, Size(src.cols / 5, src.rows / 5));

	// create a threshold for turning black & white only
	Mat thresh;
	threshold(resizeSrc, thresh, 100, 255, THRESH_BINARY);

	// break thin edge/noise and leave main texture
	Mat opening;
	Mat openKernel = getStructuringElement(MORPH_RECT, Size(2, 2));
	erode(thresh, opening, openKernel);
	dilate(opening, opening, openKernel);

	// fill the holes
	Mat closing;
	Mat closeKernel = getStructuringElement(MORPH_ELLIPSE, Size(80, 80));
	dilate(opening, closing, closeKernel);
	erode(closing, closing, closeKernel);

	// detect and extract contours from image
	const int MIN_AREA_THRESHOLD = 20;
	int numBlackChess = 0;
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(closing, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	for (const auto& contour : contours)
	{
		double area = contourArea(contour);
		if (area >= MIN_AREA_THRESHOLD)
		{
			numBlackChess++;
		}
	}

	// Output the number of the chess
	std::cout << numBlackChess << std::endl;

	imwrite("result.png", closing);
	imshow("result", closing);

	return 0;
}