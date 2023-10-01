/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: May 20, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program is to implement exception handling using try, throw, and catch in dungeon game.
*********************************************************************/
#include "main.h"
#include "MyException.h"
#include "Object.h"
#include "Creature.h"
#include "Bat.h"
#include "Ghost.h"
#include "Wolf.h"
#include "Item.h"
#include "Trigger.h"
#include "Weapon.h"
#include "Potion.h"
#include <vector>
#include <fstream>
#include <stack>

Hero	gHero;
std::vector<Creature*> gCreatures;
std::vector<Item*> gItems;

// Constent value
const char GWALL = 'O';
const char GNOTHING = ' ';

int GWIDTH = -1;
int GHEIGHT = -1;
const int MIN_SIZE = 4;
const double gTimeLog = 0.033;

// Distance
const int gDistance = 4;

// Used to store layout data
char** gBoard;

// Define six input commands and corresponding array index
enum ValidInput
{
	EW = 0,
	ES = 1,
	EA = 2,
	ED = 3,
	ESPACE = 4,
	EESC = 5,
	ESave = 6,
	ELoad = 7,
	INVALID,
};

// function declare
void keyUpdate(bool key[]);			 // detect input status
void setupBoard(int rowN, int colN); // initialize layout
void draw(void);					 // output layout
void drawInfo(void);				 // Output description information

void update(bool key[]);			 // program main driver function

void saveMap();
void loadMap();

int main(int argc, char** argv)
{
	srand(time(NULL));

	// An array used to manage the state of keyboard input
	bool gKeyState[ValidInput::INVALID];
	for (int i = 0; i < ValidInput::INVALID; i++) {
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
			try {
				update(gKeyState);
			}
			catch (MyException& error) {
				std::cout << error.message;
				draw();
				drawInfo();
			}
			startT = clock();
		}

		// Update the key
		keyUpdate(gKeyState);
		endT = clock();

		if (gKeyState[ValidInput::ESave]) {
			saveMap();
			gKeyState[ValidInput::ESave] = false;
		}
		else if (gKeyState[ValidInput::ELoad]) {
			loadMap();
			gKeyState[ValidInput::ELoad] = false;
		}
	}

	system("pause");
	return 0;
}

/*****************************************************************//**
 * Intent: To detect input status.
 * Pre: The variable key must have value.
 * Post: The function detects the input status.
 * \param key
 *********************************************************************/
void keyUpdate(bool key[])
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();
	switch (input) {
	case 'w':
	case 'W':
		key[ValidInput::EW] = true;
		break;
	case 's':
	case 'S':
		key[ValidInput::ES] = true;
		break;
	case 'a':
	case 'A':
		key[ValidInput::EA] = true;
		break;
	case 'd':
	case 'D':
		key[ValidInput::ED] = true;
		break;
	case ' ':
		key[ValidInput::ESPACE] = true;
		break;
	case 27:
		key[ValidInput::EESC] = true;
		break;
	case '1':
		key[ValidInput::ESave] = true;
		break;
	case '2':
		key[ValidInput::ELoad] = true;
		break;
	default:
		break;
	}
}

/*****************************************************************//**
 * Intent: To determine whether the position is empty.
 * Pre: The object pos must have a valid value.
 * Post: The function returns the boolean value which indicates if the position is empty.
 * \param pos
 * \return
 *********************************************************************/
bool isPositionValid(Position& pos)
{
	// Check whether it is an empty space
	if (gBoard[pos.y][pos.x] != GNOTHING)
		return false;

	return true;
}

/*****************************************************************//**
 * Intent: To implement clip algroithm.
 * Pre: The variables n,minimun,maximum must have value.
 * Post: The function clips a given value within a specified range.
 * \param n
 * \param minimun
 * \param maximum
 * \return
 *********************************************************************/
float clip(float n, float minimun, float maximum)
{
	return std::max(minimun, std::min(n, maximum));
}

/*****************************************************************//**
 * Intent: To calculate the volume of a sphere with a given radius.
 * Pre: The objects wPos,hPos,dir must have a valid value.
 * Post: The function returns the calculated direction by call-by-reference.
 * \param wPos
 * \param hPos
 * \param dir
 * \return
 *********************************************************************/
bool canSee(Position wPos, Position hPos, Position& dir, float value)
{
	// the dir_x and dir_y value are call-by-refernce
	dir.x = (int)clip((float)(hPos.x - wPos.x), -value, value); // clip the value between -1 ~ 1
	dir.y = (int)clip((float)(hPos.y - wPos.y), -value, value);
	int count = 0;
	do {
		// spot the target position
		if (wPos + dir * count == hPos) {
			return true;
		}
		count++;
	} while (count < gDistance); // check the range in 4 units
	return false;
}

