/*****************************************************************//**
 * File: Document.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to define a class named Document.
 *********************************************************************/
#include "Document.h"

 /*****************************************************************//**
 * Intent: To initialize a Document object with an empty text.
 * Pre: The variable text must be well-declared.
 * Post: The function initializes a Document object with an empty text.
 *********************************************************************/
Document::Document() :text("") {}

/*****************************************************************//**
 * Intent: To initialize a File object with a text value.
 * Pre: The variables textValue must have value.
 * Post: The function initializes a Document object with the provided text value.
 * \param value
 *********************************************************************/
Document::Document(std::string textValue)
{
	text = textValue;
}

/*****************************************************************//**
 * Intent: To retrieve the text of the Document object.
 * Pre: The variable text must be well-declared.
 * Post: The function returns the current recipient of the Document object.
 * \return
 *********************************************************************/
std::string Document::getText() const
{
	return text;
}

/*****************************************************************//**
 * Intent: To set the text value of the Document object to the provided value.
 * Pre: The variable textValue must have value.
 * Post: The function updates the title of the Document object with the provided value.
 * \param value
 *********************************************************************/
void Document::setText(const std::string& textValue)
{
	text = textValue;
}

/*****************************************************************//**
 * Intent: To assign the values of another Document object to the current object.
 * Pre: The object other must be valid.
 * Post: The function returns a reference to the current object.
 * \param other
 * \return
 *********************************************************************/
Document& Document::operator=(const Document& other)
{
	// if same direct return
	if (this != &other) {
		text = other.text;
	}
	return *this;
}
