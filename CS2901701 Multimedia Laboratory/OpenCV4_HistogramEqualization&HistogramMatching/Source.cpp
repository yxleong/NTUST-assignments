/*****************************************************************//**
 * File : Source.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 31, 2023
 * UPDATE Date : April 7, 2023
 * Description : This C++ program implememnt Histogram equalization
 *					and Histogram Matching without using library.
 *********************************************************************/
#include<opencv2/opencv.hpp>
#include<iostream>

#define COLOR_RANGE 256
#define HISTOGRAM_COLUMN_SIZE 4

enum HISTOGRAM_COLUMN {
	COUNT = 0,
	CDF_TEMP,
	CDF,
	CORRESPONDENCE_TABLE
};

using namespace cv;
using namespace std;

/**
* Intent : To perform histogram equalization on an input image and generate an output image.
* Pre : The source image must be a valid Mat object.
* Post : The destination image contains the histogram equalized version of the source image.
* \param src
* \param dst
*/
void histogramEqualization(const Mat src, Mat& dst)
{
	// declare variables which are needed
	int totalPixels = src.rows * src.cols;
	int histogram[COLOR_RANGE] = { 0 };
	float probabilityDensity[COLOR_RANGE] = { 0.0 }; // pdf
	float cumulativeDistribution[COLOR_RANGE] = { 0.0 }; // cdf

	// create the histogram of src image
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			// get the pixel value at the (i,j)th location in the source image
			int pixelValue = (int)src.at<uchar>(i, j);

			// increase the count of that pixel value in the histogram array
			histogram[pixelValue]++;
		}
	}

	// calculate the probability density of histogram
	for (int i = 0; i < COLOR_RANGE; i++)
	{
		// Formula: pdf = each pixel value count / the total number of pixel
		probabilityDensity[i] = float(histogram[i]) / totalPixels;
	}

	// calculate the cumulative distribution of histogram
	cumulativeDistribution[0] = probabilityDensity[0];
	for (int i = 1; i < COLOR_RANGE; i++)
	{
		// Formula: cdf = previous cdf + own pdf
		cumulativeDistribution[i] = cumulativeDistribution[i - 1] + probabilityDensity[i];
	}

	// make a histogram equalization to dst
	for (int i = 0; i < dst.rows; i++)
	{
		for (int j = 0; j < dst.cols; j++)
		{
			// get the pixel value at the (i,j)th location in the destination image
			int pixelValue = (int)dst.at<uchar>(i, j);

			// assign (i,j)th location with the specific cdf of pixel value
			dst.at<uchar>(i, j) = (uchar)(cumulativeDistribution[pixelValue] * (COLOR_RANGE - 1));
			// *255 to avoid overflow(>=256)
			// unchar will turn the overflow to 0 to make sure within the valid range 0~255
		}
	}
}

/**
* Intent : To check if two images have same dimensions and pixel values.
* Pre : Both images must be valid Mat objects.
* Post : The function returns a boolean value which indicate whether two images are same.
* \param img1
* \param img2
* \return
*/
//bool isSameImg(const Mat& img1, const Mat& img2)
//{
//	// if both images havaing same rows and columns
//	if (img1.rows != img2.rows || img1.cols != img2.cols)
//	{
//		// if not return false
//		return false;
//	}
//
//	// calculate the sum of pixel value differences between two images
//	Scalar diffPixelValue = sum(img1 - img2);
//	// Scalar: pass pixel values for all images with channels
//
//	// return true if pixel value differences in all channels are 0: same pixel value
//	return (diffPixelValue[0] == 0) && (diffPixelValue[1] == 0) && (diffPixelValue[2] == 0);
//}

