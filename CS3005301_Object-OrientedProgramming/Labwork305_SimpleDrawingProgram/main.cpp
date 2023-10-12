/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 20, 2023
 * UPDATE Date : March 21, 2023
 * Description : This C++ program allow users to draw
					square, isosceles right triangle and lines
					on the console.
 *********************************************************************/
#define SIZE 100

#include <iostream>
#include <string>
#include <math.h>

 /**
 * Intent : To print the graph of a shape with a given symbol in certain col and row.
 * Pre : The variables col, row must have a positive value.
 * Post : The function prints the graph in array form.
 * \param graph
 * \param col
 * \param row
 */
void drawGraph(char graph[SIZE][SIZE], int col, int row)
{
	for (int i = 0; i < col; i++) // loop vertical until i = col
	{
		for (int j = 0; j < row; j++) // loop horizontal until j = row
		{
			// output the char in graph
			std::cout << graph[i][j];
		}

		// print a newline after a row
		std::cout << std::endl;
	}

	// print a newline after a graph
	std::cout << std::endl;
}

/**
* Intent : To get the scale of a square with a given point and width.
* Pre : The variables width, yPos, xPos must have a positive value and yPos+width > col, xPos+width > row.
* Post : The function returns the graph of a square.
* \param graph
* \param col
* \param row
* \param yPos
* \param xPos
* \param width
*/
void getSquare(char graph[SIZE][SIZE], int col, int row, int yPos, int xPos, int width)
{
	// check the range of graph with given row and col: 0 < point < row/col
	if (yPos < 0 || yPos + width > col || xPos < 0 || xPos + width > row || width <= 0)
	{
		// if out, print error message
		std::cout << "Out of range.\n" << std::endl;

		// jump out this fuction
		return;
	}
	else
	{
		for (int i = yPos; i < yPos + width; i++) // col loop until i = yPos + width
		{
			for (int j = xPos; j < xPos + width; j++) // row loop until j = xPos + width
			{
				// assign char to certain position in graph
				graph[i][j] = 'X';
			}
		}

		// call function to output the graph
		drawGraph(graph, col, row);
	}
}

/**
* Intent : To judge the given points can be a line or not.
* Pre : The variables yPos1, xPos1, yPos2, xPos2 must have a positive value and yPos+width > col, xPos+width > row.
* Post : The function returns the boolean of the given points can be line or not.
* \param graph
* \param col
* \param row
* \param yPos1
* \param xPos1
* \param yPos2
* \param xPos2
* \return
*/
bool getLine(char graph[SIZE][SIZE], int col, int row, int yPos1, int xPos1, int yPos2, int xPos2)
{
	// check the range of graph with given row and col: 0 < point < row/col
	if (yPos1 < 0 || yPos1 >= col || xPos1 < 0 || xPos1 >= row || yPos2 < 0 || yPos2 >= col || xPos2 < 0 || xPos2 >= row)
	{
		// return false if out of range
		return false;
	}
	else
	{
		// declare variables which are needed
		int deltaX = 0, deltaY = 0;

		// calculate the increasement of X
		if (xPos1 < xPos2)
		{
			deltaX = 1;
		}
		else if (xPos1 > xPos2)
		{
			deltaX = -1;
		}
		else // if same
		{
			deltaX = 0;
		}

		// calculate the increasement of Y
		if (yPos1 < yPos2)
		{
			deltaY = 1;
		}
		else if (yPos1 > yPos2)
		{
			deltaY = -1;
		}
		else // if same
		{
			deltaY = 0;
		}

		// loop start from point(x1,y1) to point(x2,y2) by delta of points
		// but not touching point(x2,y2)
		for (int xPos = xPos1, yPos = yPos1; xPos != xPos2 || yPos != yPos2; xPos += deltaX, yPos += deltaY)
		{
			// assign char to certain position in graph
			graph[yPos][xPos] = 'X';
		}

		// assign char to point2 in graph
		graph[yPos2][xPos2] = 'X';

		// return true to verify the line
		return true;
	}
}

