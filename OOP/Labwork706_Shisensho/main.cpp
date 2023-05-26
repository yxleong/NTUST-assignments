/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 16, 2023
 * Update Date : April 19, 2023
 * Description : This C++ program implements tile-matching game which named Shisensho.
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Position.h"

#define BOARD_SIZE 6 + 2
 // adds an additional border around the 6x6 grid
 // to avoid having to perform boundary checks when traversing the board

enum class DIRECTION
{
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
};

/**
* Intent : To move position in the specified direction.
* Pre : The variable dir must have a value.
* Post : The function returns position with the correct movement based on the input parameter.
* \param dir
* \return
*/
Position movePosition(DIRECTION dir)
{
	switch (dir)
	{
	case DIRECTION::UP:
		return Position(0, -1);
	case DIRECTION::DOWN:
		return Position(0, 1);
	case DIRECTION::RIGHT:
		return Position(1, 0);
	case DIRECTION::LEFT:
		return Position(-1, 0);
	}
}

/**
* Intent : To clear the path that has been traversed on a 2D board.
* Pre : The variable board must have a valid 2D board.
* Post : The function resets the path that has been traversed.
* \param board
*/
void clearPath(std::vector<std::vector<int>>& board)
{
	for (auto& cell : board)
	{
		for (auto& i : cell)
		{
			if (i == -1) // board cell be marked
			{
				i = 0; // unmarked
			}
		}
	}
}

/**
* Intent : To check whether DFS finding a path from startPos to endPos with at most two turns.
* Pre : The variables board,startPos,endPos,startDir must have value.
* Post : The function returns the boolean value which indicate whether isInTwoTurns within at most two turns.
* \param board
* \param startPos
* \param endPos
* \param startDir
* \param turnTimes
* \return
*/
bool isInTwoTurns(std::vector<std::vector<int>>& board, Position startPos, const Position& endPos, DIRECTION startDir, int turnTimes)
{
	std::vector<DIRECTION> directions = { DIRECTION::UP, DIRECTION::DOWN, DIRECTION::RIGHT, DIRECTION::LEFT };

	for (const auto& dir : directions)
	{
		// move position from start position
		Position nowPos = startPos + movePosition(dir);

		// if dir != startDir, return true 1
		// else return false 0
		int turnTotal = (int)(dir != startDir) + turnTimes;

		if (nowPos == endPos) // reach
		{
			clearPath(board);

			// if turn times still not exceed 2, return true
			return (turnTotal <= 2) ? true : false;
		}

		// DFS searching
		if (nowPos.isInRange(BOARD_SIZE) && board[nowPos.yPos][nowPos.xPos] == 0 && turnTotal <= 2)
		{
			// mark traversed
			board[nowPos.yPos][nowPos.xPos] = -1;

			// check if reach or not
			if (isInTwoTurns(board, nowPos, endPos, dir, turnTotal))
			{
				clearPath(board);

				return true;
			}
		}
	}

	clearPath(board);

	return false;
}

/**
* Intent : To check if the match is bad.
* Pre : The variables board,pos1,pos2 must have a value.
* Post : The function returns a boolean value which indicate whether the match is bad.
* \param board
* \param pos1
* \param pos2
* \return
*/
bool isBadMatch(const std::vector<std::vector<int>>& board, const Position& pos1, const Position& pos2)
{
	// if out of range
	if (!pos1.isInRange(BOARD_SIZE - 1) || !pos2.isInRange(BOARD_SIZE - 1))
	{
		return true;
	}

	// if given positions are the same position
	if (pos1 == pos2)
	{
		return true;
	}

	// declare the symbol in board
	int sym1 = board[pos1.yPos][pos1.xPos];
	int sym2 = board[pos2.yPos][pos2.xPos];

	// if symbol not match
	if (sym1 != sym2)
	{
		return true;
	}

	// if symbol not 1¡¯, ¡®2¡¯, ¡®3¡¯, ¡­ , ¡®9¡¯
	// it is out of boundary or invalid symbol
	if (sym1 == 0 || sym2 == 0)
	{
		return true;
	}

	// if not condition above, not a bad pair
	return false;
}

int main(void)
{
	// declare variables which are needed
	std::vector<std::vector<int>> board(BOARD_SIZE, std::vector<int>(BOARD_SIZE, 0));
	Position pos1, pos2;

	// read the board
	for (int i = 1; i < BOARD_SIZE - 1; i++)
	{
		for (int j = 1; j < BOARD_SIZE - 1; j++)
		{
			std::cin >> board[i][j];
		}
	}

	// read a pair of coordinates
	while (std::cin >> pos1 >> pos2)
	{
		// check the input valid or not before matching
		if (isBadMatch(board, pos1, pos2))
		{
			std::cout << "bad pair" << std::endl;
			continue;
		}

		// declare variables which are needed
		std::vector<DIRECTION> directions = { DIRECTION::UP, DIRECTION::DOWN, DIRECTION::RIGHT, DIRECTION::LEFT };
		bool isMatch = false;

		for (const auto& dir : directions)
		{
			Position nowPos = pos1 + movePosition(dir);

			if (board[nowPos.yPos][nowPos.xPos] == 0) // if not traversed
			{
				board[nowPos.yPos][nowPos.xPos] = -1; // mark traversed

				// call function to check if the connection path still not exceed two turns
				if (isInTwoTurns(board, nowPos, pos2, dir, 0))
				{
					isMatch = true;
				}
			}
			else if (nowPos == pos2) // if traversed but now reach
			{
				isMatch = true;
			}
			else
			{
				continue;
			}
		}

		if (isMatch)
		{
			std::cout << "pair matched" << std::endl;

			// clear matched position
			board[pos1.yPos][pos1.xPos] = 0;
			board[pos2.yPos][pos2.xPos] = 0;
		}
		else
		{
			std::cout << "bad pair" << std::endl;
		}
	}

	return 0;
}