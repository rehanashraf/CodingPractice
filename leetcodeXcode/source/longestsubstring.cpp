//
//  longestsubstring.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 11/29/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
 Given a string, find the length of the longest substring without repeating characters.

 Example 1:

 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", with the length of 3.
 Example 2:

 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:

 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
#include <stdio.h>
#include <iostream>
#include <string>

int lengthOfLongestSubstring(std::string s);
bool runlengthOfLongestSubstring();
bool isCharatcerInString(std::string s, char ch);

int lengthOfLongestSubstring(std::string s)
{
    int rv = 0;
    std::string longestsrting, currentlongeststring = "";
    std::size_t s_len = s.length();
    std::size_t pos = -1;
    char comparecharacter;
        
    if(s_len == 0)
    {
        rv = 0;
        return rv;
    }
    else
    {
        longestsrting += s[0];
        currentlongeststring += s[0];
    }
    for(int i = 1; i < s_len; i++)
    {
        comparecharacter = s[i];
        pos = currentlongeststring.find(comparecharacter);
        if(pos!=std::string::npos)
        {
            if(currentlongeststring.size() > longestsrting.size())
            {
                longestsrting = currentlongeststring;
            }
            currentlongeststring = currentlongeststring.substr(pos+1);
            currentlongeststring += comparecharacter;
        }
        else
        {
            currentlongeststring += s[i];
        }
    }
    if(currentlongeststring.size() > longestsrting.size())
    {
        longestsrting = currentlongeststring;
    }
//    std::cout << "Substring is " << longestsrting << std:: endl;
    rv = (int)longestsrting.size();
    return rv;
}

bool runlengthOfLongestSubstring()
{
    std::string testdata = "";
    int result = 0;
    
    testdata = "abcabcbb";
    result = lengthOfLongestSubstring(testdata);
    std::cout << testdata << " " << result << std::endl;

    testdata = "bbbbb";
    result = lengthOfLongestSubstring(testdata);
    std::cout << testdata << " " << result << std::endl;

    testdata = "pwwkew";
    result = lengthOfLongestSubstring(testdata);
    std::cout << testdata << " " << result << std::endl;

    testdata = "au";
    result = lengthOfLongestSubstring(testdata);
    std::cout << testdata << " " << result << std::endl;

    testdata = "dvdf";
    result = lengthOfLongestSubstring(testdata);
    std::cout << testdata << " " << result << std::endl;
    
    testdata = "aabaab!bb";
    result = lengthOfLongestSubstring(testdata);
    std::cout << testdata << " " << result << std::endl;
    return true;
}
