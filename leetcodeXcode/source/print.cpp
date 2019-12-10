//
//  print.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/1/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

#include "print.h"

void printVector(std::vector<int>& list)
{
    std::vector<int>::iterator it;
    std::cout << "Vector contains:";

    for (it=list.begin(); it<list.end(); it++)
        std::cout << ' ' << *it;

    std::cout << '\n';
}
