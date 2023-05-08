/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: April 18, 2023
 * Update Date: April 18, 2023
 * Description: This C++ program creates canvas of a user-defined size, displays board using a 2D vector, and generates random positions for objects.
 *********************************************************************/

 /************************************************************************
 File:   source.cpp

 Author:
		 鍾賢廣，ea5878158@gmail.com
 Modifier:
		 賴祐吉，cheeryuchi@gmail.com
		 黃欣云，windyhuang6@gmail.com
		 陳俊宇，JYCReports@gmail.com
		 邱嘉興，tbcey74123@gmail.com
		 B11015016, B11015042
 Comment:
		 基本輸入方向移動功能，w s a d 移動腳色上下左右，空白改變腳色站立之地板字元，到T上可以增加經驗
		 ESC是離開畫面。同時更新圖版上的資訊。

 ************************************************************************/

#include "main.h"
#include "Hero.h"
#include <vector>
Hero	 gHero(2, 2);



class Creature {//creature class 
private:
	Position	sPos;			// Creature position
	char sIcon = 'C';			// Creature icon
	int power;
public:
	// Default constructor
	Creature(void) {
		this->sPos.x = 1;
		this->sPos.y = 1;
		this->sIcon = 'C';
		this->power = 5;
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

public:
	void update(Hero& hero) {
		Position hPos = hero.getPos();

		Position dir;
		if (canSee(this->sPos, hPos, dir)) {
			std::cout << "Creature has find the Hero in the ( " << dir.x << ", " << dir.y << " ) direction\n";
			this->sIcon = '!';
		}
		else {
			std::cout << "Creature didn't find the Hero\n";
			this->sIcon = 'C';
		}

		if (hPos.x == sPos.x && hPos.y == sPos.y) {
			hero.damage(power);
		}
	}
};

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

int GWIDTH = -1;
int GHEIGHT = -1;
const int MIN_SIZE = 4;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// 用來儲存版面資料
char** gBoard;

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


Creature gCreature;

// function declare
// 偵測輸入狀態
void keyUpdate(bool key[]);
// 初始化版面
void setupBoard(int rowN, int colN);
// 輸出版面
void draw(void);
// 輸出說明資訊
void drawInfo(void);

// 程式主驅動函式
void update(bool key[]);

// Create vector of trigger pointer for further managenent and manipulation
/*Please implement your code here*/

// gTrigger is created as a vector of trigger pointer
std::vector<Trigger*> gTrigger;

/************************************************************************/

int main(int argc, char** argv)
{
	srand(time(NULL));

	// 用來管理鍵盤輸入狀態的陣列
	bool gKeyState[6];
	for (int i = 0; i < 6; i++) {
		gKeyState[i] = false;
	}

	while (true) {
		std::cout << "Enter Width: ";
		std::cin >> GWIDTH;
		std::cout << "Enter Height: ";
		std::cin >> GHEIGHT;
		system("CLS");
		if (GHEIGHT < MIN_SIZE || GWIDTH < MIN_SIZE) {
			std::cout << "Illegal, both has to be larger than " << MIN_SIZE << std::endl;

			// to re-request user input
			std::cout << "Please enter again." << std::endl;

		}
		else {
			break;
		}
	}

	// Setup a clear dungeon
	setupBoard(GHEIGHT, GWIDTH);

	// Draw the bord and information
	draw();
	drawInfo();

	// Variable for game loop
	clock_t startT, endT;
	startT = clock();
	endT = clock();

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
// * 利用 call-by-referce 將計算得到的方向回傳
//==================================================================
bool canSee(Position cPos, Position hPos, Position& dir)
//==================================================================
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - cPos.x), -1.f, 1.f); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - cPos.y), -1.f, 1.f);
	int count = 0;
	do {
		// spot the target position
		if (cPos.x + dir.x * count == hPos.x &&
			cPos.y + dir.y * count == hPos.y) {
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	return false;
}

//******************************************************************
//
// * Setup the board
//==================================================================
void setupBoard(int rowN, int colN)
//==================================================================
{
	// Allocate & init game board using 2d dynamic array
	/*Please implement your code here*/

	// using rowN,colN given to allocate 2d dynamic array
	gBoard = new char* [rowN];
	for (int i = 0; i < rowN; i++) {
		gBoard[i] = new char[colN];
	}

	// initialize the 2d dynamic array with GWALL,GNOTHING
	for (int i = 0; i < rowN; i++) {
		for (int j = 0; j < colN; j++) {
			if (i == 0 || i == rowN - 1) {
				gBoard[i][j] = GWALL;
			}
			else if (j == 0 || j == colN - 1) {
				gBoard[i][j] = GWALL;
			}
			else {
				gBoard[i][j] = GNOTHING;
			}
		}
	}

	/************************************************************************/

	// Setup for (random) position of all elements and implementation of game board using 2d dynamic array
	// Elements has to be randomly generated within canvas
	// Two triggers should also be initialized and pushed to the container here.
	/*Please implement your code here*/

	// setup for Hero position
	Position hPos;
	hPos.y = 1 + rand() % (rowN - 2); // -2 to deduct the first,last index
	hPos.x = 1 + rand() % (colN - 2); // 1+ to start from second index
	gHero.setPos(hPos.y, hPos.x);

	// setup for Creature position
	Position cPos;
	do { // if WHILE happen then will do again and again
		cPos.y = 1 + rand() % (rowN - 2);
		cPos.x = 1 + rand() % (colN - 2);
	} while (cPos.y == hPos.y && cPos.x == hPos.x); // to avoid the same position with Hero
	gCreature.setPos(cPos.y, cPos.x);

	// setup for two Trigger positions
	for (int i = 0; i < 2; i++) {

		// initialize a new gTrigger
		Trigger* trigger = new Trigger();
		gTrigger.push_back(trigger);

		// setup for current Trigger position
		Position tPos;
		do {
			tPos.y = 1 + rand() % (rowN - 2);
			tPos.x = 1 + rand() % (colN - 2);
		} while ((tPos.y == hPos.y && tPos.x == hPos.x) || (tPos.y == cPos.y && tPos.x == cPos.x));
		gTrigger[i]->setPos(tPos.y, tPos.x);
	}

	/************************************************************************/
}

//******************************************************************
//
// * Draw the board
//==================================================================
void draw()
//==================================================================
{
	// Add the hero into the board
	// Setup and implementation of drawing board using 2d vector
	/*Please implement your code here*/

	// initialize a 2d vector for drawing 2d board with '0' in specific size
	std::vector<std::vector<char>> drawBoard(GHEIGHT, std::vector<char>(GWIDTH, '0'));

	// assign the value to board drawing
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	/************************************************************************/

	// Draw two triggers using for loop on drawBoard
	/*Please implement your code here*/

	// assign the specific character to board drawing at position of Triggers 
	for (int i = 0; i < gTrigger.size(); i++) {
		Position tPos = gTrigger[i]->getPos();
		drawBoard[tPos.y][tPos.x] = gTrigger[i]->getIcon();
	}

	/************************************************************************/

	Position c = gCreature.getPos();
	drawBoard[c.y][c.x] = gCreature.getIcon();

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getIcon();

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
	std::cout << "The hero is level " << gHero.getLevel() << "(" << gHero.getExp() << "/" << gHero.getMaxExp() << " to level up)" << std::endl;
	std::cout << "The hero has " << gHero.getHP() << " hp" << std::endl;
	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Every time you step on a trigger T, the hero gets 10 exp." << std::endl;
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

	// Manipulate update of two triggers using while loop
	/*Please implement your code here*/

	// update the information of both Triggers when Hero step on one of each Trigger
	int index = 0;
	while (index < gTrigger.size()) {
		gTrigger[index]->update(gHero);
		index++;
	}

	/************************************************************************/

	gCreature.update(gHero);
	draw();
	drawInfo();
}
