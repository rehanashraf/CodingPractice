/*
 * cimplementation.cpp
 *
 *  Created on: Oct 17, 2020
 *      Author: rehanashraf
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>


// Rehan Implementation
struct queue{
	int front, back, size, capacity;
	char *buffer;
};

int queue_init(struct queue *queue, int size)
{
	int rv = -1;
	char *buf;

	if (queue == NULL || size == 0)
		return rv;

	buf = (char *)malloc(sizeof(char) * size);
	if (buf == NULL)
		return rv;

	queue->buffer = buf;
	queue->capacity = size;
	queue->front = queue->back = queue->size = 0;
	rv = 0;

	return rv;
}

int queue_enqueue(struct queue *queue, const char *data, int bytes)
{
	int rv = 0;

	if (bytes > (queue->capacity - queue->size))
		bytes = queue->capacity - queue->size;

	for (int i = 0; i < bytes; i++)
	{
		queue->buffer[queue->back] = data[i];
		queue->size = queue->size + 1;
		queue->back = (queue->back + 1) % queue->capacity;
	}
	rv = bytes;
	return rv;
}

int queue_dequeue(struct queue *queue, char *data, int bytes)
{
	int rv = 0;

	if (queue == NULL || data == NULL)
		return rv;

	if (bytes > queue->size)
		bytes = queue->size;

	for(int i = 0; i < bytes; i++)
	{
		data[i] = queue->buffer[queue->front];
		queue->size--;
		queue->front = (queue->front + 1)% queue->capacity;
	}
	rv = bytes;
	return rv;
}

bool queue_isfull(struct queue *queue)
{
	bool rv = false;
	rv = queue->size == queue->capacity;

	return rv;
}

bool queue_isempty(struct queue *queue)
{
	bool rv = false;
	rv = queue->size == 0;

	return rv;
}

bool runRehanQueue(void) {
    char buf[10] = {0};

    struct queue queue;
    assert(queue_init(&queue, 10) == 0);

    assert(queue_enqueue(&queue, "abcdefg", 7) == 7);
    assert(queue_enqueue(&queue, "hijklmn", 7) == 3);

    assert(queue_dequeue(&queue, buf, 6) == 6);
    assert(strncmp(buf, "abcdef", 6) == 0);

    assert(queue_enqueue(&queue, "klm", 3) == 3);
    assert(queue_dequeue(&queue, buf, 10) == 7);
    assert(strncmp(buf, "ghijklm", 7) == 0);
    return true;
}





// Geeks for Geeks Implementation

// A structure to represent a queue
struct Queue {
    int8_t front, rear, size, capacity;
    int* array;
};

// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned int capacity)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)% queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

// Driver program to test above functions./
int main1()
{
    struct Queue* queue = createQueue(1000);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n\n",
           dequeue(queue));

    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    return 0;
}



