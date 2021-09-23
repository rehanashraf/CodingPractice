//
//  validanagram.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/6/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
 */

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

bool runIsAnagram();
bool isAnagram(std::string s, std::string t);

bool isAnagram(std::string s, std::string t) {
    bool rv = true;
    size_t lengths, lengtht;
    std::vector<int> alphabets_s, alphabets_t;
    
    lengths = s.length();
    lengtht = t.length();
    
    if (lengths == 0 && lengtht == 0)
        return rv;
    else if (lengths == 0 || lengtht == 0)
    {
        rv = false;
        return rv;
    }
    
    for( int i = 0; i < 26; i++)
    {
        alphabets_s.push_back(0);
        alphabets_t.push_back(0);
    }
    
    for (int i = 0; i < lengths; i++)
        alphabets_s[ s[i] - 97]++;

    for (int i = 0; i < lengtht; i++)
        alphabets_t[ t[i] - 97]++;
    
    for (int i = 0; i < 26; i++)
    {
        if(alphabets_s[i] != alphabets_t[i])
        {
            rv = false;
            return rv;
        }
    }
    return rv;
}

bool runIsAnagram()
{
    bool rv = true;
    std::string s, t;
    
    s = "";
    t = "";
    std::cout << s << " " << t << " " << isAnagram(s,t) << std::endl;
    
    s = "anagram";
    t = "nagaram";
    std::cout << s << " " << t << " " << isAnagram(s,t) << std::endl;
    
    s = "rat";
    t = "car";
    std::cout << s << " " << t << " " << isAnagram(s,t) << std::endl;
   
   
    return rv;
}