/**
* Intent : To correspond the RGB histogram of source to the RGB histogram of target.
* Pre : Both sourceand target images must be valid Mat objects.
* Post : The function performs histogram matching between two images.
* \param src
* \param target
* \param dst
*/
void histogramMatching(Mat& src, Mat& target, Mat& dst)
{
	const int colorChannels = 3;

	for (int i = 0; i < colorChannels; i++)
	{
		// declare variables which are needed
		int srcPixels = src.rows * src.cols;
		int targetPixels = target.rows * target.cols;
		float srcHistogram[HISTOGRAM_COLUMN_SIZE][COLOR_RANGE] = { 0 };
		float targetHistogram[HISTOGRAM_COLUMN_SIZE][COLOR_RANGE] = { 0 };

		// get the column of pixels count in the histogram for image source and target
		for (int j = 0; j < src.rows; j++)
		{
			for (int k = 0; k < src.cols; k++)
			{
				// get the pixel value at the (j,k)th location 
				// of (i)th channel in the source image
				int pixelValue = (int)src.at<Vec3b>(j, k)[i];

				// increase the count of that pixel value
				// in the [0]:COUNT of histogram array
				srcHistogram[HISTOGRAM_COLUMN::COUNT][pixelValue]++;
			}
		}
		for (int j = 0; j < target.rows; j++)
		{
			for (int k = 0; k < target.cols; k++)
			{
				// get the pixel value at the (j,k)th location 
				// of (i)th channel in the source image
				int pixelValue = (int)target.at<Vec3b>(j, k)[i];

				// increase the count of that pixel value
				// in the [0]:COUNT of histogram array
				targetHistogram[HISTOGRAM_COLUMN::COUNT][pixelValue]++;
			}
		}

		for (int j = 0; j < COLOR_RANGE; j++)
		{
			if (j == 0)
			{
				// get the column of cumulative distribution of pixel[0] in the histogram for image source and target
				srcHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j] = float(srcHistogram[HISTOGRAM_COLUMN::COUNT][j]) / srcPixels;
				targetHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j] = float(targetHistogram[HISTOGRAM_COLUMN::COUNT][j]) / targetPixels;
			}
			else
			{
				// get the column of cumulative distribution in the histogram for image source and target
				srcHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j] = srcHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j - 1] + float(srcHistogram[HISTOGRAM_COLUMN::COUNT][j] / srcPixels);
				targetHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j] = targetHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j - 1] + float(targetHistogram[HISTOGRAM_COLUMN::COUNT][j] / targetPixels);
			}

			// round the cumulative distribution calculated
			srcHistogram[HISTOGRAM_COLUMN::CDF][j] = floor(srcHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j] * (COLOR_RANGE - 1));
			targetHistogram[HISTOGRAM_COLUMN::CDF][j] = floor(targetHistogram[HISTOGRAM_COLUMN::CDF_TEMP][j] * (COLOR_RANGE - 1));
		}

		// find the first matched pixel of target image with source image
		for (int j = 0; j < COLOR_RANGE; j++)
		{
			int pixel = 0; // initialize the pixel

			for (int k = 0; k < COLOR_RANGE; k++)
			{
				// if the cumulative distribution of target histogram matches the the source histogram
				if (srcHistogram[HISTOGRAM_COLUMN::CDF][j] == targetHistogram[HISTOGRAM_COLUMN::CDF][k])
				{
					pixel = k; // set the pixel at index of target for making correspondence table
					break; // jump out for loop
				}
			}

			// if match not found = pixel same with the initialized &
			// cumulative distribution of source histogram < 0 -> outside the range
				// since cumulative distribution of source histogram will not < 0
				// if < 0  means the overflow condition is handle already
				// so actually is >= COLOR_RANGE
			if (pixel == 0 && srcHistogram[HISTOGRAM_COLUMN::CDF][j] < 0)
			{
				// so make the cumulative distribution of that pixel become the MAX pixel
				srcHistogram[HISTOGRAM_COLUMN::CDF][j] = COLOR_RANGE - 1;
			}

			// if first matched pixel of target image found
			while (true)
			{
				// if the cumulative distribution of pixel in source image < the matched pixel in target image
				if (srcHistogram[HISTOGRAM_COLUMN::CDF][j] <= targetHistogram[HISTOGRAM_COLUMN::CDF][pixel])
				{
					// correspond the matched pixel in target image to pixel in source image
					srcHistogram[HISTOGRAM_COLUMN::CORRESPONDENCE_TABLE][j] = pixel;
					break; // jump out while loop to goto another pixel of source image
				}
				else // if the cumulative distribution of pixel in source image > the matched pixel in target image
				{
					// keep finding the next available pixel for correspondence
					pixel++;
				}
			}
		}

		for (int j = 0; j < dst.rows; j++)
		{
			for (int k = 0; k < dst.cols; k++)
			{
				// get the pixel value at the (j,k)th location in the destination image
				int pixelValue = (int)src.at<Vec3b>(j, k)[i];

				// assign (j,k)th location with the specific cdf of pixel value
				dst.at<Vec3b>(j, k)[i] = srcHistogram[HISTOGRAM_COLUMN::CORRESPONDENCE_TABLE][pixelValue];
			}
		}
	}
}

int main(void)
{
	// read source images	
	Mat src1 = imread("src1.jpg", cv::IMREAD_GRAYSCALE);
	Mat src2 = imread("src2.jpg", cv::IMREAD_GRAYSCALE);
	//--------------------------------------------------
	Mat src3 = imread("src3.jpg", cv::IMREAD_COLOR);
	Mat target = imread("target.jpg", cv::IMREAD_COLOR);

	//Mat ref1 = Mat::zeros(src1.rows, src1.cols, CV_8UC1);
	//Mat ref2 = Mat::zeros(src2.rows, src2.cols, CV_8UC1);
	Mat ref3 = imread("correct3.png", cv::IMREAD_COLOR);

	// clone destination images with souce images
	Mat dst1 = src1.clone();
	Mat dst2 = src2.clone();
	//--------------------------------------------
	Mat dst3 = src3.clone();

	// call functions
	histogramEqualization(src1, dst1);
	histogramEqualization(src2, dst2);
	//-------------------------------------
	histogramMatching(src3, target, dst3);

	//equalizeHist(src1, ref1);
	//equalizeHist(src2, ref2);

	//std::cout << isSameImg(dst1, ref1) << std::endl;
	//std::cout << isSameImg(dst2, ref2) << std::endl;
	//std::cout << isSameImg(dst3, ref3) << std::endl;

	// output destination images with certain name
	imwrite("result1.png", dst1);
	imwrite("result2.png", dst2);
	//--------------------------------------------
	imwrite("result3.png", dst3);

	// show source images in window
	imshow("src1", src1);
	imshow("src2", src2);
	//-----------------------------
	imshow("src3", src3);

	// show destination images in window
	imshow("result1", dst1);
	imshow("result2", dst2);
	//-----------------------------------
	imshow("result3", dst3);

	//imshow("correct1", ref1);
	//imshow("correct2", ref2);
	//imshow("correct3", ref3);

	waitKey();
}