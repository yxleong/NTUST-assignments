/*****************************************************************//**
 * File : NumberGame.h
 * Author : Leong Yah Xuan
 * Create Date : April 29, 2023
 * Update Date : May 2, 2023
 * Description : This C++ program implements a designed number game.
 *********************************************************************/
#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

class NumberGame
{
private:
	std::string integer;
	std::string fileName;
	std::vector<int> legitimateNumber;
	std::set<int> products; // set to avoid duplicate element
public:
	void SetInput(int); // set the given integer A
	void ProcessInput(); // splitting the integer A into several digits
	void SetFileName(std::string); // set the file name of the file where list S is located
	void LoadNumberList(); // read list S from the file
	void PrintAllValid(); // print all the valid numbers in S ascendingly
	void Reset(); // reset all variables
};
