/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 10, 2023
 * Update Date: May 10, 2023
 * Description: This C++ program implements word game by a 4x4 grid.
 *********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define GRID_SIZE 4

struct Point
{
	int x;
	int y;

	// constructor
	Point(int pointX, int pointY) : x(pointX), y(pointY) {}
};

/*****************************************************************//**
 * Intent: To check if the dfs algorithm is valid for the words in grid generated.
 * Pre: The variables grid,word,nowPoint,index must have a value.
 * Post: The function returns the boolean value which indicates if dfs algorithm is valid.
 * \param grid
 * \param word
 * \param nowPoint
 * \param index
 * \return
 *********************************************************************/
bool canDepthFirstSearch(std::vector<std::string> grid, std::string word, Point nowPoint, int index)
{
	// if matching already reach word size
	if (index == word.size())
	{
		int count = 0;

		// check how many 0 is marked as searched on each letter
		for (const std::string& word : grid)
		{
			count += std::count(word.begin(), word.end(), '0');
		}

		// if number of marked 0 is totally equal to word size
		if (count == word.size())
		{
			// the word can be search by dfs algorithm
			return true;
		}
		else // if number of marked 0 is different with word size
		{
			// the word unable to be search by dfs algorithm
			return false;
		}
	}
	else // if matching still not reach word size
	{
		// continue go deep to search next
		for (int x = -1; x <= 1; x++) // -1 0 1
		{
			for (int y = -1; y <= 1; y++) // for adjacent point
			{
				Point nextPoint(nowPoint.x + x, nowPoint.y + y);

				// if the next point is out of grid range
				if (nextPoint.x < 0 || nextPoint.x >= GRID_SIZE || nextPoint.y < 0 || nextPoint.y >= GRID_SIZE)
				{
					continue; // direct go to next coordinate
				}
				else // if next point is still in grid
				{
					char nextLetter = grid[nextPoint.x][nextPoint.y];

					// if found the next letter in word
					if (nextLetter == word[index])
					{
						// mark the point as 0
						grid[nextPoint.x][nextPoint.y] = '0';

						// search for the next point
						if (canDepthFirstSearch(grid, word, nextPoint, index + 1))
						{
							// if reach word size & number of marked 0 = word size
							return true;
						}
						else // if dfs is not valid
						{
							// unmarked the point, continue for-loop to search next
							grid[nextPoint.x][nextPoint.y] = nextLetter;
						}
					}
				}
			}
		}
	}

	// if loop all still not found
	return false;
}

/*****************************************************************//**
 * Intent: To check if word is valid to be find by dfs in grid.
 * Pre: The variables grid,word must have a value.
 * Post: The function returns the boolean value which indicates if word can be formed from the grid.
 * \param grid
 * \param word
 * \return
 *********************************************************************/
bool isValid(std::vector<std::string> grid, std::string word)
{
	std::vector<Point> startPoints = {};

	// get all the possible starting point in grid
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			if (grid[i][j] == word[0])
			{
				startPoints.push_back(Point(i, j));
			}
		}
	}

	// using dfs to test the starting point one by one
	for (const Point& point : startPoints)
	{
		if (canDepthFirstSearch(grid, word, point, 0))
		{
			// if dfs valid then then word can be formed from the grid
			return true;
		}
	}

	return false;
}

int main(void)
{
	// declare variables which are needed
	std::string letters = "";
	std::vector<std::string> grid = { "" };

	// resize grid to contain 4 strings given
	grid.resize(GRID_SIZE);

	while (std::cin >> letters) // read 4 letters in a string
	{
		grid[0] = letters; // assign the first row by letters given

		// read the leaving three rows of letters as string
		for (int i = 1; i < GRID_SIZE; i++)
		{
			std::cin >> letters;
			grid[i] = letters;
		}

		// open text file
		std::ifstream inFile("words.txt");

		if (inFile.is_open()) // check if file is exist
		{
			std::string word = "";

			while (inFile >> word) // read the word in file
			{
				// check if the word is valid in the grid generated
				if (isValid(grid, word))
				{
					// if yes, output the certain word
					std::cout << word << std::endl;
				}
			}
			std::cout << std::endl;

			// close the file after reading
			inFile.close();
		}
	}

	return 0;
}