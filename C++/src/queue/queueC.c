//
//  queueC.c
//  leetcode
//
//  Created by Rehan Ashraf on 12/10/21.
//

//system includes

//local includes
#include "queueC.h"
#include "utility.h"

errors_e queue_init(queue_t *queue, size_t size)
{
    errors_e err = ERROR_OK;
    
    if (queue == NULL){
        err = ERROR_NULL_POINTER;
        return err;
    }
    if (size <= 0) {
        err = ERROR_WRONG_SIZE;
        return err;
    }
    
    queue->buffer = (QUEUE_TYPE*)calloc(size, sizeof(QUEUE_TYPE));
    if (queue->buffer == NULL) {
        err = ERROR_NOT_ENOUGH_MEMORY;
        return err;
    }
    queue->capacity = size;
    queue->size = queue->front = queue->back = 0;
    
    return err;
}

errors_e queue_enqueue(queue_t *queue, QUEUE_TYPE *data_array, size_t length)
{
    errors_e err = ERROR_OK;
    
    if (queue == NULL || data_array == NULL) {
        err = ERROR_NULL_POINTER;
        return  err;
    }
    
    if (length > (queue->capacity - queue->size)) {
        err = ERROR_WRONG_SIZE;
        return err;
    }
    
    for (size_t i = 0; i < length; i++ ){
        queue->back = data_array[i];
        queue->back = (queue->back + 1)  % queue->capacity;
        queue->size++;
    }
    
    return err;
}
errors_e queue_dequeue(queue_t *queue, QUEUE_TYPE *data_array, size_t length)
{
    return 0;
}
errors_e queue_isFull(queue_t *queue, bool *isFull);
errors_e queue_size(queue_t *queue, size_t *size);
errors_e queue_capacity(queue_t *queue, size_t *cap);

