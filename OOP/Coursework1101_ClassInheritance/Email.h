/*****************************************************************//**
 * File: Email.h
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to define a class for Email that is derived from Document.
 *********************************************************************/
#pragma once
#include "Document.h"

class Email :public Document
{
private:
	std::string sender;
	std::string recipient;
	std::string title;

public:
	Email();

	// body of the email message should be stored in the inherited variable text
	Email(const std::string&, const std::string&, const std::string&, const std::string&);

	// accessor
	void setSender(const std::string&);
	void setRecipient(const std::string&);
	void setTitle(const std::string&);

	// mutator
	std::string getSender() const;
	std::string getRecipient() const;
	std::string getTitle() const;

	// assignment operator
	Email& operator=(const Email& other);
};
