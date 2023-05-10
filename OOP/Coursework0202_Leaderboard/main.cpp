/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 8, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program outputs the top three players and scores
 *					by scan through the file.
 *********************************************************************/

#define SIZE 200
#define TOP 3

#include <iostream>
#include <fstream>
#include <algorithm>

 /**
 * Intent : To calculate the top three players and scores from file data.
 * Pre : Must scan through the file.
 * Post : The function returns the top three players and scores.
 * \param playerName
 * \param playerScore
 */
void getHighScores(std::string playerName[], int playerScore[])
{
	// declare variables which are needed
	std::ifstream inputFile;
	std::string fileName = "";
	std::string name = "", tempPlayerName[SIZE] = { {} };
	int score = 0, tempPlayerScore[SIZE] = { 0 };
	int numOfPlayers = 0, index[SIZE] = { 0 };

	// read input as a string
	std::cin >> fileName;

	// open file
	inputFile.open(fileName);

	if (inputFile.is_open()) // check if file is open
	{
		// infinite loop until cin meets EOF
		while (inputFile >> name >> score) // read file data
		{
			// assign file data to temp array
			tempPlayerName[numOfPlayers] = name;
			tempPlayerScore[numOfPlayers] = score;

			// record the number of elements in array
			numOfPlayers++;
		}

		inputFile.close(); // close the file
	}

	for (int i = 0; i < numOfPlayers; i++) // loop until i = numOfPlayers
	{
		index[i] = i; // assign index array with index of players in temp array
	}

	// decreasing order
	// arrange order of index array according to player scores
	std::sort(index, index + numOfPlayers, [&](int a, int b) {
		return tempPlayerScore[a] > tempPlayerScore[b];
		});

	for (int i = 0; i < TOP; i++) // loop until i = TOP
	{
		// assign top high data in temp array to parameter
		playerName[i] = tempPlayerName[index[i]];
		playerScore[i] = tempPlayerScore[index[i]];
	}

	//// record the index of the higher score in array
	//int high_score_index[3] = { 0, 0, 0 }; // initialize to -1
	//for (int player_index = 0; player_index < n; player_index++) {
	//	if (tempPlayerScore[player_index] > tempPlayerScore[high_score_index[0]]) {
	//		high_score_index[2] = high_score_index[1]; // 3. move back & throw data
	//		high_score_index[1] = high_score_index[0]; // 2. move back
	//		high_score_index[0] = player_index; // 1. record
	//	}
	//	else if (tempPlayerScore[player_index] > tempPlayerScore[high_score_index[1]]) {
	//		high_score_index[2] = high_score_index[1];
	//		high_score_index[1] = player_index;
	//	}
	//	else if (tempPlayerScore[player_index] > tempPlayerScore[high_score_index[2]]) {
	//		high_score_index[2] = player_index;
	//	}
	//	else continue;
	//}

	//for (int i = 0; i < 3; i++) {
	//	if (high_score_index[i] >= 0 && high_score_index[i] <= 3) { // to avoid warning C6385
	//		playerName[i] = tempPlayerName[high_score_index[i]];
	//		playerScore[i] = tempPlayerScore[high_score_index[i]];
	//	}
	//	else break;
	//}
}

int main(void)
{
	// declare variables which are needed
	std::string names[TOP] = { {} };
	int scores[TOP] = { 0 };

	// call function
	getHighScores(names, scores);

	for (int i = 0; i < TOP; i++) // loop until i = TOP
	{
		// output the top three players and scores
		std::cout << names[i] << std::endl << scores[i] << std::endl;
	}

	return 0;
}