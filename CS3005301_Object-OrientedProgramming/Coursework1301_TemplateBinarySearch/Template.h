/*****************************************************************//**
 * File: Template.h
 * Author: Leong Yah Xuan
 * Create Date: May 30, 2023
 * Update Date: May 30, 2023
 * Description: This C++ program implements Binary Search using template in iterative and recursive versions.
 *********************************************************************/
#pragma once

template <typename T> // create template function
/*****************************************************************//**
 * Intent: To implement Binary Search with iterative method.
 * Pre: The variables a,first,last,key,found,location must have values.
 * Post: The function searchs the key by binary search iteratively.
 * \param a
 * \param first
 * \param last
 * \param key
 * \param found
 * \param location
 *********************************************************************/
void ItrBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	// mark the found to be false
	found = false;

	while (first <= last) {
		// set the middle index of array
		int mid = (first + last) / 2;

		// if found the key at middle index
		if (a[mid] == key) {
			location = mid;
			found = true;
			return; // direct break this function
		}
		else if (key <= a[mid]) { // if the key finding is smaller than now index data
			last = mid - 1; // next search front half array data
		}
		else { // if key finding is larger than now index data
			first = mid + 1; // next search for behind half array data
		}
	}
}

template <typename T> // to create template function
/*****************************************************************//**
 * Intent: To calculate the volume of a sphere with a given radius.
 * Pre: The variable radius must have a value and radius > 0.
 * Post: The function returns the volume of a sphere.
 * \param a
 * \param first
 * \param last
 * \param key
 * \param found
 * \param location
 *********************************************************************/
void RecBinarySearch(const T a[], int first, int last, T key, bool& found, int& location)
{
	if (first > last) { // if already find all the index
		found = false; // mark still not found
		return; // jump out this function
	}

	// set the middle index of array 
	int mid = (first + last) / 2;

	// if found the key at middle index
	if (a[mid] == key) {
		location = mid;
		found = true;
		return; // direct break this function
	}
	else if (key < a[mid]) { // if the key finding is smaller than now index data
		// call function to keep searching by a new last index
		RecBinarySearch(a, first, mid - 1, key, found, location); // next search front half array data
	}
	else { // if key finding is larger than now index data
		// call function to keep searching by a new first index
		RecBinarySearch(a, mid + 1, last, key, found, location); // next search for behind half array data
	}
}