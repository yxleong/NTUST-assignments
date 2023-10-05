/*****************************************************************//**
 * File: taxiLoadingOrder.cpp
 * Author: Leong Yah Xuan
 * Create Date: October 2, 2023
 * Update Date: October 3, 2023
 * Description: This program is to handle taxi loading order.
 *********************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#define MAX 200
#define NUM 100

int main(void) {

	// declare the variables needed
	std::string input = "";
	int weight = 0;
	int weigthArr[NUM] = { 0 }, num = 0;
	int taxi[NUM][NUM] = { {0} };
	int taxiIndex = 0, numInTaxi = 0;
	int totalWeight = 0;

	// read the line of input
	std::getline(std::cin, input);
	std::istringstream iss(input);

	// add weight to array
	while (iss >> weight) {
		weigthArr[num++] = weight;
	}

	// get on taxi
	for (int i = 0; i < num; i++) {

		// for taxi above 200kg
		if (totalWeight + weigthArr[i] > 200) {		// if exceed
			totalWeight = 0;	// clear
			taxiIndex++;		// next taxi
			numInTaxi = 0;		// reset num of ppl in taxi
		}

		// add the suitable weight to specific taxi
		taxi[taxiIndex][numInTaxi] = weigthArr[i];
		numInTaxi++;					// count the ppl in taxi
		totalWeight += weigthArr[i];	// record weight in taxi
	}

	// output the number of taxi
	std::cout << taxiIndex + 1 << std::endl;

	// output the order of ppl get down from taxi
	for (int i = taxiIndex; i >= 0; i--) {									// start from the last taxi
		for (int j = 0; j < sizeof(taxi[i]) / sizeof(taxi[i][j]); j++) {	// start from first ppl in taxi
			// handle the empty element in array
			if (taxi[i][j] != 0) {
				// handle the format of output
				if (i == taxiIndex && j == 0) {	// for the first element of output
					std::cout << taxi[i][j];
				}
				else {
					std::cout << " " << taxi[i][j];
				}
			}	
		}
	}

	return 0;
}