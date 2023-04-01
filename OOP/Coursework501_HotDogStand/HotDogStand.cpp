/*****************************************************************//**
 * File : HotDogStand.cpp
 * Author : Leong Yah Xuan
 * Create Date : March 28, 2023
 * UPDATE Date : March 28, 2023
 * Description : This C++ program defines a class called HotDogStand
 *					to store and manage the hot dog stores.
 *********************************************************************/

#include <iostream>
#include "HotDogStand.h"

 // define variable which is needed
int HotDogStand::totalSellAmount = 0;

HotDogStand::HotDogStand()
{
	// construct the initialization
	standId = 0;
	hotDogSellAmount = 0;
	HotDogStand::totalSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id)
{
	// Construct a HotDogStand with the given ID
		// since standId has not been initialized to point to a valid memory location
		// cannot wrtie the code *standId = *id;
	standId = new char[strlen(id) + 1]; // need to allocate the memory first ; +1 since the \0
	strcpy_s(standId, strlen(id) + 1, id); // and then copy to it

	// set the sales volume to 0
	hotDogSellAmount = 0;
}

HotDogStand::HotDogStand(const char* id, int amount)
{
	// Construct a HotDogStand with the given ID
	standId = new char[strlen(id) + 1];
	strcpy_s(standId, strlen(id) + 1, id);

	// Construct a HotDogStand with the given sales volume
	hotDogSellAmount = amount;

	// construct the total as amount of all sales volumes
	HotDogStand::totalSellAmount += amount;
}

HotDogStand::~HotDogStand()
{
}

/**
* Intent : To increase the hot dog sales volume by 1.
* Pre : The function is called after a hot dog is sold.
* Post : The function increase the hot dog sales volume by 1.
*/
void HotDogStand::justSold()
{
	// increase hot dog sales volume of each stand by 1
	hotDogSellAmount += 1;

	// increase total hot dog sales volume of stands by 1
	HotDogStand::totalSellAmount += 1;
}

/**
* Intent : To print the ID and sales volume of the store separated by spaces.
* Pre : The variables standId,hotDogSellAmount must have a value and standId,hotDogSellAmount > 0.
* Post : The function prints the ID and sales volume of the store separated by spaces.
*/
void HotDogStand::print()
{
	std::cout << standId << " " << hotDogSellAmount << std::endl;
}

/**
* Intent : To return the sales volume of the store.
* Pre : The variable hotDogSellAmount must have a value and hotDogSellAmount > 0.
* Post : The function returns the sales volume of the store.
* \return
*/
int HotDogStand::thisStandSoldAmount()
{
	return hotDogSellAmount;
}

/**
* Intent : To return the total sales volume of all stores.
* Pre : The variable totalSellAmount must have a value and totalSellAmount > 0.
* Post : The function returns the total sales volume of all stores.
* \return
*/
int HotDogStand::allStandSoldAmount()
{
	return HotDogStand::totalSellAmount;
}
