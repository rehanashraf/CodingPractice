//
//  playground.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/19/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unistd.h>

void testSwitchCases()
{
    char ch = 'A';
    
    std::cout << ch << std::endl;
    switch(ch)
    {
        case 'A':
            std::cout << ch << ' ' << 'A' << std::endl;
            ch = 'B';
        case 'B':
            std::cout << ch << ' ' << 'B' << std::endl;
            ch = 'B';
        case 'C':
            std::cout << ch << ' ' << 'C' << std::endl;
            ch = 'B';
        default:
            break;
    }
    
}

void sameLinePrint()
{
    int seconds, milliseconds;

    milliseconds = 1000;
    seconds = 1000 * milliseconds;
    for(int i = 0; i < 10; i++)
    {
        printf("\rValue of i is: %d", i);
        fflush(stdout);
        usleep(1*seconds);
    }
}
