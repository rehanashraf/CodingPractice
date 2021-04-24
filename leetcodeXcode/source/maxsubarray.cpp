/* Given an integer array nums, find the contiguous subarray
 * (containing at least one number) which has the largest sum and return its sum.
 * Example:
 * Input: [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * Follow up:
 * If you have figured out the O(n) solution, try coding another solution
 * using the divide and conquer approach, which is more subtle.
 * */

#include <iostream>
#include <vector>
#define MAX(a,b)	((a) > (b) ? (a) : (b))

int maxSubArray(std::vector<int>& nums)
{
	int rv, currentSum, overallSum;

	rv = currentSum = 0;
	if (nums.size() == 1)
	{
		rv = nums[0];
		return rv;
	}
	overallSum = nums[0];
	for(size_t i = 0; i < nums.size(); i++)
	{
		currentSum = MAX(currentSum + nums[i], nums[i]);
		overallSum = MAX(currentSum, overallSum);
	}

	rv = overallSum;
	return rv;
}

bool runMaxSubArray()
{
	bool rv = false;

	return rv;
}
