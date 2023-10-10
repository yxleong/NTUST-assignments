/*****************************************************************//**
 * File: Email.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to define a class for Email that is derived from Document.
 *********************************************************************/
#include "Email.h"

 /*****************************************************************//**
 * Intent: To initialize an Email object with empty values for sender, recipient, and title.
 * Pre: The variables sender,recipient,title must be well-declared.
 * Post: The function initializes an Email object with empty values.
 * \param body
 * \param sender
 * \param recipient
 * \param title
 *********************************************************************/
Email::Email() :sender(""), recipient(""), title("") {};

/*****************************************************************//**
 * Intent: To initialize an Email object with the provided body, sender, recipient, and title.
 * Pre: The variables body,sender,recipient,title must have value.
 * Post: The function initializes an Email object with body, sender, recipient, and title.
 * \param body
 * \param sender
 * \param recipient
 * \param title
 *********************************************************************/
Email::Email(const std::string& body, const std::string& sender,
	const std::string& recipient, const std::string& title) :
	sender(sender), recipient(recipient), title(title)
{
	setText(body);
}

/*****************************************************************//**
 * Intent: To set the sender of the Email object to the provided value.
 * Pre: The variable newSender must have value.
 * Post: The function updates the sender of the Email object with the provided value.
 * \param newSender
 *********************************************************************/
void Email::setSender(const std::string& newSender)
{
	sender = newSender;
}

/*****************************************************************//**
 * Intent: To set the recipient of the Email object to the provided value.
 * Pre: The variable newRecipient must have value.
 * Post: The function updates the recipient of the Email object with the provided value.
 * \param newRecipient
 *********************************************************************/
void Email::setRecipient(const std::string& newRecipient)
{
	recipient = newRecipient;
}

/*****************************************************************//**
 * Intent: To set the title of the Email object to the provided value.
 * Pre: The variable newTitle must have value.
 * Post: The function updates the title of the Email object with the provided value.
 * \param newTitle
 *********************************************************************/
void Email::setTitle(const std::string& newTitle)
{
	title = newTitle;
}

/*****************************************************************//**
 * Intent: To retrieve the sender of the Email object.
 * Pre: The variable sender must be well-declared.
 * Post: The function returns the current sender of the Email object.
 * \return
 *********************************************************************/
std::string Email::getSender() const
{
	return sender;
}

/*****************************************************************//**
 * Intent: To retrieve the recipient of the Email object.
 * Pre: The variable recipient must be well-declared.
 * Post: The function returns the current recipient of the Email object.
 * \return
 *********************************************************************/
std::string Email::getRecipient() const
{
	return recipient;
}

/*****************************************************************//**
 * Intent: To retrieve the title of the Email object.
 * Pre: The variable title must be well-declared.
 * Post: The function returns the current title of the Email object.
 * \return
 *********************************************************************/
std::string Email::getTitle() const
{
	return title;
}

/*****************************************************************//**
 * Intent: To assign the values of another Email object to the current object.
 * Pre: The object other must be valid.
 * Post: The function returns a reference to the current object.
 * \param other
 * \return
 *********************************************************************/
Email& Email::operator=(const Email& other)
{
	// if same direct return
	if (this != &other) {
		setText(other.getText());
		sender = other.sender;
		recipient = other.recipient;
		title = other.title;
	}
	return *this;
}
