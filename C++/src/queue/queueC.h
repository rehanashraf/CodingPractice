//
//  queueC.h
//  leetcode
//
//  Created by Rehan Ashraf on 12/10/21.
//

#ifndef queueC_h
#define queueC_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "utility.h"

/* Defines to enable what type data do you wnat to use in the queue currently we will be using uint8_t */
#define QUEUE_UINT8
//#define QUEUE_UCHAR

#ifdef QUEUE_UINT8
#define QUEUE_TYPE  uint8_t
#elif QUEUE_UCHAR
#define QUEUE_TYPE  unsigned char
#endif

typedef struct queue{
    size_t size, capacity;
    uint32_t front, back;
    QUEUE_TYPE *buffer;
}queue_t;

errors_e queue_init(queue_t *queue, size_t size);
errors_e queue_enqueue(queue_t *queue, QUEUE_TYPE *data_array, size_t length);
errors_e queue_dequeue(queue_t *queue, QUEUE_TYPE *data_array, size_t length);
errors_e queue_isFull(queue_t *queue, bool *isFull);
errors_e queue_size(queue_t *queue, size_t *size);
errors_e queue_capacity(queue_t *queue, size_t *cap);

#endif /* queueC_h */
