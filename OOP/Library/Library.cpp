/*****************************************************************//**
 * File: Library.cpp
 * Author: Leong Yah Xuan
 * Create Date: June 9, 2023
 * Update Date: June 9, 2023
 * Description: This C++ program implements a library database system to store some information of books.
 *********************************************************************/
#include "Library.h"

 // initialize
Library::Library() :books() {};

/*****************************************************************//**
* Intent: To add the book datum into the database.
* Pre: The variables title,author,edition must have a value.
* Post: The function adds the book datum into the database.
* \param title
* \param author
* \param edition
*********************************************************************/
void Library::insert(const std::string& title, const std::string& author, const int& edition)
{
	// check if the book is already in library
	for (Book& book : books)
	{
		// if the book already got
		if (book.title == title && book.author == author)
		{
			// check same edition or not
			if (book.editions.find(edition) != book.editions.end())
			{
				// if yes
				std::cout << "Datum already exist." << std::endl;
				return; // direct jump out
			}
			else // if different edition
			{
				// add edition for that book
				book.editions.insert(edition);

				// output message
				std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << "." << std::endl;
				return; // direct jump out
			}
		}
	}

	// if book got no book in library
	// create new book
	Book newBook;
	newBook.title = title;
	newBook.author = author;
	newBook.editions.insert(edition);

	// put into library
	books.push_back(newBook);

	// output message
	std::cout << "Insert " << author << "'s " << title << ", Edition: " << edition << "." << std::endl;
}

/*****************************************************************//**
 * Intent: To locate the specific edition of book datum matching the title and author from the database.
 * Pre: The variables title,author,edition must have a value.
 * Post: The function removes the specific edition of book datum.
 * \param title
 * \param author
 * \param edition
 *********************************************************************/
void Library::deleteEdition(const std::string& title, const std::string& author, const int& edition)
{
	// search if the book got or not
	for (Book& book : books)
	{
		// if found
		if (book.title == title && book.author == author)
		{
			// check the edition got or not
			auto it = book.editions.find(edition);

			// if yes
			if (it != book.editions.end())
			{
				// delete it
				book.editions.erase(it);

				// output message
				std::cout << "Delete " << author << "'s " << title << ", Edition: " << edition << "." << std::endl;

				// if edition become empty
				if (book.editions.empty())
				{
					// delete the book from library
					books.erase(find(books.begin(), books.end(), book));
				}

				// direct jump out
				return;
			}
			else // if cannot found the edition
			{
				std::cout << "Datum doesn't exist." << std::endl;
				return; // direct jump out
			}
		}
	}
}

/*****************************************************************//**
 * Intent: To delete all data matching the record of title and author in the database.
 * Pre: The variables title,author must have a value.
 * Post: The function deletes all data matching the record of title and author in the database.
 * \param title
 * \param author
 *********************************************************************/
void Library::deleteBook(const std::string& title, const std::string& author)
{
	// 
	auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
		return (book.title == title && book.author == author);
		});

	// if found the book
	if (it != books.end())
	{
		// delete from library
		books.erase(it);

		// output message
		std::cout << "Delete " << author << "'s " << title << "." << std::endl;
	}
	else // if not found the book
	{
		std::cout << "Book doesn't exist." << std::endl;
	}
}

/*****************************************************************//**
 * Intent: To find the book datum matching the title and author in the database.
 * Pre: The variables title,author must have a value.
 * Post: The function finds the book datum matching the title and author in the database.
 * \param title
 * \param author
 *********************************************************************/
void Library::findBook(const std::string& title, const std::string& author)
{
	// find if the book is in library
	for (const Book& book : books)
	{
		// if found
		if (book.title == title && book.author == author)
		{
			// output message
			std::cout << "Title: " << book.title << "\tAuthor: " << book.author << "\tEdition: ";

			// with all the edition
			for (auto it = book.editions.begin(); it != book.editions.end(); ++it)
			{
				std::cout << *it;

				// in format ","
				if (next(it) != book.editions.end())
				{
					std::cout << ", ";
				}
			}
			std::cout << std::endl;

			// direct return
			return;
		}
	}

	// if after loop not found
	std::cout << "Book doesn't exist." << std::endl;
}

/*****************************************************************//**
 * Intent: To find all the book written by author.
 * Pre: The variable author must have a value.
 * Post: The function finds all the book written by author.
 * \param author
 *********************************************************************/
void Library::findAuthor(const std::string& author)
{
	std::vector<std::string> authorBooks;

	// find if book of that author got in library
	for (const Book& book : books)
	{
		// if found
		if (book.author == author)
		{
			// add to display vector
			authorBooks.push_back(book.title);
		}
	}

	// if display vector is empty
	if (authorBooks.empty())
	{
		// mean that author do not have book in library
		std::cout << "No book found." << std::endl;
	}
	else // if not empty
	{
		// sort by author name
		std::sort(authorBooks.begin(), authorBooks.end());

		// output the books
		std::cout << author << "'s Books: ";
		for (size_t i = 0; i < authorBooks.size(); i++)
		{
			std::cout << authorBooks[i];

			// in "," format
			if (i != authorBooks.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
}

/*****************************************************************//**
 * Intent: To sort the database by comparing the title with string relation.
 * Pre: The variable books must have value.
 * Post: The function sorts the database based on the title.
 *********************************************************************/
void Library::sortByTitle()
{
	// create algorithm with title sorted then author sort
	sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
		if (a.title != b.title)
		{
			return a.title < b.title;
		}
		else // if title name same
		{
			// sort by author
			return a.author < b.author;
		}
		});

	// output the book sorted by algorithm
	for (const Book& book : books)
	{
		std::cout << "Title: " << book.title << "\tAuthor: " << book.author << "\tEdition: ";

		for (auto it = book.editions.begin(); it != book.editions.end(); it++)
		{
			std::cout << *it;
			if (next(it) != book.editions.end())
			{
				// in "," format
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
}

/*****************************************************************//**
 * Intent: To sort the database by comparing the author with string relation.
 * Pre: The variable books must have value.
 * Post: The function sorts the databased based on the author
 *********************************************************************/
void Library::sortByAuthor()
{
	// create algorithm with author sorted then title sort
	sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
		if (a.author != b.author)
		{
			return a.author < b.author;
		}
		else // if author name same
		{
			// sort by title
			return a.title < b.title;
		}
		});

	// output the books sorted by algoritm
	for (const Book& book : books)
	{
		std::cout << "Title: " << book.title << "\tAuthor: " << book.author << "\tEdition: ";

		for (auto it = book.editions.begin(); it != book.editions.end(); ++it)
		{
			std::cout << *it;

			if (next(it) != book.editions.end())
			{
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
}