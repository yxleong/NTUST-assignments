/*****************************************************************//**
 * File : textBasedHistogram.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 14, 2023
 * UPDATE Date : March 18, 2023
 * Description : This C++ program generates a text-based histogram
					for a quiz of students as a file.

 *********************************************************************/

#define NUMS 6

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(void)
{
	// declare and open files
	std::ifstream inputFile("grade.txt");
	std::ofstream outputFile("grades.Output");

	// check if the files are opened
	if (inputFile.is_open() && outputFile.is_open())
	{
		// reusable variable, place this variable outside of the loop
		std::string line = "";

		// read the data in file line by line
		while (std::getline(inputFile, line))
		{
			// declare variable which is needed
			std::istringstream iss(line); // create a string stream from line
			int input = 0, counter[NUMS] = { 0 };

			while (iss >> input) // read input as a int
			{
				// increase the value which index same with the input
				counter[input]++;
			}

			for (int i = 0; i < NUMS; i++) // loop until i = NUMS
			{
				// output the text-based histogram with the format in the "Output" section as file
				outputFile << counter[i] << " grade(s) of " << i << std::endl;
				// print the text-based histogram with the format in the "Output" section
				std::cout << counter[i] << " grade(s) of " << i << std::endl;
			}
		}

		// close the files
		inputFile.close();
		outputFile.close();
	}
	else // if files are not successfully opened
	{
		std::cout << "Invalid files" << std::endl;
	}

	return 0;
}