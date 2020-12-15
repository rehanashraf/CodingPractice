/*
 * utility.h
 *
 *  Created on: Oct 24, 2020
 *      Author: rehanashraf
 */

#ifndef UTILITY_H_
#define UTILITY_H_

inline void swap(int *a, int *b)
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


#endif /* UTILITY_H_ */
