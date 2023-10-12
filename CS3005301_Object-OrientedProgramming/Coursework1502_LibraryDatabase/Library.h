/*****************************************************************//**
 * File: Library.h
 * Author: Leong Yah Xuan
 * Create Date: June 9, 2023
 * Update Date: June 9, 2023
 * Description: This C++ program implements a library database system to store some information of books.
 *********************************************************************/
#pragma once
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

typedef struct Book
{
	std::string title;
	std::string author;
	std::set<int> editions;

	bool operator==(const Book& other) const
	{
		return title == other.title && author == other.author;
	}
} Book;

class Library
{
private:
	std::vector<Book> books;
public:
	Library();
	void insert(const std::string& title, const std::string& author, const int& edition);
	void deleteEdition(const std::string& title, const std::string& author, const int& edition);
	void deleteBook(const std::string& title, const std::string& author);
	void findBook(const std::string& title, const std::string& author);
	void findAuthor(const std::string& author);
	void sortByTitle();
	void sortByAuthor();
};