///*
// * allconversion.c
// *
// *  Created on: Sep 30, 2020
// *      Author: rehanashraf
// */
//
//#include<stdint.h>
//
//void stringToUpperCases(uint8_t *p)
//{
//    uint32_t i = 0;
//    for (i = 0; *(p + i) != '\0'; i++)
//    {
//        if ((*(p + i) >= 'a') && (*(p + i) <= 'z'))
//        {
//            *(p + i) = *(p + i) - 32;
//        }
//    }
//}
//
//static uint8_t charToHexDigit(uint8_t c)
//{
//    if ((c >= 'A') && (c <= 'Z'))
//    {
//        return (c - 'A' + 10);
//    }
//    else if ((c >= 'a') && (c <= 'z'))
//    {
//        return (c - 'a' + 10);
//    }
//    else
//    {
//        return (c - '0');
//    }
//}
//
//static uint8_t ascii2HexToByte(uint8_t *ptr)
//{
//    return charToHexDigit(*ptr) * 16 + charToHexDigit(*(ptr + 1));
//}
//
//int32_t stringToBytes(uint8_t *string, uint8_t *result, int32_t size)
//{
//    int32_t k = 0;
//    int32_t i = 0;
//    int32_t strLen;
//
//    if (size == 0)
//    {
//        strLen = strlen((const char *)string);
//    }
//    else
//    {
//        strLen = size;
//    }
//    for (i = 0; i < strLen; i = i + 2)
//    {
//        result[k] = ascii2HexToByte(&string[i]);
//        k++;
//    }
//    return k; // number of bytes in the result array
//}
//
//int8_t hex2Ascii(int8_t c)
//{
//    if ((c >= 0) && (c <= 9)) {
//        return c + '0';
//    } else if ((c >= 10) && (c <= 15)) {
//        return (c - 10 + 'A');
//    }
//
//    return 0;
//
//}
//
//// function to convert decimal to binary
//void decToBinary(int n)
//{
//    // array to store binary number
//    int binaryNum[32];
//
//    // counter for binary array
//    int i = 0;
//    while (n > 0) {
//
//        // storing remainder in binary array
//        binaryNum[i] = n % 2;
//        n = n / 2;
//        i++;
//    }
//
//    // printing binary array in reverse order
//    for (int j = i - 1; j >= 0; j--)
//        printf("%d", binaryNum[j]);
//}
