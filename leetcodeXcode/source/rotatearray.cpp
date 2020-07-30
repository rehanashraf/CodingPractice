//
//  rotatearray.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/4/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 Given an array, rotate the array to the right by k steps, where k is non-negative.

 Follow up:

 Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 Could you do it in-place with O(1) extra space?
  

 Example 1:
 Input: nums = [1,2,3,4,5,6,7], k = 3
 Output: [5,6,7,1,2,3,4]
 Explanation:
 rotate 1 steps to the right: [7,1,2,3,4,5,6]
 rotate 2 steps to the right: [6,7,1,2,3,4,5]
 rotate 3 steps to the right: [5,6,7,1,2,3,4]
 
 Example 2:
 Input: nums = [-1,-100,3,99], k = 2
 Output: [3,99,-1,-100]
 Explanation:
 rotate 1 steps to the right: [99,-1,-100,3]
 rotate 2 steps to the right: [3,99,-1,-100]
 */

#include <stdio.h>
#include <vector>
#include "print.h"

bool runRotate();
void rotate(std::vector<int>& nums, int k);

void rotate(std::vector<int>& nums, int k) {
    size_t length = nums.size();
//    int data = 0;
    if (length == 0 || length == 1)
        return;
    
    for(int i = 0; i < k; i++) {
//        nums.insert(nums.begin(), nums.pop_back());
        nums.insert(nums.begin(), nums[length-1]);
        nums.pop_back();
    }
    
}

bool runRotate() {
    bool rv = false;
    std::vector<int> list1 , list2, list3;
    
    list1 = {1,2,3,4,5,6,7};
    list2 = {-1,-100,3,99};
    list3 = {0,2,6,5,9,7};
    
    printVector(list1);
    rotate(list1, 3);
    printVector(list1);
    
    printVector(list2);
    rotate(list2, 2);
    printVector(list2);
    
    printVector(list3);
    rotate(list3, 4);
    printVector(list3);
   
    return rv;
}
