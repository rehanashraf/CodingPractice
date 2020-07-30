//
//  containsduplicate.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/4/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 Given an array of integers, find if the array contains any duplicates.

 Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

 Example 1:

 Input: [1,2,3,1]
 Output: true
 Example 2:

 Input: [1,2,3,4]
 Output: false
 Example 3:

 Input: [1,1,1,3,3,4,3,2,4,2]
 Output: true
 */
#include <stdio.h>
#include <vector>
#include "print.h"

bool runContainsDuplicate();
bool containsDuplicate(std::vector<int>& nums);

bool runContainsDuplicate() {
    bool rv = true;
    std::vector<int> list1, list2,list3;
    
    list1 = {1,2,3,1};
    list2 = {1,2,3,4};
    list3 = {1,1,1,3,3,4,3,2,4,2};
    
    printVector(list1);
    std::cout << std::boolalpha << containsDuplicate(list1) << std::endl ;
    
    printVector(list2);
    std::cout << containsDuplicate(list2) << std::endl ;
    
    printVector(list3);
    std::cout << containsDuplicate(list3) << std::endl ;
    
    return rv;
}
bool containsDuplicate(std::vector<int>& nums) {
    size_t length = 0;
    bool rv = false;
    length = nums.size();
    
    if (length == 0 || length == 1)
        return false;
    
    for (int i = 0; i < length - 1; i++) {
        for(int j = i + 1; j < length; j++)
            if (nums[i] == nums[j]) {
                rv = true;
                return rv;
            }
    }
    return rv;
}
