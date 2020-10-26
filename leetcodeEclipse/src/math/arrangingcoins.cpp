//
//  arrangingcoins.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/5/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

 Given n, find the total number of full staircase rows that can be formed.

 n is a non-negative integer and fits within the range of a 32-bit signed integer.

 Example 1:

 n = 5

 The coins can form the following rows:
 ¤
 ¤ ¤
 ¤ ¤

 Because the 3rd row is incomplete, we return 2.
 Example 2:

 n = 8

 The coins can form the following rows:
 ¤
 ¤ ¤
 ¤ ¤ ¤
 ¤ ¤

 Because the 4th row is incomplete, we return 3.
 */
#include <iostream>

#include <stdio.h>
#include <math.h>

bool runArrangeCoins();
int arrangeCoins(int n);

int arrangeCoins(int n) {
    int rv;
    long double forsqrt;
    
    forsqrt = ((long double)8 * (long double)n) + 1;
    
    rv = ((-1 + sqrt(forsqrt))/2);
    
    return rv;
}

bool runArrangeCoins()
{
    bool rv = true;
    
    std::cout << arrangeCoins(1) << std::endl;
    std::cout << arrangeCoins(2) << std::endl;
    std::cout << arrangeCoins(3) << std::endl;
    std::cout << arrangeCoins(1804289383) << std::endl;
    
    
    return rv;
}
