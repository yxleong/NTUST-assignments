/*****************************************************************//**
 * File : ComputeStandardDeviation.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 8, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program computes the average
 *					and standard deviation of input scores.
 *********************************************************************/

#define SIZE 100

#include <iostream>
#include <fstream>
#include <cmath>

 //void compute(std::ifstream& reading, std::ofstream& writing) {
 //	int n = 0;
 //
 //	while (reading >> n) {
 //		double s[N] = {};
 //		double sum = 0;
 //		double m = 0, stdv = 0;
 //
 //		for (int i = 0; i < n; i++) {
 //			reading >> s[i];
 //			sum += s[i];
 //		}
 //		m = (double)sum / n; // calculate average
 //
 //		// standard deviation = sqrt( (1/n) * pow(s[i] - m), 2) )
 //		for (int i = 0; i < n; i++) {
 //			stdv += pow(s[i] - m, 2);
 //		}
 //		stdv /= n;
 //		stdv = sqrt(stdv);
 //
 //		writing << "Average:" << m << "\tStandard deviation:" << stdv << std::endl;
 //	}	
 //}

/**
* Intent : To calculate the volume of a sphere with a given radius.
* Pre : The variable radius must have a value and radius > 0.
* Post : The function returns the volume of a sphere.
* \param arrSize
* \param arr
*/
void computeAverageAndStandardDeviation(int arrSize, double arr[])
{
	// declare variables which are needed
	double sum = 0;
	double avg = 0, stdv = 0;

	// calculate sum of scores
	for (int i = 0; i < arrSize; i++) // loop until i = arrSize
	{
		sum += arr[i];
	}

	// calculate average of scores
	avg = sum / arrSize;

	// calculate standard deviation of scores
	// stdv = sqrt( (1/n) * pow(s[i] - m), 2) )
	for (int i = 0; i < arrSize; i++) // loop until i = arrSize
	{
		stdv += pow(arr[i] - avg, 2);
	}
	stdv /= arrSize;
	stdv = sqrt(stdv);

	// output the average and standard deviation, separated by a tab
	std::cout << "Average:" << avg << "\tStandard deviation:" << stdv << std::endl;
}

int main(void)
{
	/*std::ifstream read_file("input.txt");
	std::ofstream write_file("output.txt");

	if (read_file.is_open() && write_file.is_open()) {
		compute(read_file, write_file);
		read_file.close();
		write_file.close();
	}*/

	// reusable variables, place these variables outside of the loop
	int numOfScores = 0;
	double scores[SIZE] = { 0 };

	// infinite loop until cin meets EOF
	while (std::cin >> numOfScores) // read input as a int
	{
		for (int i = 0; i < numOfScores; i++) // loop until i = numOfScores
		{
			std::cin >> scores[i]; // read input as a int array element
		}

		// call function
		computeAverageAndStandardDeviation(numOfScores, scores);
	}

	return 0;
}