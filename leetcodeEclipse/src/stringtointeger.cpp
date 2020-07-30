//
//  stringtointeger.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/18/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//


/*
 Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
 */

#include <iostream>
#include <string>
#include <climits>

int myAtoi(std::string str)
{
    long int liReturnVal = 0;
    size_t sizeofstring = str.length();
    bool bIsNegative = false, bAlreadySigned = false, bAlreadyFound = false;
    
    if(sizeofstring == 0)
    {
        return 0;
    }
    
    for(int i = 0; i < sizeofstring; i++)
    {
        if(str[i] == ' ')
        {
            if(bAlreadyFound || bAlreadySigned)
            {
                break;
            }
            continue;
        }
        else if(str[i] == '-')
        {
            if(bAlreadyFound)
            {
                break;
            }
            else if(bAlreadySigned)
            {
                liReturnVal = 0;
                return liReturnVal;
            }

            bIsNegative = true;
            bAlreadySigned = true;
        }
        else if(str[i] == '+')
        {
            if(bAlreadyFound)
            {
                break;
            }
            else if(bAlreadySigned)
            {
                liReturnVal = 0;
                return liReturnVal;
            }

            bIsNegative = false;
            bAlreadySigned = true;
        }
        else if ((str[i] >= 48) && (str[i] <= 57))
        {
            liReturnVal = liReturnVal * 10;
            liReturnVal = liReturnVal + (str[i] - 48);
            bAlreadyFound = true;
            
            if(liReturnVal > INT_MAX)
            {
                return bIsNegative? INT_MIN : INT_MAX;
            }
            //            power = power * 10;
        }
        else
        {
            break;
        }
    }
    
    if(bIsNegative)
    {
        liReturnVal = -1 * liReturnVal;
    }
    
    return (int)liReturnVal;
}

bool runMyAtoi()
{
    bool bReturbVal = true;
    
    std::string str = "";
    
    str = "42";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "   -42";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "   -4152";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "410093 with words";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "words and 987";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "-91283472332";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "2147483648";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "-2147483648";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "2147483647";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "20000000000000000000";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    str = "-200-";
    std::cout << str << " " << myAtoi(str) << std::endl;
    
    return bReturbVal;
}
