/*
 * 3closestsum.cpp
 *
 *  Created on: Nov 9, 2020
 *      Author: rehanashraf
 */

// C++ implementation of the approach
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to return the sum of a
// triplet which is closest to x
int threeClosestSumBruteForce(vector<int>& arr, int x)
{
    // To store the closets sum
    int closestSum = INT_MAX;

    // Run three nested loops each loop
    // for each element of triplet
    for (int i = 0; i < arr.size() ; i++)
    {
        for(int j =i + 1; j < arr.size(); j++)
        {
            for(int k =j + 1; k < arr.size(); k++)
            {
                //update the closestSum
                if(abs(x - closestSum) > abs(x - (arr[i] + arr[j] + arr[k])))
                    closestSum = (arr[i] + arr[j] + arr[k]);
            }
        }
    }
    // Return the closest sum found
    return closestSum;
}

// Function to return the sum of a
// triplet which is closest to x
int threeClosestSumDoublePointer(vector<int>& arr, int x)
{

    // Sort the array
    sort(arr.begin(), arr.end());

    // To store the closets sum
    int closestSum = INT_MAX;

    // Fix the smallest number among
    // the three integers
    for (int i = 0; i < arr.size() - 2; i++) {

        // Two pointers initially pointing at
        // the last and the element
        // next to the fixed element
        size_t ptr1 = i + 1, ptr2 = arr.size() - 1;

        // While there could be more pairs to check
        while (ptr1 < ptr2) {

            // Calculate the sum of the current triplet
            int sum = arr[i] + arr[ptr1] + arr[ptr2];

            // If the sum is more closer than
            // the current closest sum
            if (abs(1LL*x - sum) < abs(1LL*x - closestSum)) {
                closestSum = sum;
            }

            // If sum is greater then x then decrement
            // the second pointer to get a smaller sum
            if (sum > x) {
                ptr2--;
            }

            // Else increment the first pointer
            // to get a larger sum
            else {
                ptr1++;
            }
        }
    }

    // Return the closest sum found
    return closestSum;
}
// Driver code
int run3ClosestSum()
{
    vector<int> arr = { -1, 2, 1, -4 };
    int x = 1;
    cout << threeClosestSumBruteForce(arr, x);

    return 0;
}

