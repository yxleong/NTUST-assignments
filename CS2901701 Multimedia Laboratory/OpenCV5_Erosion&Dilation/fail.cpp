#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

// Manually implement erode function
void erodeImg(InputArray src, OutputArray dst, InputArray element)
{
	Mat srcM = src.getMat();
	Mat elementM = element.getMat();
	Mat dstM;
	dst.copyTo(dstM);

	for (int i = 0; i < srcM.rows; i++)
	{
		for (int j = 0; j < srcM.cols; j++)
		{
			int total = 255; //erode
			for (int k = -elementM.rows / 2; k <= elementM.rows / 2; k++)
			{
				for (int l = -elementM.cols / 2; l <= elementM.cols / 2; l++)
				{
					if (i + k >= 0 && j + l >= 0 && i + k < srcM.rows && j + l < srcM.cols)
					{
						//erode
						if ((int)srcM.at<uchar>(i + k, j + l) != 255)
						{
							total = 0;
						}
					}
				}
			}
			dstM.at<uchar>(i, j) = total;
		}
	}
	dstM.copyTo(dst);
}

void dilateM(InputArray src, OutputArray dst, InputArray element)
{
	Mat srcM = src.getMat();
	Mat elementM = element.getMat();
	Mat dstM;
	dst.copyTo(dstM);

	for (int i = 0; i < srcM.rows; i++)
	{
		for (int j = 0; j < srcM.cols; j++)
		{
			int total = 0;
			for (int k = -elementM.rows / 2; k <= elementM.rows / 2; k++)
			{
				for (int l = -elementM.cols / 2; l <= elementM.cols / 2; l++)
				{
					if (i + k >= 0 && j + l >= 0 && i + k < srcM.rows && j + l < srcM.cols)
					{
						if ((int)srcM.at<uchar>(i + k, j + l) != 0)
						{
							total = 255;
						}
					}
				}
			}
			dstM.at<uchar>(i, j) = total;
		}
	}
	dstM.copyTo(dst);
}


int main(void)
{
	// read the sample image as grayscale image
	Mat src = imread("src.jpg", cv::IMREAD_GRAYSCALE);

	// scale down the size of the given image to see full image
	Mat resizeSrc;
	resize(src, resizeSrc, Size(src.cols / 5, src.rows / 5));

	// create a threshold for turning black & white only
	Mat thresh;
	threshold(resizeSrc, thresh, 100, 255, THRESH_BINARY);

	// break thin edge/noise and leave main texture
	Mat opening;
	//opening.create(thresh.size(), thresh.type());
	Mat openKernel = getStructuringElement(MORPH_RECT, Size(2, 2));
	erodeImg(thresh, opening, openKernel);
	dilate(opening, opening, openKernel);

	// fill the holes
	Mat closing;
	//closing.create(thresh.size(), thresh.type());
	Mat closeKernel = getStructuringElement(MORPH_ELLIPSE, Size(80, 80));
	dilate(opening, closing, closeKernel);
	erodeImg(closing, closing, closeKernel);

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

	return 0;
}