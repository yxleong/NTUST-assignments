/*****************************************************************//**
 * File: hiddenWord.cpp
 * Author: Leong Yah Xuan
 * Create Date: November 28, 2023
 * Update Date: December 3, 2023
 * Description: This program is to perform insertion sort and selection sort on the integer array, while simultaneously rearranging the character array accordingly.
 *********************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#define N 200

/**
 * Intent: To perform insertion sort on an integer array while rearranging a character array accordingly.
 * Pre:The input arrays intArr and charArr must be valid arrays of size arrSize.
 * Post: The function returns the number of steps taken until the character order in charArr matches the specified order in the string word.
 * \param intArr
 * \param charArr
 * \param arrSize
 * \param word
 * \param wordFound
 * \return 
 */
int insertionSort(int intArr[], char charArr[], int arrSize, const std::string& word, bool& wordFound) {
    
    // step 1: repeat steps 2 to 5 for i = 1 to arrSize - 1
    for (int i = 1; i < arrSize - 1; i++) {

        // step 2: set temp = arr[i]
        int intTemp = intArr[i];
        char charTemp = charArr[i];

        // step 3: set j = i - 1
        int j = i - 1;

        // step 4: repeat while temp < arr[j]
        while (intTemp < intArr[j]) {

            // set arr[j+1] = arr[j]
            intArr[j + 1] = intArr[j];
            charArr[j + 1] = charArr[j];

            // set j = j - 1
            j--;
        }

        // step 5: set arr[j+1] = temp
        intArr[j + 1] = intTemp;
        charArr[j + 1] = charTemp;

        // step 6: exit

        bool isWordFound = true;
        for (int k = 0; k < arrSize; ++k) {
            if (charArr[k] != word[k]) {
                isWordFound = false;
                break;  // sort next element
            }
        }

        if (isWordFound) {
            wordFound = true;
            return i + 1;   // step number
        }
    }

    return 0;   // if word not found
}

/**
 * Intent: To perform selection sort on an integer array while rearranging a character array accordingly.
 * Pre: The input arrays intArr and charArr must be valid arrays of size arrSize.
 * Post: The function returns the number of steps taken until the character order in charArr matches the specified order in the string word.
 * \param intArr
 * \param charArr
 * \param arrSize
 * \param word
 * \param wordFound
 * \return 
 */
int selectionSort(int intArr[], char charArr[], int arrSize, const std::string& word, bool& wordFound) {
    
    int step = 0;

    // step 1: repeat steps 2 and 3 for i = 0 to arrSize - 1
    for (int i = 0; i < arrSize - 1; i++) {

        // step 2: find smallest
        // step 2.1: initialize -> set small = arr[i]
        int minIntArr = intArr[i];
        int minCharArr = intArr[i];
            
        // step 2.2: initialize -> set pos = i
        int minIndex = i;

        // step 2.3: repeat for j = i + 1 to arrSize - 1
        for (int j = i + 1; j <= arrSize - 1; j++) {

            // if small > arr[j]
            if (minIntArr > intArr[j]) {
                
                // set small = arr[j]
                minIntArr = intArr[j];
                minCharArr = charArr[j];

                // set pos = j
                minIndex = j;
            }
        }

        // step 3: swap arr[i] with arr[pos]
        std::swap(intArr[i], intArr[minIndex]);
        std::swap(charArr[i], charArr[minIndex]);

        // step 4: exit

        bool isWordFound = true;
        for (int k = 0; k < arrSize; ++k) {
            if (charArr[k] != word[k]) {
                isWordFound = false;
                break;  // sort next element
            }
        }

        // to make sure it is the first wordFound
        if (isWordFound && !wordFound) {
            wordFound = true;
            step = i + 1;
        }
    }

    // sort to the end to get the rearrangged the characters
    return step;    // return to the word found step
}

int main(void) {

    // declare necessary variables
    std::string word = "";
    std::string input = "";

    int num = 0; 
    int intArray[N] = {};
    int intArrayCopy[N] = {};

    char ch = 0;
    char charArray[N] = {};
    char charArrayCopy[N] = {};

    int arraySize = 0;

    int insertionSortStep = 0;
    int selectionSortStep = 0; 
    bool wordFoundInsertion = false;
    bool wordFoundSelection = false;

// read input:
    // The first line contains a word
    std::getline(std::cin, word);

    // The second line contains a list of integers separated by space
    std::getline(std::cin, input);
    std::istringstream iss(input);
    while (iss >> num) {
        intArray[arraySize++] = num;
    }

    // The third line contains a list of characters separated by space
    arraySize = 0;
    while (std::cin >> ch) {
        charArray[arraySize++] = ch;
    }

    // create copies of the original arrays to get the sorted results respectively
    std::copy(std::begin(intArray), std::end(intArray), std::begin(intArrayCopy));
    std::copy(std::begin(charArray), std::end(charArray), std::begin(charArrayCopy));

    // call function to sort the intArray
    insertionSortStep = insertionSort(intArrayCopy, charArrayCopy, arraySize, word, wordFoundInsertion);
    selectionSortStep = selectionSort(intArray, charArray, arraySize, word, wordFoundSelection);

// handle output format:
    // Whether the given word is found during sorting process, and the step at which it was found.
    if (!wordFoundInsertion && !wordFoundSelection) {
        std::cout << "Word not found." << std::endl;
    }
    else {
        if (wordFoundInsertion) {
            std::cout << "Word found in insertion sort step " << insertionSortStep;
            if (wordFoundSelection) {
                std::cout << " and selection sort step " << selectionSortStep << "." << std::endl;
            }
            else {
                std::cout << "." << std::endl;
            }
        } else if(wordFoundSelection) {
            std::cout << "Word found in selection sort step " << selectionSortStep << "." << std::endl;
        }
    }

    // A word that is the result of rearranging the characters after the sorting is completed.
    for (int i = 0; i < arraySize; ++i) {
        std::cout << charArray[i];  
        // implemented by the selection sort which is passed by reference as a pointer
    }

	return 0;
}
