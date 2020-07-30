//
//  hammingdistance.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/5/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

 Given two integers x and y, calculate the Hamming distance.

 Note:
 0 ≤ x, y < 231.

 Example:

 Input: x = 1, y = 4

 Output: 2

 Explanation:
 1   (0 0 0 1)
 4   (0 1 0 0)
        ↑   ↑

 The above arrows point to positions where the corresponding bits are different.
 */
#include <stdio.h>
#include <iostream>

bool runHammingDistance();
int hammingDistance(int x, int y);

int hammingDistance(int x, int y) {
    int rv, xorValue, mask;
    rv = xorValue = 0;
    mask = 1;
    xorValue = x ^ y;
    
    for(int i = 0; i < 32; i++)
    {
        if(mask & xorValue)
            rv++;
        mask = mask << 1;
    }
    
    return rv;
}

bool runHammingDistance()
{
    bool rv = true;
    std::cout << hammingDistance(1, 4) << std::endl;
    return rv;
}
