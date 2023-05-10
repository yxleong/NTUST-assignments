/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	B11015042
 * Create Date: April 11, 2023
 * Update Date: April 11, 2023
 * Description: This C++ program implements Hero movement by string input.
 *********************************************************************/

 /************************************************************************
 File:   source.cpp

 Author:
		 ���s�Aea5878158@gmail.com
 Modifier:
		 �௧�N�Acheeryuchi@gmail.com
		 ���Y���Awindyhuang6@gmail.com
		 ���T�t�AJYCReports@gmail.com
		 ���ſ��Atbcey74123@gmail.com
 Comment:
		 �򥻿�J��V���ʥ\��Aw s a d ���ʸ}��W�U���k�A�ťէ��ܸ}�⯸�ߤ��a�O�r���A��T�W�i�H�W�[�g��
		 ESC�O���}�e���C�P�ɧ�s�Ϫ��W����T�C

 ************************************************************************/

#include "main.h"
#include "Hero.h"
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

const int GWIDTH = 10;
const int GHEIGHT = 10;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// �Ψ��x�s�������
char gBoard[GHEIGHT][GWIDTH];

// �w�q���ؿ�J���O�P�����}�Cindex
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	EJUMP,
	INVALID,
};


Creature gCreature;

// function declare
// ������J���A
void keyUpdate(bool key[]);
// ��l�ƪ���
void setupBoard();
// ��X����
void draw(void);
// ��X������T
void drawInfo(void);

// �{���D�X�ʨ禡
void update(bool key[]);

Trigger gTrigger(5, 5, 10);
int globalJumpX, globalJumpY;

int main(int argc, char** argv)
{
	srand(time(NULL));

	// �ΨӺ޲z��L��J���A���}�C
	bool gKeyState[6];
	for (int i = 0; i < 6; i++) {
		gKeyState[i] = false;
	}

	// Setup a clear dungeon
	setupBoard();

	gCreature.setPos(5, 6);

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
// * ������J���A
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}

	ValidInput inputType = ValidInput::INVALID;
	int jumpX = 0, jumpY = 0;

	// Read from input and parse to operation
	/*Please implement your code here*/

	std::string input = "";
	std::cin >> input;

	if (input == "Exit") {
		inputType = ValidInput::EESC;
	}
	else if (input.length() == 9)
	{
		std::string command = "";
		for (int i = 0; i < 4; i++) {
			command += input[i];
		}

		if (command == "Move") {
			int x = input[5] - '0';
			int y = input[7] - '0';
			Position hPos = gHero.getPos();

			int movement = 0;
			movement += abs(hPos.x - x);
			movement += abs(hPos.y - y);

			bool isOneMove = false;
			if (movement == 1) { isOneMove = true; }

			if (isOneMove) {
				if (hPos.y > y) inputType = ValidInput::EW; // up
				else if (hPos.y < y) inputType = ValidInput::ES; // down
				else if (hPos.x > x) inputType = ValidInput::EA; // left
				else if (hPos.x < x) inputType = ValidInput::ED; // right
			}
		}
		else if (command == "Jump") {
			jumpX = input[5] - '0';
			jumpY = input[7] - '0';
			inputType = ValidInput::EJUMP;
		}
		else { // look at the last character of the line and decide to move WASD
			char lastDigit = input[input.length() - 1];
			if (lastDigit == 'w' || lastDigit == 'W') inputType = ValidInput::EW; // up
			else if (lastDigit == 's' || lastDigit == 'S') inputType = ValidInput::ES; // down
			else if (lastDigit == 'a' || lastDigit == 'A') inputType = ValidInput::EA; // left
			else if (lastDigit == 'd' || lastDigit == 'D') inputType = ValidInput::ED; // right
		}
	}
	else // look at the last character of the line and decide to move WASD
	{
		char lastDigit = input[input.length() - 1];
		if (lastDigit == 'w' || lastDigit == 'W') inputType = ValidInput::EW; // up
		else if (lastDigit == 's' || lastDigit == 'S') inputType = ValidInput::ES; // down
		else if (lastDigit == 'a' || lastDigit == 'A') inputType = ValidInput::EA; // left
		else if (lastDigit == 'd' || lastDigit == 'D') inputType = ValidInput::ED; // right
	}

	/************************************************************************/

	if (inputType == ValidInput::EW) {
		key[ValidInput::EW] = true;
	}
	else if (inputType == ValidInput::EA) {
		key[ValidInput::EA] = true;
	}
	else if (inputType == ValidInput::ES) {
		key[ValidInput::ES] = true;
	}
	else if (inputType == ValidInput::ED) {
		key[ValidInput::ED] = true;
	}
	else if (inputType == ValidInput::EESC) {
		key[ValidInput::EESC] = true;
	}
	else if (inputType == ValidInput::EJUMP) {
		key[ValidInput::EJUMP] = true;
		globalJumpX = jumpX;
		globalJumpY = jumpY;
	}
}

//******************************************************************
//
// * �P�_��m�O�_����
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
// * �Q�� call-by-referce �N�p��o�쪺��V�^��
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

	Position t = gTrigger.getPos();
	drawBoard[t.y][t.x] = gTrigger.getIcon();

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
	std::cout << "Every time you step on a trigger T, the hero gets " << gTrigger.getExpAmount() << " EXP points" << std::endl;
	std::cout << "Type Exit to exit" << std::endl;
}

//******************************************************************
//
// * Update the board state
//==================================================================
void update(bool key[])
//==================================================================
{
	// �M������
	system("CLS");

	// �O�_��input
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
	else if (key[ValidInput::EJUMP]) {
		gHero.jump(globalJumpX, globalJumpX);
		hasInput = true;
	}
	else {
		std::cout << "invalid input\n";
	}
	gTrigger.update(gHero);
	gCreature.update(gHero);
	draw();
	drawInfo();
}
