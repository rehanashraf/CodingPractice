//
//  uglynumber2.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/5/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
 /*
  Write a program to find the n-th ugly number.

  Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

  Example:

  Input: n = 10
  Output: 12
  Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
  Note:

  1 is typically treated as an ugly number.
  n does not exceed 1690.
  */

#include <stdio.h>
#include <limits.h>

#include <iostream>

#include "macros.h"

bool runNthUglyNumber();
int nthUglyNumber(int n);


int nthUglyNumber(int n) {
    int rv, count;
    rv = 0;
    count = 1;
    
    if (n == 1)
        return 1;
    for (long int i = 2; i < INT_MAX; i++)
    {
        if((i%2 == 0) || (i%3 == 0) || (i%5 == 0))
        {
            count++;
            std::cout << i << " " ;
            
            if (count == n)
            {
                rv = (int)i;
                return rv;
            }
        }
    }
    return rv;
}

bool runNthUglyNumber()
{
    bool rv = true;
    std::cout << nthUglyNumber(20) << std::endl;
    MIN(10,11);
    MAX(12,13);
    return rv;
}
