/*****************************************************************//**
 * File : NumberGame.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 29, 2023
 * Update Date : May 2, 2023
 * Description : This C++ program implements a designed number game.
 *********************************************************************/
#include "NumberGame.h"

 /**
 * Intent : To set the given integer.
 * Pre : The variable input must have a value.
 * Post : The function assgins the given integer as a string by stream.
 * \param input
 */
void NumberGame::SetInput(int input)
{
	std::stringstream ss;

	// insert int to stream
	ss << input;

	// get the content in stream as string
	integer = ss.str();
}

/**
* Intent : To split the integer into several digits.
* Pre : The variable integer must have a value.
* Post : The function saves the digits and their product results in set.
*/
void NumberGame::ProcessInput()
{
	// loop the integer digit by digit
	for (const char& c : integer)
	{
		// convert the char as int
		int digit = c - '0';

		// declared a temporary set to save the products generated by new current digit
		std::set<int> temp;

		// loop the elements in products
		for (const int& i : products)
		{
			// multiply all the generated products with current digit
			temp.insert(i * digit); // as new possible products
		}

		// insert the current digit after generate new possible products
		products.insert(digit);

		// insert the new generated possible products
		products.insert(temp.begin(), temp.end());
	}
}

/**
* Intent : To set the file name of the file where list is located.
* Pre : The variable fileGiven must have a value.
* Post : The function sets the file for reading the number list.
* \param fileGiven
*/
void NumberGame::SetFileName(std::string fileGiven)
{
	// assign the file name
	fileName = fileGiven;
}

/**
* Intent : To read list from the file.
* Pre : The variable fileName must have a value.
* Post : The function saves the valid number found in number list.
*/
void NumberGame::LoadNumberList()
{
	// declare variables which are needed
	std::ifstream inFile(fileName);
	int fileInput = 0;

	// check if the file is successfully open
	if (inFile.is_open())
	{
		// read file content
		while (inFile >> fileInput)
		{
			// if the read number is found in products set
			if (products.count(fileInput))
			{
				// insert the number in valid number vector
				legitimateNumber.push_back(fileInput);
			}
		}

		// close the file after reading all content
		inFile.close();
	}
}

/**
* Intent : To print all the valid numbers in number list ascendingly.
* Pre : The variable legitimateNumber must have a value.
* Post : The function prints all the valid numbers.
*/
void NumberGame::PrintAllValid()
{
	for (int number : legitimateNumber)
	{
		std::cout << number << std::endl;
	}
}

/**
* Intent : To reset all variables.
* Pre : The variables integer,fileName,legitimateNumber,products must be well defined.
* Post : The function resets all variables.
*/
void NumberGame::Reset()
{
	integer = "";
	fileName = "";
	legitimateNumber.clear();
	products.clear();
}
