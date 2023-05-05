/*****************************************************************//**
 * File : Diary.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 28, 2023
 * Update Date : May 3, 2023
 * Description : This C++ program generates diary observation logs for creatures.
 *********************************************************************/
#include "Diary.h"

 // defined outside the class Diary to allocate memory for static variables
std::string Diary::dateCode = "";
std::vector<DiaryLog> Diary::logRecord = {};

/**
* Intent : To set the current date code.
* Pre : The variable day must have a value.
* Post : The function sets the current date code to log recoder.
* \param day
*/
void Diary::NewDay(std::string day)
{
	// assign the current date code
	Diary::dateCode = day;

	// add current day to log recoder
	DiaryLog newDay = { day,{} }; // create a new log for a new date code
	logRecord.push_back(newDay); // insert the new day log
}

/**
* Intent : To set a new log based on the given day into log recoder.
* Pre : The variables name,info have a value.
* Post : The function sets the information of creature based on date code in log recoder.
* \param name
* \param info
*/
void Diary::setNewLog(std::string name, std::string info)
{
	// assign the new log including creature and its information
	LogRecord newLog = { name,info };

	// insert the newest log to the diary log record
	logRecord.back().logLists.push_back({ newLog });
	// access to the newest/last log record and
	// add new log information as log list into that log record
}