/*
 * happynumber.cpp
 *
 *  Created on: Apr 6, 2020
 *      Author: rehanashraf
 *
 *      Write an algorithm to determine if a number n is "happy".
 *      A happy number is a number defined by the following process: Starting with any positive integer, replace the number by
 *      the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops
 *      endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *      Return True if n is a happy number, and False if not.
 *      Example:
 *      Input: 19
 *      Output: true
 *      Explanation:
 *      1^2 + 9^2 = 82
 *      8^2 + 2^2 = 68
 *      6^2 + 8^2 = 100
 *      1^2 + 0^2 + 0^2 = 1
 */

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int getSquaredSum(int number);
bool runIsHappy(void);

bool isHappy(int n)
{
	bool rv  = false;
	std::vector<int> list;


	while(!rv)
	{
		n = getSquaredSum(n);
		if (n == 1)
		{
			rv = true;
			return rv;
		}
		if(std::find(list.begin(), list.end(), n) != list.end())
		{
			rv = false;
			return rv;
		}
		list.push_back(n);
	}
	return rv;
}

int getSquaredSum(int number)
{
	int rv = 0;
	while(number)
	{
		rv = rv + pow(number % 10,2);
		number = number/10;
	}
	return rv;
}

bool runIsHappy(void)
{
	bool rv = true;
	for(int i = 1; i < 100; i++)
	{
		std::cout << i << " square is " << getSquaredSum(i) << " " << isHappy(i) <<std::endl;
	}
	return rv;
}
