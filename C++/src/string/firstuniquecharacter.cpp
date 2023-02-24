//
//  firstuniquecharacter.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/6/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
 

Note: You may assume the string contains only lowercase English letters
 */
#include <string>
#include <iostream>
#include <vector>

#include <stdio.h>

bool runFirstUniqChar();
int firstUniqChar(std::string s);

int firstUniqChar(std::string s) {
    int rv = -1;
    size_t length = 0;
    std::vector<int> alphabets;
    
    length = s.length();
    if (length == 0)
        return rv;
    
    for( int i = 0; i < 26; i++)
        alphabets.push_back(0);
    
    for (auto ch : s)
    {
//        std::cout << ch << " ";
        alphabets[ch - 97]++;
    }
//    std::cout << std::endl;
    
    for (int i = 0; i < length; i++)
    {
        if(alphabets[s[i] -97] == 1)
        {
            rv = i;
            return rv;
        }
    }
    
    return rv;
}

bool runFirstUniqChar()
{
    bool rv = true;
    std::string str;
    str = "rehan ashraf cheema";
        
    firstUniqChar(str);
    
    return rv;
}
