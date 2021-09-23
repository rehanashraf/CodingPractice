/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
*/

#include <vector>
#include <iostream>
using namespace std;

int singleNumber(vector<int>& nums);
bool runSingleNumber(void);

int singleNumber(vector<int>& nums)
{
	int rv = 0, arraySize = 0;

	arraySize = nums.size();
	for(int i = 0; i < arraySize; i++)
	{
		rv ^= nums[i];
	}

	return rv;
}

bool runSingleNumber(void)
{
	bool rv = true;

	vector<int> array1;

	array1.push_back(4);
	array1.push_back(1);
	array1.push_back(2);
	array1.push_back(1);
	array1.push_back(2);

	cout << "Single Number for " << singleNumber(array1);
	return rv;
}
