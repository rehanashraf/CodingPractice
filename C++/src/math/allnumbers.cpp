//
//  allnumbers.cpp
//  leetcode
//
//  Created by Rehan Ashraf on 3/30/23.
//

#include <stdio.h>
#include <inttypes.h>

bool isPalindrome(uint32_t number);
uint32_t reverseNumber(uint32_t number);

uint32_t reverseNumber(uint32_t number) {
    uint32_t rv = 0;
    
    uint8_t digit = 0;
    while(number) {
        digit = number % 10;
        number = number / 10;
        rv = (rv * 10) + digit;
    }
    return rv;
}

bool isPalindrome(uint32_t number) {
    bool rv = false;
    uint32_t reverse = 0;
    
    reverse = reverseNumber(number);
    if (number == reverse) {
        rv = true;
    }
    return rv;
}
