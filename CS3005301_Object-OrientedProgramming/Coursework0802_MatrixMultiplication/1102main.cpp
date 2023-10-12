/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 19, 2023
 * Description: This C++ program is to calculate matrix multiplication.
 *********************************************************************/

#include <iostream>
#include <vector>

int main(void)
{
	// declare variables which are needed
	int rowA = 0, colA = 0;
	int rowB = 0, colB = 0;

	// read the size of matrix A and matrix B in row major
	std::cin >> rowA >> colA >> rowB >> colB;

	// check if the number of columns of the matrix A equal to the number of rows of the matrix B
	if (colA != rowB) {
		// if not, then matrix A and matrix B cannot be multiplied
		std::cout << "Matrix multiplication failed." << std::endl;
	}
	else { // if number of columns of the matrix A equal to the number of rows of the matrix B

		// declare variables which are needed
		std::vector<std::vector<int>> matrixA(rowA, std::vector<int>(colA));
		std::vector<std::vector<int>> matrixB(rowB, std::vector<int>(colB));
		std::vector<std::vector<int>> matrixAB(rowA, std::vector<int>(colB));

		// read numbers of matrix A
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colA; j++) {
				std::cin >> matrixA[i][j];
			}
		}

		// read numbers of matrix B
		for (int i = 0; i < rowB; i++) {
			for (int j = 0; j < colB; j++) {
				std::cin >> matrixB[i][j];
			}
		}

		// multiplying matrix A and matrix B
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colA; j++) {
				for (int k = 0; k < colB; k++) {
					matrixAB[i][k] += matrixA[i][j] * matrixB[j][k];
				}
			}
		}

		// output the result matrix AB
		for (int i = 0; i < rowA; i++) {
			for (int j = 0; j < colB; j++) {
				std::cout << matrixAB[i][j];

				// to get the valid format
				if (j != colB - 1) {
					// if not the column of row
					std::cout << " ";
				}
				else { // enter to next row
					std::cout << std::endl;
				}
			}
		}
	}

	return 0;
}
