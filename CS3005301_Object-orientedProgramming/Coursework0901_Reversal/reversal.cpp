/*****************************************************************//**
 * File: reversal.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 4, 2023
 * Update Date: May 9, 2023
 * Description: This C++ program finds the longest word that reverses to a different word.
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
	// declare variables which are needed
	std::string input = "";
	std::string longestReversalWord = "";
	std::vector<std::string> wordLists = { "" };

	// read the text file content
	while (std::cin >> input)
	{
		// save the words in a list
		wordLists.push_back(input);
	}

	// loop all the word in the list
	for (std::string reverseWord : wordLists)
	{
		// reverse the current word
		reverse(reverseWord.begin(), reverseWord.end());

		// search the current reversed word in the list
		for (std::string word : wordLists)
		{
			// if found the reversed word in the list
			// and the word is longer than the reversal word found
			if (word == reverseWord && reverseWord.length() > longestReversalWord.length())
			{
				// reverse back the word to be original word
				reverse(word.begin(), word.end());

				// replace the longest reversal word
				longestReversalWord = word;
			}
		}
	}

	// output the result
	std::cout << longestReversalWord << std::endl;

	return 0;
}