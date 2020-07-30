//
//  lettercombinationofphone.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/31/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
 Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 
 Input: "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include "print.h"
using namespace std;

std::vector<std::string> letterCombinations(std::string digits);
bool runLetterCombinations();
long int getTotalCombinations(std::string& data);

std::vector<std::string> data{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

std::vector<std::string> letterCombinations(std::string digits)
{
    std::vector<std::string> rv;
    queue<std::string> qString;
    std::string subString;
    std::size_t stringSize = 0;
    std::size_t loopSize = 0;
    char ch;
    
    stringSize = digits.length();
    if(stringSize == 0)
    {
        return rv;
    }
    
    for(int i = 0; i < digits.length(); i++)
    {
        if((digits[i] == '0') || (digits[i] == '1'))
        {
            return rv;
        }
    }
    qString.push("");
    
    while(!qString.empty())
    {
        subString = qString.front();
        qString.pop();
        
        if(subString.length() == stringSize)
        {
            rv.push_back(subString);
        }
        else
        {
            loopSize = data[digits[subString.length()] - 50].length();
            for(int i = 0; i < loopSize; i++)
            {
                ch = data[digits[subString.length()] - 50][i];
                qString.push(subString + ch);
            }
        }
    }
    
    //    loopSize = getTotalCombinations(digits);
    
    
    return rv;
}

long int getTotalCombinations(std::string& data)
{
    long int rv = 1;
    size_t stringSize = data.length();
    
    if(stringSize == 0)
    {
        return 0;
    }
    
    for(int i = 0; i < stringSize; i++)
    {
        switch(data[i])
        {
            case'2':
                rv *= 3;
                break;
            case'3':
                rv *= 3;
                break;
            case'4':
                rv *= 3;
                break;
            case'5':
                rv *= 3;
                break;
            case'6':
                rv *= 3;
                break;
            case'7':
                rv *= 4;
                break;
            case'8':
                rv *= 3;
                break;
            case'9':
                rv *= 4;
                break;
            default:
                break;
        }
    }
    
    return rv;
}

bool runLetterCombinations()
{
    bool rv = false;
    std::string data = "";
    
    std::vector<std::string> result;
    result =letterCombinations(data);
    printVector(result);
        
    return rv;
}
  
