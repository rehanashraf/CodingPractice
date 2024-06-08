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

//     array = new Integer[] {1, 2, 3, 4, -10, 1};   //10
//     array = new Integer[] {1, 2, 3, 4, 5, 6, 7, 8};   // 36
//      array = new Integer[] {1, 2, 3, 4, -10, 1}; // 10
//     array = new Integer[] { -1,-2 -3 -4 -5 }; // ?
//      array = new Integer[] { 4 3 -10 3 -1 2 0 -3 5 7 -4 -8 -10 4 7 -30 -2 -6 4 7 } ; // 13


#include <iostream>
#include <vector>
#include <climits>

#include <stdio.h>
#define MAX(a,b)	((a) > (b) ? (a) : (b))

long int find_max_sum(int *array, int len);
int maxSubArray(std::vector<int>& nums)
{
  // Kadane's algorithm
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
	  int testarray1[] = {1, 2, 3, 4, -10, 1};
	  find_max_sum(testarray1, sizeof(testarray1)/sizeof(testarray1[0]));

	  int testarray2[] = { -1,-2,-3, -4, -5};
	  find_max_sum(testarray2, sizeof(testarray2)/sizeof(testarray2[0]));

	  int testarray3[] = { 1, 2, 3, 4, 5, 6, 7, 8};
	  find_max_sum(testarray3, sizeof(testarray3)/sizeof(testarray3[0]));

	  int testarray4[] = {  4, 3, -10, 3, -1, 2, 0, -3, 5, 7, -4, -8, -10, 4, 7, -30, -2, -6, 4, 7};
	  find_max_sum(testarray4, sizeof(testarray4)/sizeof(testarray4[0]));

	  int testarray5[] = { -5,-4,-3, -4, -5};
	  find_max_sum(testarray5, sizeof(testarray5)/sizeof(testarray5[0]));
	return rv;
}


long int find_max_sum(int *array, int len)
{
  long int currentsum, maxsum;
  int start, end, tempiter;

  maxsum  = INT_MIN;
  currentsum = start = end = tempiter = 0;
  // currentsum = 0;//-10000000000;

  for(int i = 0; i<len;i++)
  {
    currentsum = currentsum + array[i];

    if(maxsum < currentsum)
    {
      maxsum = currentsum;
      start = tempiter;
      end = i;
    }

    if (currentsum < 0) //check equal to
    {
      currentsum = 0;
      tempiter = i + 1;
    }

  }
  printf("start index=%d end index = %d max sum=%ld\n", start, end, maxsum);

  return maxsum;
}

int maxSubArraySum(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
       start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }
    return max_so_far;
}


