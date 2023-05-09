/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	B11015042
 * Create Date: March 14, 2023
 * Update Date: March 14, 2023
 * Description: This C++ program implements wall drawing function.
 *********************************************************************/

 /************************************************************************
 File:   Source.cpp

 Author:
		 鍾賢廣，ea5878158@gmail.com
 Modifier:
		 賴祐吉，cheeryuchi@gmail.com
		 顧唯耀，guweiyao867@gmail.com
		 陳俊宇，JYCReports@gmail.com
		 邱嘉興，tbcey74123@gmail.com
 Comment:
		 Draw and print out the canvas.

 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

void drawBoard(); //Function to draw board
void makeBoard(); //Function to make board
void modifyBoard();	//Function to modify board

const int DUNGEN_ROW = 10, DUNGEN_COL = 20;
char dungenMap[DUNGEN_ROW][DUNGEN_COL];

int main(int argc, char** argv)
{
	makeBoard();
	drawBoard();
	modifyBoard();
	drawBoard();
}

void drawBoard()
//==================================================================
{
	// Draw out the whole board
	/************************************************************************/
	/*Please implement your code here*/

	// create map with size 10 columns and 20 rows
	for (int y = 0; y < DUNGEN_ROW; y++) {
		for (int x = 0; x < DUNGEN_COL; x++) {
			std::cout << dungenMap[y][x];

			// for drawing correct format
			if (x == DUNGEN_COL - 1)
				std::cout << std::endl;
			else continue;
		}
	}

	/************************************************************************/
}

void makeBoard()
//==================================================================
{
	// Enter symbol for wall and blank then create array
	/************************************************************************/
	/*Please implement your code here*/

	// Use char array to store map information
	char wallSymbol = 0, blank_symbol = 0;
	// Enter two symbols for wall and space
	std::cout << "Enter symbol for wall:";
	std::cin >> wallSymbol;
	std::cout << "Enter symbol for blank:";
	std::cin >> blank_symbol;

	for (int y = 0; y < DUNGEN_ROW; y++) {
		for (int x = 0; x < DUNGEN_COL; x++) {
			if (y == 0 || x == 0 || y == DUNGEN_ROW - 1 || x == DUNGEN_COL - 1) {
				// draw the dungeon wall
				dungenMap[y][x] = wallSymbol;
			}
			else {
				dungenMap[y][x] = blank_symbol;
			}
		}
	}
	/************************************************************************/
}

void modifyBoard()
//==================================================================
{
	// Function for modifying board given position and char to change
	/************************************************************************/
	/*Please implement your code here*/

	char posSymbol = 0;
	int posX = 0, posY = 0;

	std::cout << "Enter symbol for modifying position:";
	std::cin >> posSymbol;
	std::cout << "Enter X of modifying position:";
	std::cin >> posX;
	std::cout << "Enter Y of modifying position:";
	std::cin >> posY;

	// Enter the correct position and successfully place the specified symbol 
	if (posX > 0 && posX < DUNGEN_COL - 1 && posY > 0 && posY < DUNGEN_ROW - 1)
		// place the specified symbol anywhere in the specified dungeon by inputting it
		dungenMap[posY][posX] = posSymbol;
	else
		// Output an error message if the position is out of range
		std::cout << "Invalid input" << std::endl;

	/************************************************************************/
}
