/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 24, 2023
 * Update Date : April 24, 2023
 * Description : This C++ program calculates matrix multiplication.
 *********************************************************************/
#include <iostream>
#include <vector>

int main(void)
{
	// declare variables which are needed
	int rowA = 0, colA = 0, rowB = 0, colB = 0;

	// read the size of A and B as int in row major
	std::cin >> rowA >> colA >> rowB >> colB;

	// number of columns of the A matrix must equal to the number of rows of the B matrix
	if (colA != rowB)
	{
		// if not, A and B can not be multiplied
		std::cout << "Matrix multiplication failed." << std::endl;
	}
	else
	{
		// declare the matrix in specific size inputted
		std::vector<std::vector<int>> matrixA(rowA, std::vector<int>(colA));
		std::vector<std::vector<int>> matrixB(rowB, std::vector<int>(colB));
		std::vector<std::vector<int>> matrixM(rowA, std::vector<int>(colB));

		// read the numbers of matrix A
		for (int i = 0; i < rowA; i++)
		{
			for (int j = 0; j < colA; j++)
			{
				std::cin >> matrixA[i][j];
			}
		}

		// read the numbers of matrix B
		for (int i = 0; i < rowB; i++)
		{
			for (int j = 0; j < colB; j++)
			{
				std::cin >> matrixB[i][j];
			}
		}

		// calculate matrix multiplication based on multiplication rule of the matrix
		for (int i = 0; i < rowA; i++)
		{
			for (int j = 0; j < colA; j++) // colA == rowB
			{
				for (int k = 0; k < colB; k++)
				{
					matrixM[i][k] += matrixA[i][j] * matrixB[j][k];
				}
			}
		}

		// output the matrix obtained by multiplying A and B
		for (int i = 0; i < rowA; i++)
		{
			for (int j = 0; j < colB; j++)
			{
				std::cout << matrixM[i][j];

				// to avoid the presentation error
				if (j != colB - 1)
				{
					// each line will not have space at last
					std::cout << " ";
				}
			}

			// enter after each line end
			std::cout << std::endl;
		}
	}

	return 0;
}
