/*****************************************************************//**
 * File : Diary.h
 * Author : Leong Yah Xuan
 * Create Date : April 28, 2023
 * Update Date : May 3, 2023
 * Description : This C++ program generates diary observation logs for creatures.
 *********************************************************************/
#pragma once
#include <string>
#include <vector>

struct LogRecord
{
	std::string logRecordCreature;
	std::string logRecordInfo;
};

struct DiaryLog
{
	std::string logDate;
	std::vector<LogRecord> logLists;
};

class Diary
{
public:
	// static for declaration only -> does not allocate any memory
	static std::vector<DiaryLog> logRecord;
	static std::string dateCode;

	static void setNewLog(std::string name, std::string info);

	// Set the current date code(A string of words.May not all necessarily be numbers.)
	static void NewDay(std::string day);
};
