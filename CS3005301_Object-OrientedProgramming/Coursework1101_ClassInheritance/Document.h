/*****************************************************************//**
 * File: Document.h
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to define a class named Document.
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

class Document
{
private:
	std::string text; // stores any textual content for the document
public:
	Document();
	Document(std::string value);

	std::string getText() const;		// returns the text field
	void setText(const std::string&);	// a way to set this value

	Document& operator=(const Document&); // overloaded assignment operator
};
