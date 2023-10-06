/*
 * allbits.cpp
 *
 *  Created on: Sep 27, 2020
 *      Author: rehanashraf
 */
#include <stdint.h>

#define FLIPBIT(byte, nbit)		(byte ^ (1U << nbit))
#define SETBIT(byte, nbit)		(byte | (1U << nbit))
#define	CLEARBIT(byte, nbit)	(byte & ~(1U << nbit))
#define	BITCHECK(byte, nbit)	(byte & (1U << nbit))
#define SWAPNIBBLE(byte)		(((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4))
#define GET_UPPER_NIBBLE(byte)  ((byte & 0xF0) >> 4)
#define GET_LOWER_NIBBLE(byte)  ((byte & 0x0F) << 4)

#define SWAP_UINT16(x)          (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x)          (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

#define GET_EVEN_BITS_32(x)     (x & 0x55555555) // 0b0101'0101
#define GET_ODD_BITS_32(x)      (x & 0xAAAAAAAA) // 0b1010'1010
#define GET_ARRAY_SIZE(array)	(sizeof(array)/sizeof(array[0]))

#define C_TO_F(deg_c)	(((float)(deg_c)*9)/5 + 32)
#define INT_BITS 32

typedef enum {
    LITTLE_ENDIAN, BIG_ENDIAN,
} ENDINESS;

//! Byte swap unsigned short
uint16_t swap_uint16(uint16_t val) {
    return (val << 8) | (val >> 8);
}

//! Byte swap short
int16_t swap_int16(int16_t val) {
    return (val << 8) | ((val >> 8) & 0xFF);
}

//! Byte swap unsigned int
uint32_t swap_uint32(uint32_t val) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | (val >> 16);
}

//! Byte swap int
int32_t swap_int32(int32_t val) {
    val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF);
    return (val << 16) | ((val >> 16) & 0xFFFF);
}

int64_t swap_int64(int64_t val) {
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL)
            | ((val >> 8) & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL)
            | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | ((val >> 32) & 0xFFFFFFFFULL);
}

uint64_t swap_uint64(uint64_t val) {
    val = ((val << 8) & 0xFF00FF00FF00FF00ULL)
            | ((val >> 8) & 0x00FF00FF00FF00FFULL);
    val = ((val << 16) & 0xFFFF0000FFFF0000ULL)
            | ((val >> 16) & 0x0000FFFF0000FFFFULL);
    return (val << 32) | (val >> 32);
}

unsigned int swapBitsInPair(unsigned int x) {
    // Extracting the high bit shift it to lowbit
    // Extracting the low bit shift it to highbit
    return ((x & 0b10101010) >> 1) | ((x & 0b01010101) << 1);
}

uint32_t swap_even_odd_bits_uint32(uint32_t val) {
    uint32_t rv = 0;

    rv |= GET_EVEN_BITS_32(val) << 1;
    rv |= GET_ODD_BITS_32(val) >> 1;

    return rv;
}

uint8_t flip_hi_low(uint8_t n) {
    uint8_t rv = 0;
    uint8_t mask = 0b1000'0001;

    rv = n ^ mask;
    return rv;
}

uint32_t invertbits(uint32_t n) {
    uint32_t rv = 0;
    rv = ~n;
    return rv;
}

uint32_t flipbit(uint32_t n, uint8_t i) {
    uint32_t rv = 0;
    if (i > 31)
        return rv;

    rv = n ^ (1U << i);

    return rv;
}

uint32_t reverseBitsForLoop(uint32_t n) {

    uint32_t rv = 0;
    uint32_t mask = 1;

    for (int i = 0; i < 32; i++) {
        mask = (1 << 0);
        mask = mask & n;
        mask = mask << (31 - (i));
        rv |= mask;
        n = n >> 1;
    }

    return rv;
}

uint32_t reverseBitsWhileLoop(uint32_t n) {
    int i = 0;
    uint32_t rv = 0;

    while (n) {
        rv |= ((1U & n) << (31 - i++));
        n = n >> 1;
    }
    return rv;

}

uint8_t countSetBits(uint32_t n) {
    uint8_t rv = 0;

    while (n) {
        rv += n & 1U;
        n = n >> 1;
    }
    return rv;
}

uint8_t countClearBits(uint32_t n) {
    uint8_t rv = 0;

    rv = countSetBits(~n);

    return rv;
}

/* Set bits from Y:X eg 20:18 */
void setBitsXY(uint32_t *n, uint8_t x, uint8_t y) {
    uint32_t mask = 0;
    for (int i = 0; i <= (y - x); i++) {
        mask |= (mask | (1U << i));
    }

    *n |= mask;
}

int32_t addOne(int32_t x) {
    int32_t m = 1;

    // Flip all the set bits
    // until we find a 0
    while (x & m) {
        x = x ^ m;
        m = m << 1;
    }

    // flip the rightmost 0 bit
    x = x ^ m;

    return x;
}

int32_t subtract(int32_t x, int32_t y) {
    // Iterate till there
    // is no carry
    while (y != 0) {
        // borrow contains common
        // set bits of y and unset
        // bits of x
        int32_t borrow = (~x) & y;

        // Subtraction of bits of x
        // and y where at least one
        // of the bits is not set
        x = x ^ y;

        // Borrow is shifted by one
        // so that subtracting it from
        // x gives the required sum
        y = borrow << 1;
    }
    return x;
}

/*Function to left rotate n by d bits*/
int leftRotate(int n, unsigned int d) {
    /* In n<<d, last d bits are 0. To put first 3 bits of n at
     last, do bitwise or of n<<d with n >>(INT_BITS - d) */
    return (n << d) | (n >> (INT_BITS - d));
}

/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d) {
    /* In n>>d, first d bits are 0. To put last 3 bits of at
     first, do bitwise or of n>>d with n <<(INT_BITS - d) */
    return (n >> d) | (n << (INT_BITS - d));
}

bool runReverseBits(void) {
    bool rv = false;
    uint32_t number = 0b0000'0010'1001'0100'0001'1110'1001'1100;
    uint32_t reversenumber = 0;

    reversenumber = reverseBitsForLoop(number);
    if (reversenumber == number) {
        rv = true;
    }

    return rv;
}

bool runInvertBits(void) {
    bool rv = false;
    uint32_t test = 0b0000'0010'1001'0100'0001'1110'1001'1100;
    test = invertbits(test);
    return rv;
}

ENDINESS TestByteOrder() {
    short int word = 0x0001;
    char *byte = (char*) &word;
    return (byte[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

uint32_t changeEndiness(uint32_t num) {
    uint32_t b0, b1, b2, b3;
    uint32_t res;

    b0 = (num & 0x000000ff) << 24u;
    b1 = (num & 0x0000ff00) << 8u;
    b2 = (num & 0x00ff0000) >> 8u;
    b3 = (num & 0xff000000) >> 24u;

    res = b0 | b1 | b2 | b3;

    return res;
}