/*****************************************************************//**
 * Intent: To generate a map using recursion.
 * Pre: The variables must have valid value.
 * Post: The function generates a map using recursion.
 * \param startRow
 * \param endRow
 * \param startCol
 * \param endCol
 * \param isHorizontal
 *********************************************************************/
void recursiveDivision(int startRow, int endRow, int startCol, int endCol, bool isHorizontal) {

	// if area is too small, then no need add any wall
	if (endRow - startRow < 2 || endCol - startCol < 2) {
		return;
	}

	// add a wall in random position within an area
	int wallRow = startRow + 1 + 2 * (rand() % ((endRow - startRow) / 2));
	int wallCol = startCol + 1 + 2 * (rand() % ((endCol - startCol) / 2));

	// to check if the wall is at even position
	if (wallRow % 2 == 0) { // if yes
		wallRow++; // add one to let it become odd position
	} // in order to clear even position for path
	if (wallCol % 2 == 0) {
		wallCol++;
	}

	// check if the orientation of the wall is horizontal
	if (isHorizontal) { // if yes
		for (int i = startCol; i <= endCol; i++) {
			if (i != wallCol) { // path for connecting seperated area
				gBoard[wallRow][i] = GWALL; // create a horizontal wall in that row
			}
		}

		// create one random opening for this wall
		int passage = startCol + 1 + 2 * (rand() % ((endCol - startCol) / 2));
		gBoard[wallRow][passage] = GNOTHING;

		// recursively divide the sections on both sides of the wall in vertical
		recursiveDivision(startRow, wallRow - 1, startCol, endCol, !isHorizontal);
		recursiveDivision(wallRow + 1, endRow, startCol, endCol, !isHorizontal);

		// create a path through the wall to make sure connecting divided sections
		int pathCol = startCol + 1 + 2 * (rand() % ((endCol - startCol) / 2));
		gBoard[wallRow][pathCol] = GNOTHING;
	}
	else { // if is vertical
		bool isVertical = isHorizontal;

		for (int i = startRow; i <= endRow; i++) {
			if (i != wallRow) { // path for connecting seperated area
				gBoard[i][wallCol] = GWALL; // create a vertical wall in that col
			}
		}

		// create one random opening for this wall
		int passage = startRow + 1 + 2 * (rand() % ((endRow - startRow) / 2));
		gBoard[passage][wallCol] = GNOTHING;

		// recursively divide the sections on both sides of the wall in horizontal
		recursiveDivision(startRow, endRow, startCol, wallCol - 1, !isVertical);
		recursiveDivision(startRow, endRow, wallCol + 1, endCol, !isVertical);

		// create a path through the wall to make sure connecting divided sections
		int pathRow = startRow + 1 + 2 * (rand() % ((endRow - startRow) / 2));
		gBoard[pathRow][wallCol] = GNOTHING;
	}
}

/*****************************************************************//**
 * Intent: To setup the board.
 * Pre: The variables rowN,colN must have a value and rowN,colN > 0.
 * Post: The function setups the board as gBoard.
 * \param rowN
 * \param colN
 *********************************************************************/
void setupBoard(int rowN, int colN)
{
	// Allocate & init game board using 2d dynamic array

	gBoard = new char* [rowN];
	for (int i = 0; i < rowN; i++) {
		gBoard[i] = new char[colN];
		for (int j = 0; j < colN; j++) {
			if (i == 0 || i == rowN - 1 || j == 0 || j == colN - 1)
				gBoard[i][j] = GWALL;
			else
				gBoard[i][j] = GNOTHING;
		}
	}

	// Call the gBoard generation function
	recursiveDivision(1, rowN - 2, 1, colN - 2, true);

	// Setup for (random) position of all elements and implementation of game board using 2d dynamic array
	// Elements are randomly generated within canvas

	std::vector<std::vector<bool>> validFlags(GHEIGHT);
	for (int i = 0; i < GHEIGHT; i++) {
		validFlags[i].resize(GWIDTH);
		for (int j = 0; j < GWIDTH; j++) {
			validFlags[i][j] = gBoard[i][j] == GWALL ? false : true;
		}
	}

	auto getRandomPos = [&rowN, &colN]() {
		return Position((int)(rand() % colN), (int)(rand() % rowN));
	};

	auto getValidRandomPos = [&validFlags, &getRandomPos]() {
		while (true) {
			Position pos = getRandomPos();
			if (validFlags[pos.y][pos.x]) {
				return pos;
			}
		}
	};

	Position hPos = getValidRandomPos();
	validFlags[hPos.y][hPos.x] = false;
	gHero.setPos(hPos);

	// Create Bats
	Bat* bat = new Bat();
	Position bPos = getValidRandomPos();
	validFlags[bPos.y][bPos.x] = false;
	bat->setPos(bPos);
	gCreatures.push_back(bat);

	// Create Wolves
	Wolf* wolf = new Wolf();
	Position wPos = getValidRandomPos();
	validFlags[wPos.y][wPos.x] = false;
	wolf->setPos(wPos);
	gCreatures.push_back(wolf);

	// Create Ghosts
	Ghost* ghost = new Ghost();
	Position gPos = getValidRandomPos();
	validFlags[gPos.y][gPos.x] = false;
	ghost->setPos(gPos);
	gCreatures.push_back(ghost);

	// Create Triggers
	Trigger* trigger = new Trigger();
	Position tPos = getValidRandomPos();
	validFlags[tPos.y][tPos.x] = false;
	trigger->setPos(tPos);
	gItems.push_back(trigger);

	// Create Weapon
	Weapon* weapon = new Weapon();
	Position wwPos = getValidRandomPos();
	validFlags[wwPos.y][wwPos.x] = false;
	weapon->setPos(wwPos);
	gItems.push_back(weapon);

	// Create Potion
	Potion* potion = new Potion();
	Position pPos = getValidRandomPos();
	validFlags[pPos.y][pPos.x] = false;
	potion->setPos(pPos);
	gItems.push_back(potion);
}

