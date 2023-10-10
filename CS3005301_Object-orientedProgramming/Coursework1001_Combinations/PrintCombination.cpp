/*****************************************************************//**
 * File: PrintCombination.cpp
 * Author: Leong Yah Xuan
 * Create Date: May 10, 2023
 * Update Date: May 10, 2023
 * Description: This C++ program enumerates all combinations of C(n,r) by a recursive function.
 *********************************************************************/
#include "PrintCombination.h"

 /*****************************************************************//**
  * Intent: To generates combinations by the recursive callback itself.
  * Pre: The variables oriArr,choseArr,choiceNum,startIndex,endIndex,nowIndex must have value.
  * Post: The function generates all possible combinations.
  * \param oriArr
  * \param choseArr
  * \param choiceNum
  * \param startIndex
  * \param endIndex
  * \param nowIndex
  *********************************************************************/
void getCombination(int* oriArr, int* choseArr, int choiceNum, int startIndex, int endIndex, int nowIndex)
{
	// if combination elements number reach number for choice
	if (nowIndex == choiceNum)
	{
		// print out the generated combination
		for (int i = 0; i < choiceNum; i++)
		{
			std::cout << choseArr[i];

			// avoid the presentation error
			if (i != choiceNum - 1) {
				std::cout << " ";
			}
		}
		std::cout << std::endl;

		return; // to jump out this time of function
	}
	else // if haven't reach the number for choice
	{
		// loop for each element inside the original array, including the last element
		for (int index = startIndex; index <= endIndex; index++)
		{
			int numNeed = choiceNum - nowIndex;
			int numChoiceRemain = endIndex - index + 1;

			// check if the number is left enough for fill the combination
			if (numNeed <= numChoiceRemain)
			{
				// assign at choosing index with the value at now looping index in original array
				choseArr[nowIndex] = oriArr[index];

				// get the next possible combination element
				getCombination(oriArr, choseArr, choiceNum, index + 1, endIndex, nowIndex + 1);
			}
			else // if not enough
			{
				break; // direct jump out this loop to save time
			}
		}
	}
}

/*****************************************************************//**
  * Intent: To print combinations by calling function.
  * Pre: The variables oriArr,arrayNum,choiceNum must have value.
  * Post: The function prints all possible combinations.
 * \param oriArr
 * \param arrayNum
 * \param choiceNum
 *********************************************************************/
void PrintCombination(int* oriArr, int arrayNum, int choiceNum)
{
	// declare a result combination array with desired combination length
	int* choseArr = new int[choiceNum];

	// print all possible combination by calling function
	getCombination(oriArr, choseArr, choiceNum, 0, arrayNum - 1, 0);

	// release the memory allocated
	delete[] choseArr;
}

// 1
// 1 2
// 1 2 3
// 1 2 3 4 -> return

// 1 2 3
// 1 2 3 5 -> return

// 1 2 4
// 1 2 4 5 -> return

// 1 3
// 1 3 4
// 1 3 4 5 -> return

// 2
// 2 3
// 2 3 4
// 2 3 4 5 -> return

// 3 -> return 
// since no enough index
