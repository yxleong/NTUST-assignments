/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	Tien Qingian
 * Create Date: February 21, 2023
 * Update Date: February 21, 2023
 * Description: This C++ program implements basic user input control.
 *********************************************************************/

 /************************************************************************
 File:   Source.cpp

 Author:
		 Áé½å¼s¡Aea5878158@gmail.com
 Modifier:
		 ¿à¯§¦N¡Acheeryuchi@gmail.com
		 ³¯«T¦t¡AJYCReports@gmail.com
 Comment:
		 Output W,A,S,D after input, ESC to stop process.

 ************************************************************************/
#include <iostream>	// For print out information
#include <conio.h>	// For getch() function

 // Define inputs and its index
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

// Detect state of input
void keyUpdate(bool key[]);

int main()
{
	//Initialize state of key
	bool gKeyState[ValidInput::INVALID];

	// Obtain and update the input using a loop
	/************************************************************************/
	/*Please implement your code here*/

	while (true) {
		// continuously read user input in a loop

		keyUpdate(gKeyState);

		// End the expression and output the end message when pressing the Esc key
		if (gKeyState[ValidInput::EESC]) {
			std::cout << "Key ESC is pressed. End program." << std::endl;
			break;
		}
		else {
			if (gKeyState[ValidInput::EW])
				std::cout << "Key W is pressed." << std::endl;
			else if (gKeyState[ValidInput::ES])
				std::cout << "Key S is pressed." << std::endl;
			else if (gKeyState[ValidInput::EA])
				std::cout << "Key A is pressed." << std::endl;
			else if (gKeyState[ValidInput::ED])
				std::cout << "Key D is pressed." << std::endl;
			else
				std::cerr << "Wrong input!" << std::endl;
		}
	}

	return 0;

	/************************************************************************/
}

//******************************************************************
//
// * °»´ú¿é¤Jª¬ºA
//==================================================================
void keyUpdate(bool key[])
//==================================================================
{
	for (int i = 0; i < ValidInput::INVALID; i++) {
		key[i] = false;
	}
	char input = _getch();

	// Implement a switch for output calls
	/************************************************************************/
	/*Please implement your code here*/

	switch (input) {
		// Use the switch to judge the input
		// when pressing W, A, S, D to input the corresponding message
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
	default:
		break;
	}

	/************************************************************************/
}
