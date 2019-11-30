//
//  twosum.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 11/29/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> rv ;
    size_t siezeoflist = nums.size();

    for(int i = 0; i < siezeoflist; i++)
    {
        for(int j = i+1; j < siezeoflist; j++)
        {
            if((nums[i] + nums[j]) == target)
            {
                rv.push_back(i);
                rv.push_back(j);
                return rv;
            }
        }
    }

    return rv;
}

void printVector(vector<int>& list)
{
    std::vector<int>::iterator it;
    std::cout << "Vector contains:";

    for (it=list.begin(); it<list.end(); it++)
        std::cout << ' ' << *it;

    std::cout << '\n';
}

bool runTwoSum()
{
    vector<int> testlist;

    testlist.push_back(2);
    testlist.push_back(7);
    testlist.push_back(9);
    testlist.push_back(11);

    printVector(testlist);

    testlist = twoSum(testlist, 9);

    printVector(testlist);

    return true;
}
