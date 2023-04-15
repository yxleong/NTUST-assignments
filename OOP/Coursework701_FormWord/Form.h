/*****************************************************************//**
 * File : Form.h
 * Author : Leong Yah Xuan
 * Create Date : April 11, 2023
 * UPDATE Date : April 12, 2023
 * Description : This C++ program loads few words compose by given word.
 *********************************************************************/
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Form
{
private:
	// declare variables which are needed
	string word;
	string file;
	vector<string> foundWords;

public:
	void SetInputWord(string inputWord); // set input
	void ProcessInputWord(); // process input
	void SetFileName(string fileName); // set file name
	void Load_CompareWord(); // read-in data and compare
	void PrintFoundWords(); // print answers
};
