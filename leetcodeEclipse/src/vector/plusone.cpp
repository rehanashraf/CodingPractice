//
//  plusone.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/5/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

 The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

 You may assume the integer does not contain any leading zero, except the number 0 itself.

 Example 1:

 Input: [1,2,3]
 Output: [1,2,4]
 Explanation: The array represents the integer 123.
 Example 2:

 Input: [4,3,2,1]
 Output: [4,3,2,2]
 Explanation: The array represents the integer 4321.
 */

#include <stdio.h>
#include <vector>
#include "print.h"

bool runPlusOne();
std::vector<int> plusOne(std::vector<int>& digits);

std::vector<int> plusOne(std::vector<int>& digits) {
    std::vector<int> rv;
    int overflow, sum;
    
    overflow = 1;
    sum = 0;
    size_t length = digits.size();
    
    if (digits.size() == 0)
        return rv;
    
    for (int i = (int)length - 1; i >= 0; i--) {
        sum = digits[i] + overflow;
        overflow = sum /10;
        rv.insert(rv.begin(), sum % 10);
    }
    
    if (overflow)
        rv.insert(rv.begin(), overflow);
    return rv;
}

bool runPlusOne() {
    bool rv = true;
    std::vector<int> list1, list2, list3, list4;
    
    list1 = {1,2,3};
    list2 = {4,3,2,1};
    list3 = {9,9,9,9};
    
    printVector(list1) ;
    list4 = plusOne(list1);
    printVector(list4);
    
    printVector(list2) ;
    list4 = plusOne(list2);
    printVector(list4);
    
    printVector(list3) ;
    list4 = plusOne(list3);
    printVector(list4);
    
    return rv;
}
