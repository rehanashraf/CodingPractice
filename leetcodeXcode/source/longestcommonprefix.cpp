//
//  longestcommonprefix.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/20/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".

 Example 1:

 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:

 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:

 All given inputs are in lowercase letters a-z.
 */


#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "print.h"

std::string longestCommonPrefix(std::vector<std::string>& strs);
bool runLongestCommonPrefix();

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string rv;
    size_t listSize = 0, stringSize = 0, rvSize = 0;
    bool keepRunning = true;
    char checkChar = '\0';
    
    listSize = strs.size();
    rv = "";
    
    if(listSize == 0)
    {
        return rv;
    }
    
    while(keepRunning)
    {
        for(int i = 0 ; i < listSize; i++)
        {
            stringSize = strs[i].length();
            if(stringSize == 0)
            {
                rv = "";
                return rv;
            }
            if(i == 0)
            {
                checkChar = strs[i][rvSize];
                rvSize++;
            }
            if (rvSize)
            {

                if (rvSize <= stringSize)
                {
                    if(strs[i][rvSize - 1] == checkChar)
                    {
                        continue;
                    }
                    else
                    {
                        return rv;
                    }
                }
                else
                {
                    return rv;
                }

            }
        }
        rv = rv + checkChar;
    }
    
    return rv;
}

bool runLongestCommonPrefix()
{
    bool rv = true;
    
    std::vector<std::string> input = {"flower","flow","flowight"};
    
    printVector(input);
    std::cout << longestCommonPrefix(input) << std::endl;
    return rv;
}
