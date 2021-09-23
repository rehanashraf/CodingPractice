//
//  validprantheses.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 2/3/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
 */

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s);
bool runIsValid();

bool isValid(std::string s)
{
    bool rv = false;
    size_t stringLen = 0;
    
    char current, previous;
    
    current = previous = '\0';
    
    stringLen = s.size();
    std::stack<char> teststack;
    
    for(int i = 0; i < stringLen; i++)
    {
        if((s[i] == ')') || (s[i] == ']') || (s[i] == '}'))
        {
            if(!teststack.empty())
            {
                
            }
            else
            {
                rv = false;
                return rv;
            }
        }
    }
    
    return rv;
}

bool runIsValid()
{
    bool rv = true;
    
    
    return rv;
}
