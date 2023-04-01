/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 9, 2023
 * UPDATE Date : March 17, 2023
 * Description : This C++ program makes sure the result remains clean
 *					by following the format.
 *********************************************************************/

#define SIZE 100

#include <iostream>
#include <string>

int main(void)
{
	// reusable variables, place these variable outside of the loop
	int num = 0;

	// infinite loop until cin meets EOF
	while (std::cin >> num) // read input as a int
	{
		// declare variables which are needed
		std::string name[SIZE] = {};
		std::string salary[SIZE] = {}, bonus[SIZE] = {};

		for (int i = 0; i < num; i++) // loop until i = num
		{
			// read input as string
			std::cin >> name[i] >> salary[i] >> bonus[i];
		}

		// initialize length to the first length of data
		size_t maxName = name[0].length();
		size_t maxSalary = salary[0].length();
		size_t maxBonus = bonus[0].length();

		for (int i = 1; i < num; i++) // loop from 1 until i = num, since index 0 assigned
		{
			// swap if length is not the max
			if (name[i].length() > maxName) {
				maxName = name[i].length();
			}
			//else continue;
			/* cannot use else or will skip to i + 1, the below if will not run at i */

			if (salary[i].length() > maxSalary) {
				maxSalary = salary[i].length();
			}
			//else continue;

			if (bonus[i].length() > maxBonus) {
				maxBonus = bonus[i].length();
			}
			//else continue;
		}

		// insert space until match the rules
		for (int i = 0; i < num; i++) // loop until i = num
		{
			// std::string str(int length, char ch);
			std::string spaceName(maxName - name[i].length(), ' ');
			name[i] = spaceName + name[i]; // combine string

			// indented by two additional spaces
			std::string spaceSalary(maxSalary - salary[i].length() + 2, ' ');
			salary[i] = spaceSalary + salary[i];

			std::string spaceBonus(maxBonus - bonus[i].length() + 2, ' ');
			bonus[i] = spaceBonus + bonus[i];

			// output in certain format
			std::cout << name[i] << "|" << salary[i] << "|" << bonus[i] << std::endl;
		}
	}

	return 0;
}