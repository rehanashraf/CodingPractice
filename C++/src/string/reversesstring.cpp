//
//  reversesstring.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/6/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 */

#include <stdio.h>
#include <vector>
#include <iostream>
#include "print.h"

bool runReverseString();
void reverseString(std::vector<char>& s);

void reverseString(std::vector<char>& s) {
    size_t length = 0;
    char temp = '\0';
    
    length = s.size();
    
    if (length == 0 || length == 1)
        return;
    for(int i = 0; i < length/2; i++)
    {
        temp = s[length - 1 - i];
        s[length - 1 - i] = s[i];
        s[i] = temp;
    }
}

bool runReverseString()
{
    bool rv = true;
    std::vector<char> list1, list2,list3;
    
    list1 = {'h','e','l','l','o'};
    list2 = {'h','a','n','n','a','h'};
    
    printVector(list1);
    reverseString(list1);
    printVector(list1);
    
    printVector(list2);
    reverseString(list2);
    printVector(list2);
    
    return rv;
}


#include <stdio.h>

// Function to reverse any sequence
// starting with pointer begin and
// ending with pointer end
void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

// Function to reverse words*/
void reverseWords(char* s)
{
    char* word_begin = s;

    // Word boundary
    char* temp = s;

    // Reversing individual words as
    // explained in the first step
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }

    // Reverse the entire string
    reverse(s, temp - 1);
}

