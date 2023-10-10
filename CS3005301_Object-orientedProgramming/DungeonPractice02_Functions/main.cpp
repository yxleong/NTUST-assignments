/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: March 7, 2023
 * Update Date: March 7, 2023
 * Description: This C++ program implements character movement.
 *********************************************************************/

 /************************************************************************
 File:   Source.cpp

 Author:
		 ���ſ��Atbcey74123@gmail.com
 Comment:
		 Output character position after W,A,S,D input.
		 Output invalid if destination out of boundary.
		 ESC to stop process.

 ************************************************************************/
#include <iostream>	// For print out information
#include <conio.h>	// For getch() function

bool tryMove(int deltaX, int deltaY);
bool checkValidDst(int x, int y);

int posX = 0, posY = 0; // global param to keep the character position
const int DUNGEN_SIZE = 5; // For each dimension, -DUNGEN_SIZE < pos < DUNGEN_SIZE

int main() {
	// Obtain and update the input using a loop
	while (true) {
		char input = _getch();
		// Continue reading taker input in a loop

		/************************************************************************/
		/*Please implement your code here*/

		// Move character position based on user input
		switch (input) {
		case 'w':
		case 'W':
			if (!tryMove(0, 1)) {
				std::cerr << "Failed to move" << std::endl;
			}
			break;
		case 's':
		case 'S':
			if (!tryMove(0, -1)) {
				std::cerr << "Failed to move" << std::endl;
			}
			break;
		case 'a':
		case 'A':
			if (!tryMove(-1, 0)) {
				std::cerr << "Failed to move" << std::endl;
			}
			break;
		case 'd':
		case 'D':
			if (!tryMove(1, 0)) {
				std::cerr << "Failed to move" << std::endl;
			}
			break;
		default:
			break;
		}

		// correctly respond to user input
		if (checkValidDst(posX, posY)) {
			std::cout << "Character position : (" << posX << ", " << posY << ")" << std::endl;
		}

		/************************************************************************/
	}
}

//******************************************************************
//
// * Move character with input delta, return true if successful otherwise false
//==================================================================
bool tryMove(int deltaX, int deltaY) {
	/************************************************************************/
	/*Please implement your code here*/

	// judge whether the character can move to the given (x, y)
	if (posX + deltaX <= -DUNGEN_SIZE || posX + deltaX >= DUNGEN_SIZE || posY + deltaY <= -DUNGEN_SIZE || posY + deltaY >= DUNGEN_SIZE) {
		return false;
	}
	posX += deltaX;
	posY += deltaY;
	return true;

	/************************************************************************/
}
//******************************************************************
//
// * Check if given position is a valid destination, return true if valid otherwise false
//==================================================================
bool checkValidDst(int x, int y) {
	/************************************************************************/
	/*Please implement your code here*/

	if (x <= -DUNGEN_SIZE || x >= DUNGEN_SIZE || y <= -DUNGEN_SIZE || y >= DUNGEN_SIZE) {
		return false;
	}
	return true;

	/************************************************************************/
}