/*****************************************************************//**
* Intent: To draw the board.
* Pre: The const variables must be well-defined.
* Post: The function displays the dungeon game board.
*********************************************************************/
void draw()
{
	// Add the hero into the board
	// Setup and implementation of drawing board using 2d vector

	std::vector<std::vector<char>> drawBoard(GHEIGHT);

	for (int i = 0; i < GHEIGHT; i++) {
		drawBoard[i].resize(GWIDTH);
		for (int j = 0; j < GWIDTH; j++) {
			drawBoard[i][j] = gBoard[i][j];
		}
	}

	// Draw items using for loop on drawBoard
	for (int i = 0; i < gItems.size(); i++) {
		Position t = gItems[i]->getPos();
		drawBoard[t.y][t.x] = gItems[i]->getDispIcon();
	}

	// Draw creatures using for loop on drawBoard
	for (int i = 0; i < gCreatures.size(); i++) {
		Position c = gCreatures[i]->getPos();
		drawBoard[c.y][c.x] = gCreatures[i]->getDispIcon();
	}

	// Update the hero information
	Position h = gHero.getPos();
	drawBoard[h.y][h.x] = gHero.getDispIcon();

	// Draw the board
	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			std::cout << drawBoard[i][j]; //  output
		}
		std::cout << "\n";
	}
}

/*****************************************************************//**
 * Intent: To output information.
 * Pre: The const variables must be well-defined.
 * Post: The function outputs the information of dungeon game.
 *********************************************************************/
void drawInfo(void)
{
	std::cout << "The hero is level " << gHero.getLevel() << "(" << gHero.getExp() << "/" << gHero.getMaxExp() << " to level up)" << std::endl;
	std::cout << "The hero has " << gHero.getHP() << " hp" << std::endl;
	std::cout << "The hero has " << gHero.getAttack() << " attack power" << std::endl;
	std::cout << "Use wsad key to move Hero " << gHero.getIcon() << std::endl;
	std::cout << "Every time you step on a trigger T, the hero gets 10 exp." << std::endl;
	std::cout << "Every time you step on a weapon ), the hero gets 2 attack power." << std::endl;
	std::cout << "Every time you step on a potion &, the hero gets 5 hp." << std::endl;
	std::cout << "(ESC) Exit (1) Save (2) Load" << std::endl;
}

/*****************************************************************//**
 * Intent: To update the board state.
 * Pre: The const variables must be well-defined.
 * Post: The function update the dungeon game state.
 * \param key
 *********************************************************************/
void update(bool key[])
{
	// clear layout
	system("CLS");

	Position delta;

	// check is there an input
	bool hasInput = false;
	if (key[ValidInput::EW]) {
		delta -= Position(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::ES]) {
		delta += Position(0, 1);
		hasInput = true;
	}
	else if (key[ValidInput::EA]) {
		delta = delta - Position(1, 0);
		hasInput = true;
	}
	else if (key[ValidInput::ED]) {
		delta = delta + Position(1, 0);
		hasInput = true;
	}
	else {
		bool allInvalid = true;
		for (int i = 0; i < ValidInput::INVALID; i++) {
			if (key[i]) {
				allInvalid = false;
				break;
			}
		}
		if (allInvalid) {
			MyException errorMessage("Invalid input\n");
			throw errorMessage;
		}
	}
	if (hasInput) {
		gHero.move(delta);
	}

	for (int i = 0; i < gCreatures.size(); i++) {
		gCreatures[i]->update(gHero);
	}

	// Manipulate update of items using while loop
	for (int i = 0; i < gItems.size(); i++) {
		gItems[i]->update(gHero);
	}

	draw();
	drawInfo();
}

