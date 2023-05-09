/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : May 5, 2023
 * Update Date : May 5, 2023
 * Description : This C++ program verifies whether the words in each pair match.
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>

#define NUM_LETTER 26

int main(void)
{
	// reusable variables, place these variables outside of the loop
	int numPossibleTranslation = 0, numDecodePairs = 0;

	// read the number of translations of letters and the number of word pairs
	while (std::cin >> numPossibleTranslation >> numDecodePairs)
	{
		if (numPossibleTranslation == 0 && numDecodePairs == 0)
		{
			// Exit the program while inputs are both 0
			break;
		}

		// declare variables which are needed
		std::vector<std::vector<bool>> transitionMachine(NUM_LETTER, std::vector<bool>(NUM_LETTER, false));
		char originLetter = 0, decipherLetter = 0;
		std::string word1 = "", word2 = "";

		// generate a table that saving the letter A can be translated to the letter B
		for (int i = 0; i < numPossibleTranslation; i++)
		{
			// read possible translation pairs of letters
			std::cin >> originLetter >> decipherLetter;

			// convert index from char to int 
			int fromLetter = originLetter - 'a';
			int toLetter = decipherLetter - 'a';

			// mark that the transition is valid in table by index
			transitionMachine[fromLetter][toLetter] = true;
		}

		// mark also the muliple transition is valid
		for (int j = 0; j < NUM_LETTER; j++) // loop as transfer letter
		{
			for (int i = 0; i < NUM_LETTER; i++) // loop as origin letter
			{
				for (int k = 0; k < NUM_LETTER; k++) // loop as target letter
				{
					// if (a->b) && (b->c)
					if (transitionMachine[i][j] && transitionMachine[j][k])
					{
						// then (a->c)
						transitionMachine[i][k] = true;
					}
				}
			}
		}

		for (int i = 0; i < numDecodePairs; i++)
		{
			// read pairs of original and deciphered words
			std::cin >> word1 >> word2;

			// Two words match if they have the same length
			if (word1.length() != word2.length())
			{
				// if not the same length
				std::cout << "no" << std::endl;
				continue; // to read next pair of words
			}

			bool isMatch = true;

			// if word length same
			// check if the pair of words have available translations
			for (int j = 0; j < word1.length(); j++)
			{
				// convert index from char to int 
				int fromLetter = word1[j] - 'a';
				int toLetter = word2[j] - 'a';

				// if found one letter of the first word which different with letter of second word
				// cannot be turned into the corresponding letter of the second word
				if ((word1[j] != word2[j]) && (!transitionMachine[fromLetter][toLetter]))
				{
					isMatch = false;
					break; // jump out this loop to stop checking available translations
				}
			}

			// check if the result of both words are match
			if (isMatch)
			{
				// if match, output yes
				std::cout << "yes" << std::endl;
			}
			else // if not match
			{
				std::cout << "no" << std::endl;
			}

		}
	}

	return 0;
}