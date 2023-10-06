/*
 * allString.cpp
 *
 *  Created on: Sep 13, 2023
 *      Author: rehanashraf
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define MAX_LEN 15

typedef enum status {
    STATUS_OK = 0,
    NULL_POINTER_PROVIDED = -1,
    BAD_PARAM = -2,
} status_t;

int compress_string(char *input_buf, uint32_t input_size, uint32_t *output_buf,
        uint32_t output_len) {
    status_t rv = STATUS_OK;

    if (input_buf == NULL || output_buf == NULL) {
        rv = NULL_POINTER_PROVIDED;
        return rv;
    }
    if (output_len == 0) {
        rv = BAD_PARAM;
        return rv;
    }

    char previous_char = input_buf[0];
    uint32_t previous_count = 1;
    int index = 0;

    for (int i = 1; i <= strlen(input_buf); i++) {
        if (previous_char == input_buf[i]) {
            previous_count++;
        } else {
            output_buf[index++] = previous_char;
            output_buf[index++] = previous_count;
            previous_count = 1;
            previous_char = input_buf[i];
        }

        // check for anything besides aplphabets
        // check output type chould be uint32_t buffer to accomodate big numbers
        // see if you can do a malloc (have some static buffer save data in there and then malloc and as grow maybe realloc)
    }
    output_buf[index++] = '\0';
    return index;
}

static void reverse(char *start, char *end) {

    char temp = '\0';
    if (start == NULL || end == NULL) {
        return;
    }

    while(start <= end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

char* reverseWords(char *s) {
    char *start = s;
    char *end = s;

    while (*end) {
        end++;
        if (*end == '\0') {
            reverse(start, end - 1);
        } else if (*end == ' ') {
            reverse(start, end - 1);
            start = end + 1;
        }
    }
    return s;
}

void run_compression(void) {
    char input[] = "aaaaagggdjfhhhooo";
    uint32_t output[MAX_LEN] = { 0 };

    printf("%s\n", input);
    compress_string(input, strlen(input), output, MAX_LEN);

    for (int i = 0; i < MAX_LEN; i++) {
        if (i % 2 == 0) {
            printf("%c", output[i]);
        } else {
            printf("%d", output[i]);
        }
    }

    printf("\n");

    for (int i = 0; i < MAX_LEN; i++) {
        printf("0x%02X ", output[i]);
    }
}
