/*
 * utility.cpp
 *
 *  Created on: Oct 24, 2020
 *      Author: rehanashraf
 */

#include "utility.h"



// A utility function to swap two elements
inline void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

inline void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
