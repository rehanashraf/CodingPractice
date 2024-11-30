/*
 * utility.h
 *
 *  Created on: Oct 24, 2020
 *      Author: rehanashraf
 */

#ifndef UTILITY_H_
#define UTILITY_H_

#define FLIPBIT(byte, nbit) (byte ^ (1U << nbit))
#define SETBIT(byte, nbit) (byte | (1U << nbit))
#define CLEARBIT(byte, nbit) (byte & ~(1U << nbit))
#define BITCHECK(byte, nbit) (1U & (number >> nbit))
#define SWAPNIBBLE(byte) (((byte & 0x0F) << 4) | ((byte & 0xF0) >> 4))
#define GET_UPPER_NIBBLE(byte) ((byte & 0xF0) >> 4)
#define GET_LOWER_NIBBLE(byte) ((byte & 0x0F) << 4)

#define SWAP_UINT16(x) (((x) >> 8) | ((x) << 8))
#define SWAP_UINT32(x) (((x) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

#define GET_EVEN_BITS_32(x) (x & 0x55555555) // 0b0101'0101
#define GET_ODD_BITS_32(x) (x & 0xAAAAAAAA)  // 0b1010'1010
#define GET_ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

#define C_TO_F(deg_c) (((float)(deg_c) * 9) / 5 + 32)
#define INT_BITS 32

typedef enum errors
{
    ERROR_OK = 0,
    ERROR_GENERIC = -1,
    ERROR_NULL_POINTER = -2,
    ERROR_NOT_ENOUGH_MEMORY = -3,
    ERROR_OUT_OF_BOUNDS = -4,
    ERROR_WRONG_SIZE = -5,
    ERROR_BAD_PARAMETER = -6,
} errors_e;

inline void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// inline void swap(int a, int b) {
//	int temp;
//	temp = a;
//	a = b;
//	b = temp;
// }

#endif /* UTILITY_H_ */
