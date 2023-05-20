/*****************************************************************//**
 * File: File.h
 * Author: Leong Yah Xuan
 * Create Date: May 19, 2023
 * Update Date: May 20, 2023
 * Description: This C++ program is to define a class for File that is derived from Document.
 *********************************************************************/
#pragma once
#include "Document.h"

class File :public Document
{
private:
	std::string pathname;

public:
	File();
	File(const std::string&, const std::string&);

	void setPathname(const std::string&);	 // accessor
	std::string getPathname() const;		 // mutator

	File& operator=(const File&);			 // assignment operator 
};
