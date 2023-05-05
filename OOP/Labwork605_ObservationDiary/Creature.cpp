/*****************************************************************//**
 * File : Creature.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 28, 2023
 * Update Date : May 3, 2023
 * Description : This C++ program generates diary observation logs for creatures.
 *********************************************************************/
#include "Creature.h"

 /**
 * Intent : To set the name of creature.
 * Pre : The variable name must have a value.
 * Post : The function returns the name of creature.
 * \param name
 */
Creature::Creature(std::string name) :creatureName(name)
{
	// update the record index based on the log record size
	currentRecordIndex = Diary::logRecord.size() - 1; // since count from 0 so need deduct 1
}

/**
* Intent : To set the name of creature and its base of each body part.
* Pre : The variables name,base must have a value.
* Post : The function returns the name of creature and its base of each body part.
* \param name
* \param base
*/
Creature::Creature(std::string name, Creature base) : creatureName(name)
{
	// map(variable, counter) already automatically counted
	for (const auto& bodyPart : base.bodyPartsCounter)
	{
		// assign to reference of object
		this->bodyPartsCounter[bodyPart.first] = bodyPart.second;
	}

	// update the record index based on the log record size
	currentRecordIndex = Diary::logRecord.size() - 1; // since count from 0 so need deduct 1
}

/**
* Intent : To obtain the specified body part of Creature.
* Pre : The variable bodyPart must have a value.
* Post : The function returns to the body part of Creature.
* \param bodyPart
* \return
*/
Creature& Creature::operator[](std::string bodyPart)
{
	// update the creature body part
	creatureBodyPart = bodyPart;

	// if bodyPart unfound = new body part
	if (bodyPartsCounter.find(bodyPart) == bodyPartsCounter.end())
	{
		// the default value for the number of body parts is 0
		bodyPartsCounter[bodyPart] = 0; // count as 0
	}

	// return to the body part counter map
	return *this;
}

/**
* Intent : To update the log after implement operator.
* Pre : The variables originalValue,changedValue must have a value.
* Post : The function sets the new log by updating the information of creature.
* \param originalValue
* \param changedValue
*/
void Creature::updateLog(int originalValue, int changedValue)
{
	std::stringstream ss;

	// assgin the string stream as format
	// "<name>'s <body_part>
	ss << creatureName << "'s " << creatureBodyPart;

	// judge the condition of using which operator
	if (originalValue == 0 && changedValue > 0)
	{
		// for Overload operator =
		ss << " appeared ";
	}
	else if (originalValue < changedValue)
	{
		// for Overload operator +=
		ss << " increased ";
	}
	else if (originalValue > changedValue)
	{
		// for Overload operator -=
		ss << " decreased ";
	}
	else // if (originalValue == changedValue)
	{
		return;
	}

	// continually assign the output behind
	// (<original_value> -> <changed_value>)
	ss << '(' << originalValue << " -> " << changedValue << ")." << std::endl;

	// update a new log for creature by string from stream
	Diary::setNewLog(creatureName, ss.str());
}

/**
* Intent : To assign a value to a body part in Creature.
* Pre : The variable changedValue must have a value and changedValue > 0.
* Post : The function returns the value of a body part in Creature.
* \param changedValue
*/
void Creature::operator=(int changedValue)
{
	// set the original value of body part of Creature
	int originalValue = bodyPartsCounter[creatureBodyPart];

	// assgin the new value for current value of body part of Creature
	bodyPartsCounter[creatureBodyPart] = changedValue;

	// call function to write the log
	updateLog(originalValue, bodyPartsCounter[creatureBodyPart]);
}

/**
* Intent : To increase the number of specified body parts in Creature.
* Pre : The variable number must have a value and number > 0.
* Post : The function returns the increased value of specified body part in Creature.
* \param number
*/
void Creature::operator+=(int number)
{
	// set the original value of body part of Creature
	int originalValue = bodyPartsCounter[creatureBodyPart];

	// increase the current value of body part of Creature by a number given
	bodyPartsCounter[creatureBodyPart] += number;

	// call function to write the log
	updateLog(originalValue, bodyPartsCounter[creatureBodyPart]);
}

/**
* Intent : To reduce the number of specified body parts in Creature.
* Pre : The variable number must have a value and number > 0.
* Post : The function returns the reduced value of specified body part in Creature.
* \param number
*/
void Creature::operator-=(int number)
{
	// set the original value of body part of Creature
	int originalValue = bodyPartsCounter[creatureBodyPart];

	// reduce the current value of body part of Creature by a number given
	bodyPartsCounter[creatureBodyPart] -= number;

	// call function to write the log
	updateLog(originalValue, bodyPartsCounter[creatureBodyPart]);
}

/**
* Intent : To prints the value of each body part of the organism.
* Pre : The variable bodyPartsCounter must have a value.
* Post : The function outputs the value of each body part of the organism.
*/
void Creature::PrintStatus() const
{
	// output as required format
	std::cout << creatureName << "'s status:" << std::endl;

	// loop all existed body part
	for (const auto& bodyPart : bodyPartsCounter)
	{
		// if body part number is count as 0
		if (bodyPart.second != 0)
		{
			// output the body part name and its number
			std::cout << bodyPart.first << " * " << bodyPart.second << std::endl;
		}
	}

	std::cout << std::endl;
}

/**
* Intent : To prints the log information of the creature on a Diary basis since it was collected.
* Pre : The object logRecord of variable creature must have a value.
* Post : The function outputs the log information of the creature.
*/
void Creature::PrintLog() const
{
	// output as required format
	std::cout << creatureName << "'s log:" << std::endl;

	// loop from current record index as a starting index for searching all records that day
	// current record index = date code
	// .................... = log lists in that day
	// until reach [log record size - 1]
	for (int i = currentRecordIndex; i < Diary::logRecord.size(); i++)
	{
		// output the date code of current date in that recorded log list
		std::cout << "Day " << Diary::logRecord[i].logDate << std::endl;

		// loop that day recorded log lists only
		for (LogRecord logList : Diary::logRecord[i].logLists)
		{
			if (logList.logRecordCreature == creatureName)
			{
				// output the information of required creature only
				std::cout << logList.logRecordInfo;
			}
		}
	}

	std::cout << std::endl;
}