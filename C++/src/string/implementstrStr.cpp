//
//  implementstrStr.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/6/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 mplement strStr().

 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 Example 1:

 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:

 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:

 What should we return when needle is an empty string? This is a great question to ask during an interview.

 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

#include <string>
#include <iostream>

bool runStr();
int strStr(std::string haystack, std::string needle);

int strStr(std::string haystack, std::string needle) {
    int rv = -1;
    size_t loopsize, lengthhaystack, lenghthneedle;
    
    lenghthneedle = lengthhaystack = 0;
    
    lengthhaystack = haystack.length();
    lenghthneedle = needle.length();
    
    if((!lengthhaystack && !lenghthneedle) || (!lenghthneedle))
    {
        rv = 0;
        return rv;
    }

    if (lengthhaystack > lenghthneedle)
        loopsize = lengthhaystack - lenghthneedle;
    else if (lengthhaystack == lenghthneedle)
        loopsize = 1;
    else
        return rv;
    
    for (uint8_t i = 0; i <= loopsize; i++)
    {
        if (haystack[i] == needle[0])
        {
            rv = i;
            for(int j = 1; j < lenghthneedle; j++)
            {
                if (haystack[i+j] != needle[j])
                {
                    rv = - 1;
                    break;;
                }
            }
            if (rv >= 0)
                return rv;
        }
    }
    
    
    return rv;
}

bool runStr()
{
    bool rv = true;
    
    std::string hay, ned;
    
    hay = "mississippi";
    ned = "pi";
    std::cout << hay << " " << ned << " " << strStr(hay,ned) << std::endl;
    
    hay = "hello";
    ned = "ll";
    std::cout << hay << " " << ned << " " << strStr(hay,ned) << std::endl;
    
    return rv;
}
