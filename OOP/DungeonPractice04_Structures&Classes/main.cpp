/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *  Tien Qingian
 * Create Date: March 25, 2023
 * Update Date: May 9, 2023
 * Description: This C++ program implements class Creature and Hero controls.
 *********************************************************************/

 /************************************************************************
 File:   Source.cpp

 Author:
		 鍾賢廣，ea5878158@gmail.com
 Modifier:
		 賴祐吉，cheeryuchi@gmail.com
		 陳俊宇，JYCReports@gmail.com
		 邱嘉興，tbcey74123@gmail.com
 Comment:
		 基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，
		 ESC是離開畫面。同時更新圖版上的資訊。

 ************************************************************************/

#include <iostream>
#include <math.h>		// pow() and sqrt()
#include <ctime>		// for time loop function
#include <conio.h>		// _getch() <= to read input without enter "ENTER" key
#include <algorithm>	// for max and min function

 //************************************************************
 // The location in the board
 //************************************************************
struct Position {
	int x; // X, y Coordinate
	int y;
};

// Check whether the location is a valid one i.e. not a wall
bool isPositionValid(Position& loc);

//************************************************************
// Hero Class, only has requirement part for example
//************************************************************
class Hero {
private:
	Position	sPos;			// Hero location
	char sIcon = 'H';	// Hero icon

public:
	// Default constructor
	Hero() {
		this->sPos.x = 0;
		this->sPos.y = 0;
		this->sIcon = 'H';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// Incrementally move the elements 
	void move(int deltaX, int deltaY) {
		// Implement Hero controls
		/*Please implement your code here*/

		// compute Hero destination position according to the given movement
		Position nextPos;
		nextPos.x = this->sPos.x + deltaX;
		nextPos.y = this->sPos.y + deltaY;

		// check if Hero destination position is valid
		if (isPositionValid(nextPos))
		{
			// if yes, move the Hero to destination
			this->sPos.x += deltaX;
			this->sPos.y += deltaY;
		}
		else
		{
			std::cout << "Invalid location" << std::endl;
		}

		/************************************************************************/
	}
};

// clip algroithm
float clip(float n, float minimun, float maximum);

class Creature {

	// Implement Creature Class
	/*Please implement your code here*/
private:
	Position	sPos;
	char sIcon = '@';

public:
	// Default constructor
	Creature() {

		// create position for Creature
		this->sPos.x = 0;
		this->sPos.y = 0;

		// assign icon for Creature
		this->sIcon = '@';
	};

	// Set position
	void setPos(Position pos) { this->sPos = pos; }
	void setPos(int x, int y) {
		this->sPos.x = x;
		this->sPos.y = y;
	}

	// Set icon
	void setIcon(char& icon) { this->sIcon = icon; }

	// Get position
	Position getPos(void) { return this->sPos; }

	// Get Icon
	char getIcon(void) { return this->sIcon; }

	// check if the Hero is within 2 vertical, horizontal, and diagonal lines of the Creature
	bool canSee(Position hPos, int& dirX, int& dirY)
	{
		// calculate the directional distance from Hero to Creature
		dirX = clip((hPos.x - this->sPos.x), -1, 1);
		dirY = clip((hPos.y - this->sPos.y), -1, 1);

		int count = 0; // keep track of the number of iterations in the loop

		do // when Creature and Hero distance larger than 2 in that direction
		{
			// if Creature at a given multiple of the direction vector equals Hero
			if (this->sPos.x + dirX * count == hPos.x &&
				this->sPos.y + dirY * count == hPos.y)
			{
				return true; // spot the target position
			}
			count++; // if not found, check other direction
		} while (count < 4); // until 4 direction checked

		return false; // if 4 direction not found, then Creature can't see Hero
	}

