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
#include <time.h>

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

uint64_t getTimeUTC(void) {
    uint64_t ret = 0;
    time_t current_time = 0;

    
    current_time = time(NULL);
//    gmtime_r(&current_time, &utc_time);
    struct tm *utc_time = gmtime(&current_time);
    printf("UTC time: %s", asctime(utc_time));
    
    struct tm *local_time = localtime(&current_time);
    printf("Local time: %s", asctime(local_time));
//    printf("UTC Time:%lu, Local Time:%lu\n", (long)current_time, (long)ret);
//    ret = localtime_r(&current_time, &local_time);
//    printf("UTC Time:%lu, Local Time:%lu\n", (long)current_time, (long)ret);
    return ret;
}
int convertTimeStringToEpoch(const char *string, const char *format) {
    int retVal = 0;
    
    
    return retVal;
}
