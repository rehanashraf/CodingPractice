//
//  main.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 11/29/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "main.h"
#include "playground.h"
#include <vector>
#include <string>

using namespace std;

int getFib(int n);
void getCombinations(char *data, uint32_t len,
                     char **outputData, uint32_t outputLen) {
    char *array = (char*)calloc(len, sizeof(char));
    outputData = (char **)calloc(1 << outputLen, sizeof(char*));
    if (data == NULL){
        return;
    }
    uint32_t llen = 0;
    
    for(int mask = 0; mask < (1 << len); mask++) {
        memset(array, 0, len);
        llen = 0;
        for (int j = 0; j<len;j++) {
            int number = 1 << j;
            if ((mask & number)) {
                array[llen++] = data[j];
            }
        }
        outputData[outputLen] = (char*)calloc(strlen(array) + 1, sizeof(char));
        strcpy(outputData[outputLen], array);
        outputLen++;
        printf("%s\n", array);
    }
}

int main(int argc, const char * argv[])
{
    char name[] = "abc";
    char *output = NULL;
    uint32_t outputLength = 0;
    
    getCombinations(name, strlen(name), &output, outputLength);
    printf("\n\n\n");
    for(int i = 0; i < outputLength; i++) {
        printf("%s\n", output[i]);
    }
//    for(int mask = 0; mask < (1 << length); mask++) {
//        string temp = "";
//        for (int j = 0; j<length;j++) {
//            int number = 1 << j;
//            if ((mask & number)) {
//                temp += name[j];
//            }
//        }
//        cout << temp << endl;
//    }
    return 0;
}
