/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 2, 2023
 * UPDATE Date : April 3, 2023
 * Description : This C++ program implements a sudoku checker.
 *********************************************************************/

#include <iostream>
#include <string>

#define SIZE 9

 /**
 * Intent : To check if the value in row and column of a sudoku given is from 1 to 9.
 * Pre : The variable sudoku must have values.
 * Post : The function returns a boolean value indicating whether the row and column of a sudoku given is valid.
 * \param sudoku
 * \return
 */
bool isValidRowCol(int sudoku[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		// declare variables which are needed
		// will be a array save isSeen for 0 to 9
		bool isNumInRowSeen[SIZE] = { false };
		bool isNumInColSeen[SIZE] = { false };

		for (int j = 0; j < SIZE; j++)
		{
			// num in suduku will from 1 to 9
			// instead of start from 0
			// so when indicate the index, -1
			int numInRow = sudoku[i][j] - 1;
			// check if the num in the certain boolean row array is appeared before
			if (isNumInRowSeen[numInRow])
			{
				// if already checked before
				return false;
			}
			// if not, mark that checked
			isNumInRowSeen[numInRow] = true;

			// num in suduku will from 1 to 9
			// instead of start from 0
			// so when indicate the index, -1
			int numInCol = sudoku[j][i] - 1;
			// check if the num in the certain boolean row array is appeared before
			if (isNumInColSeen[numInCol])
			{
				// if already checked before
				return false;
			}
			// if not, mark that checked
			isNumInColSeen[numInCol] = true;
		}
	}

	// if the value in row and column of a sudoku given is from 1 to 9
	// and no any duplicate & missing
	return true;
}

/**
 * Intent : To check if the value in square of a sudoku given is from 1 to 9.
 * Pre : The variable sudoku must have values.
 * Post : The function returns a boolean value indicating whether the square of a sudoku given is valid.
 * \param sudoku
* \return
*/
bool isValidSquare(int sudoku[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i += 3)
	{
		for (int j = 0; j < SIZE; j += 3)
		{
			// declare a array save isSeen for 0 to 9
			bool isNumInSquareSeen[SIZE] = { false };

			// create a loop for 3x3 square in 9x9
			for (int k = i; k < i + 3; k++)
			{
				for (int h = j; h < j + 3; h++)
				{
					// num in suduku will from 1 to 9
					// instead of start from 0
					// so when indicate the index, -1
					int numInSquare = sudoku[k][h] - 1;

					// check if the num in the certain boolean row array is appeared before
					if (isNumInSquareSeen[numInSquare])
					{
						// if already checked before
						return false;
					}

					// if not, mark that checked
					isNumInSquareSeen[numInSquare] = true;
				}
			}
		}
	}

	// if the value in square of a sudoku given is from 1 to 9
	// and no any duplicate & missing
	return true;
}

int main(void)
{
	// reusable variables, place them outside of the loop
	int sudoku[SIZE][SIZE] = {};
	char line[100] = {};

	// infinite loop until cin meets EOF
	while (std::cin.getline(line, 100)) // get first line: read by line with 100 max character
	{
		for (int i = 0; i < SIZE; i++)
		{
			// declare variables which are needed
			char* nextToken = nullptr;
			char* token = strtok_s(line, ",", &nextToken); // set ',' as token to avoid to get
			int j = 0;

			// when reach ',' as a next index in the line inputted
			while (token != nullptr)
			{
				// assign the value of token record
				sudoku[i][j] = std::stoi(token);

				// increase column index
				j++;

				// redefine the token to next next index
				token = strtok_s(nullptr, ",", &nextToken);
			}

			// read next line until reach 9 lines
			std::cin.getline(line, 100);
		}

		if (isValidRowCol(sudoku) && isValidSquare(sudoku))
		{
			// if sudoku is valid
			std::cout << "True" << std::endl;
		}
		else // if sudoku is not valid
		{
			std::cout << "False" << std::endl;
		}
	}

	return 0;
}
