//
//  removeduplicatesfromsortedlist.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 6/26/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

// [1,1,2]
// [0,0,1,1,1,2,2,3,3,4]

#include <stdio.h>
#include <vector>
#include <iostream>

#include "print.h"

bool runRemoveDuplicates();
int removeDuplicates(std::vector<int>& nums);

int removeDuplicates(std::vector<int>& nums) {
    int rv = 0;
    rv = (int)nums.size();
    
//    nums[1]).erase();
    if (!rv)
        return rv;
    printVector(nums);
    for(std::vector<int>::iterator it = nums.begin(); it != nums.end() - 1;) {
        if(*it == *(it+1)){
            nums.erase(it+1);
            rv--;
        }
        else {
            ++it;
        }
    }
    printVector(nums);
    return rv;
}

bool runRemoveDuplicates() {
    bool rv = true;
    
    std::vector<int> vector1;
    std::vector<int> vector2;
    
    vector1.push_back(1);
    vector1.push_back(1);
    vector1.push_back(1);
    vector1.push_back(1);
    vector1.push_back(2);
    vector1.push_back(2);
    
    vector2.push_back(0);
    vector2.push_back(0);
    vector2.push_back(1);
    vector2.push_back(1);
    vector2.push_back(1);
    vector2.push_back(2);
    vector2.push_back(2);
    vector2.push_back(3);
    vector2.push_back(3);
    vector2.push_back(4);
    
    removeDuplicates(vector1);
    removeDuplicates(vector2);
    return rv;
}
