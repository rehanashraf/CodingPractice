/*
 * Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 * Example:
 * Input: [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 */

#include <iostream>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums)
{
   int leftmoveindex, lenghth;
   leftmoveindex = lenghth = 0;

    lenghth = (int)nums.size();
   for(size_t i = 0; i < lenghth; i++)
   {
       if (nums[i] != 0)
       {
           std::swap(nums[i], nums[leftmoveindex]);
           leftmoveindex++;
       }
   }
}

bool runMoveZeroes(void)
{
	bool rv = false;

	std::vector<int> list1,list2;
    list1 = {0,1,0,3,12};
    list2 = {0,1,0};
    
	moveZeroes(list1);
	moveZeroes(list2);
    
	return rv;
}