/**
* Intent : To get the scale of a triangle with a given point, hypotenuse and facing.
* Pre : The variables hypotenuse, yPos, xPos must have a positive value.
* Post : The function returns the graph of a triangle.
* \param graph
* \param col
* \param row
* \param yPos
* \param xPos
* \param hypotenuse
* \param face
*/
void getTriangle(char graph[SIZE][SIZE], int col, int row, int yPos, int xPos, int hypotenuse, std::string face)
{
	// check the range of graph with given row and col: 0 < point < row/col
	if (yPos < 0 || yPos >= col || xPos < 0 || xPos >= row || hypotenuse <= 0)
	{
		// if out, print error message
		std::cout << "Out of range.\n" << std::endl;

		// jump out this fuction
		return;
	}

	// calculate the side length of isosceles right triangle by a given hypotenuse
	// L^2 + L^2 = H^2
	// 2(L^2) = H^2
	// L^2 = (H^2) / 2
	// L = H / sqrt(2)
	int length = hypotenuse / sqrt(2);

	// initialize the vertices to original given point first
	int yPos1 = yPos, yPos2 = yPos, xPos1 = xPos, xPos2 = xPos;

	// check if the hypotenuse facing to left or right
	switch (face[0])
	{
	case 'L': // if left, 
		// vertice move to left from original point
		xPos1 -= length;
		break;
	case 'R': // if right, 
		// vertice move to right from original point
		xPos1 += length;
		break;
	default:
		break;
	}

	// check if the hypotenuse facing to up or down
	switch (face[1])
	{
	case 'U': // if up, 
		// another vertice move up from original point
		yPos2 -= length;
		break;
	case 'D': // if down, 
		// another vertice move down from original point
		yPos2 += length;
		break;
	default:
		break;
	}

	// check the range of graph with given row and col: 0 < point < row/col
	if (yPos1 < 0 || yPos1 >= col || xPos1 < 0 || xPos1 >= row || yPos2 < 0 || yPos2 >= col || xPos2 < 0 || xPos2 >= row)
	{
		// if out, print error message
		std::cout << "Out of range.\n" << std::endl;

		// jump out this fuction
		return;
	}

	// call function to assign three lines with the three points above
	getLine(graph, col, row, yPos, xPos, yPos1, xPos1);
	getLine(graph, col, row, yPos, xPos, yPos2, xPos2);
	getLine(graph, col, row, yPos1, xPos1, yPos2, xPos2);

	// call function to output the graph
	drawGraph(graph, col, row);
}

int main(void)
{
	// declare variables which are needed
	int row = 0, col = 0;
	char graph[SIZE][SIZE];
	std::string shape = "";

	// read input as a int
	std::cin >> row >> col;

	// initialize the graph to *
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			graph[i][j] = '*';
		}
	}

	// infinite loop until cin meets EOF
	while (std::cin >> shape) // read input as a string
	{
		if (shape == "EXIT")
		{
			break; // end the while loop
		}
		else
		{
			// declare variables which are needed
			int xPos = 0, yPos = 0;
			int xPos1 = 0, yPos1 = 0;
			int width = 0, hypotenuse = 0;
			std::string face = "";

			// judge the first char of the input string
			switch (shape[0])
			{
			case'S':
				// read the information
				std::cin >> width >> xPos >> yPos;

				// call function to draw square
				getSquare(graph, col, row, yPos, xPos, width);

				// jump out the switch
				break;
			case'T':
				// read the information
				std::cin >> hypotenuse >> xPos >> yPos >> face;

				// call function to draw triangle
				getTriangle(graph, col, row, yPos, xPos, hypotenuse, face);

				// jump out the switch
				break;
			case'L':
				// read the information
				std::cin >> xPos >> yPos >> xPos1 >> yPos1;

				// check if line is valid to be draw by given points
				if (!getLine(graph, col, row, yPos, xPos, yPos1, xPos1))
				{
					// if not, print error message
					std::cout << "Out of range.\n" << std::endl;
				}
				else
				{
					// call function to draw triangle
					drawGraph(graph, col, row);
				}
				// jump out the switch
				break;
			default: // if not founding
				// direct jump out the switch
				break;
			}
		}
	}

	return 0;
}