	// Creature move according to whether it saw the Hero or not
	void update(Position hPos)
	{
		Position cPos;
		cPos.x = this->sPos.x;
		cPos.y = this->sPos.y;

		// check if the hero is in line of sight
		int dirX = 0, dirY = 0;
		if (canSee(hPos, dirX, dirY))
		{
			// isNegX = 0
			// if (hPos.x - cPos.x) < 0
			// hPos at left of cPos
			bool isNegX = (hPos.x - cPos.x) < 0;

			// isNegY = 0
			// if (hPos.y - cPos.y) < 0
			// hPos at bottom of cPos
			bool isNegY = (hPos.y - cPos.y) < 0;

			// move toward the Hero
			if (isNegX) // if cPos at right
			{
				cPos.x--; // move left to reach hPos
			}
			else // if cPos at left
			{
				cPos.x++; // move right to reach hPos
			}

			if (isNegY) // if cPos at top
			{
				cPos.y--; // move down to reach hPos
			}
			else // if cPos at bottom
			{
				cPos.y++; // move up to reach hPos
			}
		}
		else // if Hero is out of sight
		{
			int direction = rand() % 4;

			// randomly move up, down, left, and right
			switch (direction)
			{
			case 0:
				cPos.y--;
				break;
			case 1:
				cPos.y++;
				break;
			case 2:
				cPos.x--;
				break;
			case 3:
				cPos.x++;
				break;
			default:
				break;
			}
		}

		// check if Creature destination position is valid
		if (isPositionValid(cPos))
		{
			// if yes, move the Creature to destination
			this->sPos.x = cPos.x;
			this->sPos.y = cPos.y;
		}
	}
	/************************************************************************/
};

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char gBoard[GHEIGHT][GWIDTH];

// 定義六種輸入指令與對應陣列index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	INVALID,
};

Hero gHero;
Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 判斷位置是否為空
bool isPositionValid(Position& loc);
// 初始化版面
void setupBoard();
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];

	// Setup a clear dungeon
	setupBoard();

	// Set the position of Hero
	gHero.setPos(2, 2);

	gCreature.setPos(5, 6);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

	// Get the press key
	keyUpdate(gKeyState);

	// Run the game loop
	while (!gKeyState[ValidInput::EESC]) {
		// Compute the time lap
		double timeFrame = (double)(endT - startT) / CLOCKS_PER_SEC;

		// Execute the game loop
		if (timeFrame >= gTimeLog) {
			update(gKeyState);
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();
	}

	system("pause");
	return 0;
}

//******************************************************************
//
// * 偵測輸入狀態
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
	case 'w':
		key[ValidInput::EW] = true;
		break;
	case 's':
		key[ValidInput::ES] = true;
		break;
	case 'a':
		key[ValidInput::EA] = true;
		break;
	case 'd':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	default:
		break;
	}
}

//******************************************************************
//
// * 判斷位置是否為空
//==================================================================
bool isPositionValid(Position& pos)
//==================================================================
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	if (pos.x == gHero.getPos().x && pos.y == gHero.getPos().y)
		return false;

	if (pos.x == gCreature.getPos().x && pos.y == gCreature.getPos().y)
		return false;

	return true;
}

//******************************************************************
//
// * clip algroithm
//==================================================================
float clip(float n, float minimun, float maximum)
//==================================================================
{
	return std::max(minimun, std::min(n, maximum));
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard()
//==================================================================
{
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			if (i == 0 || i == GHEIGHT - 1) {
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == GWIDTH - 1) {
				gBoard[i][j] = GWALL;
			}
			else {
				gBoard[i][j] = GNOTHING;
			}
		}
	}
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	char drawBoard[GHEIGHT][GWIDTH];

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

//******************************************************************
//
// * Output information
//==================================================================
void drawInfo(void)
//==================================================================
{
	// Print Outputs
	/*Please implement your code here*/

	int dirX = 0, dirY = 0;
	// check if the position of Hero is within 2 vertical, horizontal, and diagonal lines of the Creature
	if (gCreature.canSee(gHero.getPos(), dirX, dirY))
	{
		// if yes, the output message indicates that the Creature has seen the Hero
		std::cout << "Creature found Hero!" << std::endl;
	}

	/************************************************************************/

	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Press ESC key to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// 清除版面
	system("CLS");

	// 是否有input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		gHero.move(0, -1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		gHero.move(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		gHero.move(-1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		gHero.move(1, 0);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	//Calculate and Initiate Move
	gCreature.update(gHero.getPos());
	draw();
	drawInfo();
}
