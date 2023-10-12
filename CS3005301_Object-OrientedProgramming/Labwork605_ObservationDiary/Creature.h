/*****************************************************************//**
 * File : Creature.h
 * Author : Leong Yah Xuan
 * Create Date : April 28, 2023
 * Update Date : May 3, 2023
 * Description : This C++ program generates diary observation logs for creatures.
 *********************************************************************/
#pragma once
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include "Diary.h"

class Creature
{
private:
	std::string creatureName;
	std::string creatureBodyPart;
	std::map<std::string, int> bodyPartsCounter;
	int currentRecordIndex;

	void updateLog(int, int);
public:
	Creature(std::string name); // Contains a creature named name
	Creature(std::string name, Creature base); // A creature that contains the same information as the base of each body part

	Creature& operator [](std::string bodyPart); // Obtain the specified body part of Creature
	void operator =(int changedValue); // Assign a value to a body part in Creature
	void operator +=(int number); // Increase the number of specified body parts in Creature
	void operator -=(int number); // Reduce the number of specified body parts in Creature

	void PrintStatus() const; // Prints the value of each body part of the organism
	void PrintLog() const; // Prints the log information of the creature on a Diary basis since it was collected
};