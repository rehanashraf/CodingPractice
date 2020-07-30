//
//  reverseinteger.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/17/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*fGiven a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120*/

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <climits>

//#define MAX pow(2,31)

int reverse(int x)
{
    long int iReturnValue = 0;//, iDividingPower = 10, iMultiplyingPower = 1;
    bool bIsNegative = false;
    
    if (((x >= INT_MAX) || (x <= INT_MIN)))
    {
        iReturnValue = 0;
        return (int)iReturnValue;
    }
    
    if(x < 0)
    {
        bIsNegative = true;
        x = abs(x);
    }
    
    while(x)
    {
        iReturnValue = iReturnValue*10;
        iReturnValue = iReturnValue + (x%10);
        x = x / 10;
        //        power = power * 10;
    }
    
    if(iReturnValue > INT_MAX)
    {
        iReturnValue = 0;
        return (int)iReturnValue;
    }
    if(bIsNegative)
    {
        iReturnValue = -iReturnValue;
    }
    return (int)iReturnValue;
    
}

bool runReverse()
{
    bool bReturnValue = true;
    int x = 0;
    
    std::cout << INT_MAX << " " << INT_MIN << std::endl;
    
    x = 0;
    std::cout << x << " " << reverse(x) << std::endl;
    
    x = 10;
    std::cout << x << " " << reverse(x) << std::endl;
    
    x = -100;
    std::cout << x << " " << reverse(x) << std::endl;
    
    x = 123;
    std::cout << x << " " << reverse(x) << std::endl;
    
    x = -123;
    std::cout << x << " " << reverse(x) << std::endl;
    
    x = 1534236469;
    std::cout << x << " " << reverse(x) << std::endl;
    
    return bReturnValue;
}