/*****************************************************************//**
 * Intent: To save the map status.
 * Pre: The const variables must be well-defined.
 * Post: The function saves dungen game to file.
 *********************************************************************/
void saveMap() {
	// Save dungen to file
	system("CLS");
	std::cout << "Input file name for saving or Exit to leave saving." << std::endl;
	std::cout << "Input: ";
	std::string input;
	std::cin >> input;
	if (input.compare("Exit") == 0)
		return;

	std::ofstream oStream(input + ".txt");
	oStream << GWIDTH << " " << GHEIGHT << std::endl;

	for (int i = 0; i < GHEIGHT; i++) {
		for (int j = 0; j < GWIDTH; j++) {
			oStream << gBoard[i][j];
		}
		oStream << std::endl;
	}
	oStream << std::endl;

	oStream << gHero.getPos() << " " << gHero.getHP() << " " << gHero.getLevel() << " " << gHero.getExp() << " " << gHero.getMaxExp() << " " << gHero.getAttack() << std::endl;

	oStream << gCreatures.size() << std::endl;
	for (int i = 0; i < gCreatures.size(); i++) {
		oStream << gCreatures[i]->getIcon() << " " << gCreatures[i]->getPos() << std::endl;
	}

	oStream << gItems.size() << std::endl;
	for (int i = 0; i < gItems.size(); i++) {
		oStream << gItems[i]->getIcon() << " " << gItems[i]->getPos() << std::endl;
	}

	oStream.close();
}

/*****************************************************************//**
 * Intent: To load the map status.
 * Pre: The const variables must be well-defined.
 * Post: The function resets the dungeon game.
 *********************************************************************/
void loadMap() {
	// Load from file and reset the dungen
	system("CLS");
	std::cout << "Input file name for loading or Exit to leave loading." << std::endl;
	std::cout << "Input: ";
	std::string input;
	std::cin >> input;
	if (input.compare("Exit") == 0)
		return;

	std::ifstream iStream(input + ".txt");
	if (!iStream.is_open())
		return;

	// reset dungen
	for (int i = 0; i < GHEIGHT; i++) {
		delete[] gBoard[i];
	}
	delete[] gBoard;

	for (int i = 0; i < gCreatures.size(); i++)
		delete gCreatures[i];
	gCreatures.clear();

	for (int i = 0; i < gItems.size(); i++)
		delete gItems[i];
	gItems.clear();

	iStream >> GWIDTH >> GHEIGHT;

	char _c;
	iStream.get(_c);

	gBoard = new char* [GHEIGHT];
	for (int i = 0; i < GHEIGHT; i++) {
		gBoard[i] = new char[GWIDTH];
		for (int j = 0; j < GWIDTH; j++) {
			iStream.get(gBoard[i][j]);
		}
		iStream.get(_c);
	}

	Position pos;

	int hp = 0, level = 0, exp = 0, maxExp = 0, power = 0;
	iStream >> pos >> hp >> level >> exp >> maxExp >> power;
	gHero.setPos(pos);
	gHero.setHP(hp);
	gHero.setLevel(level);
	gHero.setExp(exp);
	gHero.setMaxExp(maxExp);
	gHero.setAttack(power);

	int creatureN = 0;
	char creatureIcon = 0;
	iStream >> creatureN;
	for (int i = 0; i < creatureN; i++) {
		iStream >> creatureIcon >> pos;
		if (creatureIcon == 'B') {
			Bat* bat = new Bat();
			bat->setPos(pos);
			gCreatures.push_back(bat);
		}
		if (creatureIcon == 'W') {
			Wolf* wolf = new Wolf();
			wolf->setPos(pos);
			gCreatures.push_back(wolf);
		}
		if (creatureIcon == 'G') {
			Ghost* ghost = new Ghost();
			ghost->setPos(pos);
			gCreatures.push_back(ghost);
		}
	}

	int itemN = 0;
	char itemIcon = 0;
	iStream >> itemN;
	for (int i = 0; i < itemN; i++) {
		iStream >> itemIcon >> pos;
		if (itemIcon == 'T') {
			Trigger* trigger = new Trigger();
			trigger->setPos(pos);
			gItems.push_back(trigger);
		}
		if (itemIcon == ')') {
			Weapon* weapon = new Weapon();
			weapon->setPos(pos);
			gItems.push_back(weapon);
		}
		if (itemIcon == '&') {
			Potion* potion = new Potion();
			potion->setPos(pos);
			gItems.push_back(potion);
		}
	}

	iStream.close();
}
