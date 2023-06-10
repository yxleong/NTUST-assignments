/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: June 9, 2023
 * Update Date: June 10, 2023
 * Description: This C++ program implements a library database system to store some information of books.
 *********************************************************************/
#include "Library.h"
#include <iostream>
#include <sstream>

 /*****************************************************************//**
 * Intent: To seperate the command to be correct type.
 * Pre: The variable input must have value.
 * Post: The function reads command as correct type.
 * \param input
 *********************************************************************/
void readCommand(std::string& input) // to handle the string with space
{
	bool insideQuotes = false;

	for (char& c : input) {
		if (c == '"')
		{	// first time false->true
			insideQuotes = !insideQuotes;
			// second time true->false
		}

		if (insideQuotes && c == ' ')
		{
			// mark for first read
			c = '|';
		}
		else if (insideQuotes && c == '|')
		{
			// mark for catch data
			c = ' ';
		}
	}
}

int main(void)
{
	// declare the variables needed
	std::string input = "";
	Library library;

	// keep entering commands until reading EOF
	while (!std::cin.eof())
	{
		// read input in line
		std::getline(std::cin, input);

		// ignore the space
		if (input == "") continue;

		// seperate the command to words without "
		readCommand(input);

		// read the command as stringstream
		std::stringstream command(input);

		// differentiate the command
		std::string commandType = "";
		command >> commandType;

		// declare the variables needed
		std::string title = "", author = "";
		int edition = 0;

		if (commandType == "Insert")
		{
			if (command >> title >> author >> edition)
			{
				// read as "title title"
				readCommand(title);

				// delete the " to become title title
				title.erase(title.begin());
				title.erase(title.end() - 1);

				readCommand(author);
				author.erase(author.begin());
				author.erase(author.end() - 1);

				library.insert(title, author, edition);
			}
			else
			{
				std::cout << "Incomplete Command." << std::endl;
			}
		}
		else if (commandType == "Delete")
		{
			command >> commandType;

			if (commandType == "Edition")
			{
				if (command >> title >> author >> edition)
				{
					readCommand(title);
					title.erase(title.begin());
					title.erase(title.end() - 1);

					readCommand(author);
					author.erase(author.begin());
					author.erase(author.end() - 1);

					library.deleteEdition(title, author, edition);
				}
				else
				{
					std::cout << "Incomplete Command." << std::endl;
				}
			}
			else if (commandType == "Book")
			{
				if (command >> title >> author)
				{
					readCommand(title);
					title.erase(title.begin());
					title.erase(title.end() - 1);

					readCommand(author);
					author.erase(author.begin());
					author.erase(author.end() - 1);

					library.deleteBook(title, author);
				}
				else
				{
					std::cout << "Incomplete Command." << std::endl;
				}
			}
			else
			{
				std::cout << "Unknown Command." << std::endl;
			}
		}
		else if (commandType == "Find")
		{
			command >> commandType;

			if (commandType == "Book")
			{
				if (command >> title >> author)
				{
					readCommand(title);
					title.erase(title.begin());
					title.erase(title.end() - 1);

					readCommand(author);
					author.erase(author.begin());
					author.erase(author.end() - 1);

					library.findBook(title, author);
				}
				else
				{
					std::cout << "Incomplete Command." << std::endl;
				}
			}
			else if (commandType == "Author")
			{
				if (command >> author)
				{
					readCommand(author);
					author.erase(author.begin());
					author.erase(author.end() - 1);

					library.findAuthor(author);
				}
				else
				{
					std::cout << "Incomplete Command." << std::endl;
				}
			}
			else
			{
				std::cout << "Unknown Command." << std::endl;
			}
		}
		else if (commandType == "Sort")
		{
			command >> commandType; // by

			command >> commandType;
			if (commandType == "Title")
			{
				library.sortByTitle();
			}
			else if (commandType == "Author")
			{
				library.sortByAuthor();
			}
			else
			{
				std::cout << "Unknown Command." << std::endl;
			}
		}
		else
		{
			std::cout << "Unknown Command." << std::endl;
		}
	}

	return 0;
}