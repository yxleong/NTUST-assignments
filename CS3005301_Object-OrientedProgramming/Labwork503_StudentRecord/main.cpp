/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : April 2, 2023
 * UPDATE Date : April 2, 2023
 * Description : This C++ program students at most 10 student data by structures.
 *********************************************************************/

#include <iostream>
#include <string>
#include <cstring>

#define MAX_RECORDS 10

typedef struct {
	char firstName[25];
	char lastName[30];
	char phone[15];
} StRec;

// declare variables which are needed
int recordCounter = 0;
StRec students[MAX_RECORDS];

/**
* Intent : To search a student which match all the datas recorded.
* Pre : The variable students of type StRec must be passed as a parameter with values.
* Post : The function returns a boolean value indicating whether the student record was found and updates index found.
* \param student
* \param index
* \return
*/
bool searchRecord(StRec student, int& index)
{
	for (int i = 0; i < recordCounter; i++)
	{
		// if the string of the datas match
		if (!strcmp(students[i].firstName, student.firstName) &&
			!strcmp(students[i].lastName, student.lastName) &&
			!strcmp(students[i].phone, student.phone))
		{
			// update the index parameter with the i of students
			index = i;

			// mark if is found
			return true;
		}
	}

	// if not found a match
	return false;
}

/**
* Intent : To insert the datas of a student after last student's datas.
* Pre : The variable students of type StRec must be passed as a parameter with values.
* Post : The function inserts a student if the datas of the student is valid.
* \param student
* \param index
*/
void insertRecord(StRec student, int index)
{
	if (recordCounter == MAX_RECORDS)
	{
		// if already reach 10 records 
		std::cout << "Insert Error" << std::endl;
		return;
	}

	if (searchRecord(student, index))
	{
		// if the record already exists
		std::cout << "Insert Error" << std::endl;
		return;
	}

	// insert the datas of student in students of current record index
	strncpy_s(students[recordCounter].firstName, student.firstName, strlen(student.firstName));
	strncpy_s(students[recordCounter].lastName, student.lastName, strlen(student.lastName));
	strncpy_s(students[recordCounter].phone, student.phone, strlen(student.phone));

	// increase the record index in students
	recordCounter++;
}

/**
* Intent : To delete the datas of a student which match all the datas recorded.
* Pre : The variable students of type StRec must be passed as a parameter with values.
* Post : The function returns a boolean value indicating whether the student record was found and deletes it.
* \param student
* \param index
* \return
*/
bool deleteRecord(StRec student, int index)
{
	// if datas is match
	if (searchRecord(student, index))
	{
		// cover the data of current index with data of next index
		// cover the data of next index by data of next next index
		// ...
		// until the datas of last second index
		for (int j = index; j < recordCounter - 1; j++)
		{
			students[j] = students[j + 1];
		}

		// delete the last datas in last index
		recordCounter--;

		// record that match found
		return true;
	}

	// if not found a match
	return false;
}

/**
* Intent : To print all three data of records and separate them by space.
* Pre : The variable students of type StRec must be passed as a parameter with values.
* Post : The function prints all three data of students.
*/
void printRecords()
{
	if (recordCounter == 0)
	{
		// if there are no records
		std::cout << "Print Error" << std::endl;
		return;
	}

	// if there got records
	for (int i = 0; i < recordCounter; i++)
	{
		// print them by space 
		std::cout << students[i].firstName << " " << students[i].lastName << " " << students[i].phone << std::endl;
	}
}

/**
* Intent : To check whether the input string is numeric or not.
* Pre : The variable str must have a value.
* Post : The function returns a boolean value indicating whether the input is numeric or not.
* \param str
* \return
*/
bool isNumeric(std::string str)
{
	// loop through each character in the input string
	for (char c : str)
	{
		// check if the character is a digit
		if (!isdigit(c))
		{
			// if not a digit
			return false;
		}
	}

	// if whole string is digit
	return true;
}

/**
* Intent : To check the input format accuracy.
* Pre : The variable student of type StRec must be passed as a parameter with values.
* Post : The function returns a boolean value indicating whether the input format is valid or not.
* \param student
* \return
*/
bool isValidInput(StRec student)
{
	// if the length of firstName or lastName or phone is too long
	if (strlen(student.firstName) > 25 ||
		strlen(student.lastName) > 30 ||
		strlen(student.phone) > 15 ||
		!isNumeric(student.phone)) // if phone is not a number
	{
		// mark not valid
		return false;
	}

	// firstName <= 25 letters
	// lastName <= 30 letters
	// phone <= 15 numbers
	// whole phone is numeric
	return true;
}

int main(void)
{
	// reusable variable, place this variable outside of the loop
	std::string command = "";

	// infinite loop until cin meets EOF
	while (std::cin >> command) // read input as a string
	{
		// declare variables which are needed
		StRec student;
		int index = 0;

		// check which the command is inputted
		if (command == "insert")
		{
			// read inputs as string
			std::cin >> student.firstName >> student.lastName >> student.phone;

			// check input format accuracy
			if (!isValidInput(student))
			{
				// if invalid 
				std::cout << "Input Error" << std::endl;
				// and re-enter a command
			}
			else
			{
				// call function related to command
				insertRecord(student, index);
			}
		}
		else if (command == "delete")
		{
			// read inputs as string
			std::cin >> student.firstName >> student.lastName >> student.phone;

			// check input format accuracy
			if (!isValidInput(student))
			{
				// if invalid 
				std::cout << "Input Error" << std::endl;
				// and re-enter a command
			}
			else
			{
				// call function related to command
				if (!deleteRecord(student, index))
				{
					// if the record does not exist
					std::cout << "Delete Error" << std::endl;
				}
			}
		}
		else if (command == "search")
		{
			// read inputs as string
			std::cin >> student.firstName >> student.lastName >> student.phone;

			// check input format accuracy
			if (!isValidInput(student))
			{
				// if invalid 
				std::cout << "Input Error" << std::endl;
				// and re-enter a command
			}
			else
			{
				// call function related to command
				if (searchRecord(student, index))
				{
					// print which index the record is in
					std::cout << index << std::endl;
				}
				else // if the record does not exist
				{
					std::cout << "Search Error" << std::endl;
				}
			}
		}
		else if (command == "print")
		{
			// call function related to command
			printRecords();
		}
		else
		{
			// if the string that inputted was not one of the four commands
			std::cout << "Input Error" << std::endl;
			// and re-enter a command
		}
	}

	return 0;
}