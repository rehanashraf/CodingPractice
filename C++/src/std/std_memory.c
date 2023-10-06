/*
 * memory_impl.c
 *
 *  Created on: Sep 18, 2023
 *      Author: rehanashraf
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void my_memcpy(void *dest, void *src, size_t n)
{
    // Typecast src and dest addresses to (char *)
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    // Copy contents of src[] to dest[]
    for (int i=0; i<n; i++)
        cdest[i] = csrc[i];
}

void my_memmove(void *dest, void *src, size_t n)
{
    // Typecast src and dest addresses to (char *)
    char *csrc = (char *)src;
    char *cdest = (char *)dest;

    // Create a temporary array to hold data of src
    char *temp = malloc(n * sizeof(char));

    // Copy data from csrc[] to temp[]
    for (int i=0; i<n; i++)
        temp[i] = csrc[i];

    // Copy data from temp[] to cdest[]
    for (int i=0; i<n; i++)
        cdest[i] = temp[i];

    free(temp);
}
