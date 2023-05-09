/*****************************************************************//**
 * File: main.cpp
 * Author:
 *	Leong Yah Xuan
 *	B11015042
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
		 Use clock to count time (And output) for following input tasks

 ************************************************************************/

#include <ctime>
#include <iostream>

int main(int argc, char** argv)
{
	clock_t startT, endT; // Variable to store the start of the gameloop
	startT = clock();
	endT = clock();
	clock_t globalStartT = startT;

	// Start the game loop
	/************************************************************************/
	/*Please implement your code here*/

	const int GAME_DURATION = 15;
	int secsPass = 0;

	while (secsPass < GAME_DURATION) {
		// Continuously output messages using a loop
		// output a message every 1 (¡À0.05) seconds, output 15 seconds

		endT = clock();

		double elapsedTime = double(endT - startT) / CLOCKS_PER_SEC;
		// clock_t : clock tick counts
		// clock_t / CLOCKS_PER_SEC = sec

		if (elapsedTime >= 1.00 && elapsedTime <= 1.05)
		{
			std::cout << "Total time " << secsPass << " at " << 1.001 + secsPass;
			if (secsPass < GAME_DURATION - 1) std::cout << std::endl;

			secsPass++;
			globalStartT = startT;
			startT = endT;
		}
	}

	/************************************************************************/

}
