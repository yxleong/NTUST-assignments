/*****************************************************************//**
 * File: main.cpp
 * Author: Leong Yah Xuan
 * Create Date: June 6, 2023
 * Update Date: June 9, 2023
 * Description: This C++ program eliminates the duplicate names by using the set template class.
 *********************************************************************/
#include <iostream>
#include <set>
#include <fstream>
#include <string>

int main(void) {

	// open file
	std::ifstream inFile("name.txt");

	// check if file is correctly opened
	if (!inFile.is_open()) {
		// if not, stop system
		return 0;
	}

	// declare the variables needed
	std::set<std::string> nameList;
	std::string names = "";

	// read file content line by line
	while (std::getline(inFile, names)) {
		// insert content in line to set
		nameList.insert(names);
		// without duplicate content
	}

	// close the file
	inFile.close();

	// loop the content in set
	for (auto& name : nameList) {
		// output the content in set
		std::cout << name << std::endl;
	}

	return 0;
}
