//
//  integertoroman.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/20/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

 Symbol       Value
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

 Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

 I can be placed before V (5) and X (10) to make 4 and 9.
 X can be placed before L (50) and C (100) to make 40 and 90.
 C can be placed before D (500) and M (1000) to make 400 and 900.
 Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.
 */

#include <stdio.h>
#include <string>
#include <iostream>

bool runIntToRoman(void);
std::string intToRoman(int num);

std::string intToRoman(int num) {
    std::string rv = "";
    
    if (num < 1)
        return rv;
    else if (num > 3999)
        return rv;
    
    while (num > 0)
    {
        if (num/1000)
        {
            num -= 1000;
            rv += 'M';

        }
        else if (num/900)
        {
            num -= 900;
            rv += 'C';
            rv += 'M';
        }
        else if (num/500)
        {
            num -= 500;
            rv += 'D';
        }
        else if (num/400)
        {
            num -= 400;
            rv += 'C';
            rv += 'D';
        }
        else if (num/100)
        {
            num -= 100;
            rv += 'C';
        }
        else if (num/90)
        {
            num -= 90;
            rv += 'X';
            rv += 'C';
        }
        else if (num/50)
        {
            num -= 50;
            rv += 'L';
        }
        else if (num/40)
        {
            num -= 40;
            rv += 'X';
            rv += 'L';
        }
        else if (num/10)
        {
            num -= 10;
            rv += 'X';
        }
        else if (num/9)
        {
            num -= 9;
            rv += 'I';
            rv += 'X';
        }
        else if (num/5)
        {
            num -= 5;
            rv += 'V';
        }
        else if (num/4)
        {
            num -= 4;
            rv += 'I';
            rv += 'V';
        }
        else
        {
            num -= 1;
            rv += 'I';
        }
    }
    return rv;
}

bool runIntToRoman(void)
{
    bool rv = true;
    int testvalue = 0;
    
    testvalue = 1699;
    std::cout << testvalue << " in Roman is " << intToRoman(testvalue);
    return rv;
}
