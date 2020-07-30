//
//  validpalindrome.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/6/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
 /*
  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

 Note: For the purpose of this problem, we define empty string as valid palindrome.

 Example 1:

 Input: "A man, a plan, a canal: Panama"
 Output: true
 Example 2:

 Input: "race a car"
 Output: false
  

 Constraints:

 s consists only of printable ASCII characters.
  */

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#include "macros.h"

bool runIsPalindrome();
bool isPalindrome(std::string s);

bool isPalindrome(std::string s) {
    bool rv = true;
    size_t length = 0;
    std::vector<char> shortlist;
    
    length = s.size();
    for(int i = 0; i < length; i++)
    {
        if (ISALPHA(s[i]) || ISDIGIT(s[i]))
            shortlist.push_back(s[i]);
    }
    
    length = shortlist.size();
    if (length == 0 || length == 1)
        return rv;
    
    for(int i = 0, j = (int)length -1; i < length/2; i++, j--)
    {
        if (SMALLIZE(shortlist[i]) != SMALLIZE(shortlist[j]))
        {
            rv = false;
            return rv;
        }
    }
    return rv;
    
//    bool rv = true, run = true;
//    int leftIndex, rightIndex, length;
//
//    leftIndex = rightIndex = length = 0;
//
//    length = rightIndex = s.length();
//
//    if (length == 0)
//    {
//        rv = false;
//        return rv;
//    }
//
//    while(run)
//    {
//        if (leftIndex > rightIndex)
//        {
//            rv = true;
//            return rv;
//        }
//
//        if (!ISALPHA(s[leftIndex]) && !ISALPHA(s[rightIndex]))
//        {
//            leftIndex++;
//            rightIndex--;
//            continue;
//        }
//        else if (!ISALPHA(s[leftIndex]))
//        {
//            leftIndex++;
//            continue;
//        }
//        else if (!ISALPHA(s[rightIndex]))
//        {
//            rightIndex--;
//            continue;
//        }
//
//        if ()
//        {
//
//        }
//    }
//    return rv;
}

bool runIsPalindrome()
{
    bool rv = true;
    std::string input;
    
    input = "0P";
    std::cout << input << " ----- " << isPalindrome(input) << std::endl;
    
    input = "A man, a plan, a canal: Panama";
    std::cout << input << " ----- " << isPalindrome(input) << std::endl;
    

    return rv;
}
