//
//  romantointeger.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/20/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
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
Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: "III"
Output: 3
Example 2:

Input: "IV"
Output: 4
Example 3:

Input: "IX"
Output: 9
Example 4:

Input: "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.
Example 5:

Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */
#include <stdio.h>
#include <string>
#include <iostream>

int romanToInt(std::string s)
{
    int total, current, previous;
//    char ch;
    
    size_t stringSize = s.length();
    total = current = previous = 0;
    
    for(int i = 0; i < stringSize; i++)
    {
        switch (s[i])
        {
            case 'I':
                current = 1;
                break;
            case 'V':
                current = 5;
                break;
            case 'X':
                current = 10;
                break;
            case 'L':
                current = 50;
                break;
            case 'C':
                current = 100;
                break;
            case 'D':
                current = 500;
                break;
            case 'M':
                current = 1000;
                break;
            default:
                current = 0;
                break;
        }
        if(current > previous)
        {
            total = total + current - 2*previous;
        }
        else
        {
            total = total + current;
        }
        previous = current;
    }
    return total;
}

bool runRomanToInt()
{
    bool rv = true;
    
    std::string input = "III";
    std::cout << input << " = " << romanToInt(input) << std::endl;
    
    input = "IV";
    std::cout << input << " = " << romanToInt(input) << std::endl;
    
    input = "IX";
    std::cout << input << " = " << romanToInt(input) << std::endl;
    
    input = "LVIII";
    std::cout << input << " = " << romanToInt(input) << std::endl;

    input = "MCMXCIV";
    std::cout << input << " = " << romanToInt(input) << std::endl;
    
    return rv;
}
