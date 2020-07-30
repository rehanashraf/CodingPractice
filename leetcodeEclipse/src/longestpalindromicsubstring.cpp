//
//  longestpalindromicsubstring.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/16/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

 Example 1:

 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:

 Input: "cbbd"
 Output: "bb"
 */

/*
 This is not the optimum solution. Complexity is O(n^3)
 98/102 test cases passed.
 */

#include <stdio.h>
#include <iostream>
#include <string>

bool isPalindrome(std::string &s, int start, int end);
std::string longestPalindrome(std::string s);

std::string longestPalindrome(std::string s)
{
    std::string sReturnValue = "";
    int iStringLength = 0, iSubstingLength = 0;
    
    iStringLength = (int)s.length();
    
    if(s.length() == 1)
    {
        return s;
    }
    
//    sReturnValue = s[0];
    
    for(int i = 0; i < iStringLength; i++)
    {
        for(int j = i + 1; j < iStringLength; j++)
        {
            if(isPalindrome(s, i, j))
            {
                iSubstingLength = j - i + 1;
                if((iSubstingLength) > sReturnValue.length())
                {
                    sReturnValue = s.substr(i,iSubstingLength);
                }
            }
        }
    }

    return sReturnValue;
}

bool isPalindrome(std::string &s, int start, int end)
{
    bool bReturnValue = true;
    int iStartIndex = 0, iEndIndex = 0;
    
    iStartIndex = start;
    iEndIndex = end;
    
    for(int i = 0; i < (end - start + 1)/2; i++, iStartIndex++, iEndIndex--)
    {
        if (s[iStartIndex] != s[iEndIndex])
        {
            bReturnValue = false;
            return bReturnValue;
        }
    }
    //check if palindrome
    return bReturnValue;
}

bool runlongestPalindrome()
{
    bool bReturnValue = true;
    std::string s;
    
    s = "naherrehan";
    std::cout << s << " " << isPalindrome(s,0,(int)s.length() - 1) << std::endl;
    
    s = "naherrehan";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "cbbd";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "babad";
    std::cout << s << " " << longestPalindrome(s) << std::endl;

    s = "abbab";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "a";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "ac";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "aba";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "aa";
    std::cout << s << " " << longestPalindrome(s) << std::endl;
    
    s = "1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    std::cout << s << std::endl << std::endl << std::endl << longestPalindrome(s) << std::endl;
    
    return bReturnValue;
}
