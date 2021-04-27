/*
 * utility.h
 *
 *  Created on: Oct 24, 2020
 *      Author: rehanashraf
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>
#include <vector>
using namespace std;

#define LOG_TAG    ( strrchr( __FILE__, '/' ) ? strrchr( __FILE__, '/' ) + 1 : __FILE__ )
#define FILENAME    (strrchr(LOG_TAG,'.') = '\0')
template<typename T>
inline void swap(T &x, T &y) {
    T tmp = x;
    x = y; y = tmp;
}

template<typename T>
void printVector(vector<T> &list) {
    for (auto &item : list) {
    cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void print2DVector(vector<vector<T>> &list) {
    for (auto &item : list) {
        printVector(item);
    }
}

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
