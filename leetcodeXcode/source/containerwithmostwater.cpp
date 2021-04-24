//
//  containerwithmostwater.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/19/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
 Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

 Note: You may not slant the container and n is at least 2.
 The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 Example:

 Input: [1,8,6,2,5,4,8,3,7]
 Output: 49
 
 */


#include <stdio.h>
#include <vector>
#include <iostream>

#include "print.h"

int maxArea(std::vector<int>& height)
{
    int returnValue = 0, currentMaxArea = 0, longestMaxArea = 0, length = 0, width = 0;
    size_t arrayLength = 0;
    
    arrayLength = height.size();
    
    for(int i = 0; i < arrayLength - 1; i++)
    {
//        currentMaxArea =
        for(int j = i + 1; j < arrayLength; j++)
        {
            if(height[i] > height[j])
            {
                length = height[j];
            }
            else
            {
                length = height[i];
            }
            width = j - i;
            
            currentMaxArea = length * width;
            if(currentMaxArea > longestMaxArea)
            {
                longestMaxArea = currentMaxArea;
            }
        }
    }
    returnValue = longestMaxArea;
    return returnValue;
}

bool runMaxArea()
{
    bool retunValue = true;
    
    std::vector<int> firstArray{1,8,6,2,5,4,8,3,7};
    printVector(firstArray);
    std::cout << "Max Area is " << maxArea(firstArray) << std::endl;
    
    return retunValue;
}
