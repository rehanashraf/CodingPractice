//
//  pivotIndex.cpp
//  leetcode
//
//  Created by Rehan Ashraf on 2/21/23.
//

#include <stdio.h>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    vector<int> rv;
    int sum = 0;
    for(auto & item : nums) {
        sum += item;
        rv.push_back(sum);
    }
    return rv;
}

int pivotIndex(vector<int>& nums) {
    size_t vecSize = nums.size();
    vector<int> leftSum, rightSum;
    int lSum, rSum;
    lSum = rSum = 0;
    int rv = -1;
    
    // std::cout << vecSize;
    for (int i = 0; i < vecSize; i++) {
        lSum += nums[i];
        rSum += nums[vecSize - i - 1];
        leftSum.push_back(lSum);
        rightSum.insert(rightSum.begin(), rSum);
    }
    
    for (int i = 0; i < vecSize; i++) {
        if (leftSum[i] == rightSum[i]) {
            rv = i;
            return rv;
        }
    }
    
    return rv;
}
