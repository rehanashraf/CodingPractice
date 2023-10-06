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

/* Function to check if x is power of 2*/
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return 0;
    while (n != 1) {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

int getPower(int base, int number) {
	int rv = 0;

	while (number >1){
		number = number/base;
		rv++;
	}
	return rv;
}

int isPowerof2(int x)
{
    return (x && !(x & x-1));
}

int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
