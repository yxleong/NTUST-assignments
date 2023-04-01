/*****************************************************************//**
 * File : main.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 14, 2023
 * UPDATE Date : March 18, 2023
 * Description : This C++ program reads a list of numbers
					and outputs with two - column table
					sorted descending by the number's count value
 *********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

int main(void)
{
	// declare variable which is needed
	std::string line = "";

	// read whole string 'line'
	std::getline(std::cin, line);

	// create string stream from 'line'
	std::stringstream iss(line);

	// reusable variable, place this variable outside of the loop
	int input = 0, count = 0;
	std::vector<int> nums;
	std::vector<std::vector<int>> counter;

	// read one by one based on the string stream
	while (iss >> input) // read input as a int
	{
		nums.push_back(input); // put inside vector
	}

	// sort element of vector
	std::sort(nums.begin(), nums.end());

	// initialize prevNum to the first element in vector
	int prevNum = nums[0];

	for (int i = 0; i < nums.size(); i++) // loop until i = nums.size()
	{
		// check if element with current index in vector same with previous element
		if (nums[i] == prevNum) // if same
		{
			// increase the count
			count++; // since count initialize to be 0, need not worry redundant adding [0]
		}
		else // if not same
		{
			// push back the count and its num to counter
			counter.push_back({ prevNum, count });

			// count to be 1 since the element with current index is newly counted
			count = 1;

			// previous element = element with current index
			prevNum = nums[i];
		}
	}

	// since always push back the previous number when doing comparation
	// so need to remember to push back the last element and its count too
	counter.push_back({ nums.back(),count });

	// sort the nums in vector counter in decreasing order
	std::sort(counter.begin(), counter.end(), [](const std::vector<int>& num1, const std::vector<int>& num2) {
		return num1[0] > num2[0]; // if a[1]b[1] then will be storted by counter
		});

	// output in requirement format
	std::cout << "N\tcount" << std::endl; // \t : tab

	for (const auto& i : counter) // iterate over each element in counter
	{
		// output the table
		std::cout << i[0] << "\t" << i[1] << std::endl;
	}

	return 0;
}