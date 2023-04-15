/*****************************************************************//**
 * File : Form.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 11, 2023
 * UPDATE Date : April 12, 2023
 * Description : This C++ program loads few words compose by given word.
 *********************************************************************/
#include "Form.h"

 /**
 * Intent : To set the given word of the game.
 * Pre : The variable inputWord must have a value.
 * Post : The function sets the given word of the game.
 * \param inputWord
 */
void Form::SetInputWord(string inputWord)
{
	// assign the word by inputWord
	word = inputWord;
}

/**
* Intent : To do some necessary pre-process of the given word. (e.g. upper or lower case transition.)
* Pre : The variable inputWord must have a value.
* Post : The function processes the given word of the game.
*/
void Form::ProcessInputWord()
{
	// loop all the character of word assigned
	for (int i = 0; i < word.length(); i++)
	{
		// if the character is capital letter
		if (word[i] >= 'A' && word[i] <= 'Z') // attention : && not ||
		{

			// change the character value to lowercase
			word[i] -= ('A' - 'a');
		}
	}
}

/**
* Intent : To set the file name of the file that contains all the valid words.
* Pre : The variable fileName must have a value.
* Post : The function set the file name of the file that contains all the valid words.
* \param fileName
*/
void Form::SetFileName(string fileName)
{
	// assign fileName to file
	file = fileName;
}

/**
* Intent : To load the valid words from the file.
* Pre : The variables fileName,inputWord must have a value.
* Post : The function finds out all the valid words composed by the letters in the given word.
*/
void Form::Load_CompareWord()
{
	// read the given filename
	fstream read(file);

	// check if the file is open
	if (!read.is_open())
	{
		cout << "File error" << endl;
		return;
	}

	// reusable variable, place outside of the loop
	string line = "";

	// infinite loop until cin meets EOF
	while (getline(read, line)) // read by line
	{
		// declare variables which are needed
		string tempWord = word;
		bool isFound = true;

		// loop all character in read word in line
		for (char c : line)
		{
			// find the first index of word-in-line match with given word
			size_t indexFound = tempWord.find(c);

			// if found that character in line no match with given word
			if (indexFound == string::npos)
			{
				// mark not found
				isFound = false;

				// direct jump out the this word-in-line
				break;
			}
			else // if index of given word got assign
			{
				// remove the character tested
				tempWord.erase(indexFound, 1);
			}
			// continue test if next character of word-in-line is still match with word or not
		}

		// if whole word-in-line is valid in given word
		if (isFound)
		{
			// sava the word-in-line
			foundWords.push_back(line);
		}
	}

	// close the file read
	read.close();
}

/**
* Intent : To print the words found.
* Pre : The function void Form::Load_CompareWord() must valid.
* Post : The function outputs the words found.
*/
void Form::PrintFoundWords()
{
	// loop until the size of vector
	for (int i = 0; i < foundWords.size(); i++)
	{
		// output all the saved word-in-line from file
		cout << foundWords[i] << endl;
	}
}