/*
 * utility.h
 *
 *  Created on: Oct 24, 2020
 *      Author: rehanashraf
 */

#ifndef UTILITY_H_
#define UTILITY_H_

typedef enum errors{
    ERROR_OK = 0,
    ERROR_GENERIC = -1,
    ERROR_NULL_POINTER = -2,
    ERROR_NOT_ENOUGH_MEMORY = -3,
    ERROR_OUT_OF_BOUNDS = -4,
    ERROR_WRONG_SIZE = -5,
    ERROR_BAD_PARAMETER = -6,
}errors_e;

inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//inline void swap(int a, int b) {
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
//}


#endif /* UTILITY_H_ */
