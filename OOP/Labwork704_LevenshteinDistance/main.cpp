/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 15, 2023
 * Update Date : April 19, 2023
 * Description : This C++ program finds the minimum distance between two text.
 *********************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

 /**
 * Intent : To calculate the levenshtein distance of two words.
 * Pre : The variables word1,word2 must have a value.
 * Post : The function returns the levenshtein distance of two words.
 * \param word1
 * \param word2
 * \return
 */
int levenshteinDistance(const std::string& word1, const std::string& word2)
{
	// initialize whole vector become 0, in order to let the first row and col remain 0
	std::vector<std::vector<int>> editCount(word1.length() + 1, std::vector<int>(word2.length() + 1, 0));

	// the operation of deleting
	for (int i = 1; i <= word1.length(); i++) // loop from 1 to let the count work
	{
		// mark the cost that all character in word1 have to be deleted => become NULL
		editCount[i][0] = i;
	}

	// the operation of inserting
	for (int j = 1; j <= word2.length(); j++)
	{
		// mark the cost that all the character in word2 have to be inserted => NULL become word2
		editCount[0][j] = j;
	}

	// the operation of replacing word1 become word2
	for (size_t i = 0; i < word1.length(); i++)
	{
		for (size_t j = 0; j < word2.length(); j++)
		{
			// to let first i word1 become to first j+1 word2
			int insertAfterWord1 = editCount[i][j + 1] + 1; // add cost +1

			// to let first j word2 become to first i+1 word1
			int insertAfterWord2 = editCount[i + 1][j] + 1; // add cost +1

			// check whether the character of word are same
			// if not same, then need to be replaced, count on 1
			int cost = (word1[i] == word2[j]) ? 0 : 1;
			int replaceCount = editCount[i][j] + cost;

			// compare to get the minimum cost for distance between two words
			editCount[i + 1][j + 1] = std::min(insertAfterWord1, std::min(insertAfterWord2, replaceCount));
		}
	}

	// return the saved value in the table at the index of both word length
	return editCount[word1.length()][word2.length()];
}

int main(void)
{
	// declare variables which are needed
	std::string line = "";
	std::string word1 = "", word2 = "";
	int distance = 0;

	// infinite loop until cin meets EOF
	while (std::getline(std::cin, line)) // read string line by line
	{
		// assign the first read line in word1
		word1 = line;

		// read a string line again
		std::getline(std::cin, line);

		// assign the second read line in word2
		word2 = line;

		// call function to output the levenshtein distance between both word
		distance = levenshteinDistance(word1, word2);

		// output the levenshtein distance between both word
		std::cout << distance << std::endl;
	}

	return 0;
}