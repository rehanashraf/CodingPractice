/*
 * stackCimpl.cpp
 *
 *  Created on: Oct 18, 2020
 *      Author: rehanashraf
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdint.h>

struct stack
{
	int top, capacity;
	char *buffer;
};

typedef struct stack cstack_t;

int stack_init(cstack_t *stack,int size);
int stack_top(cstack_t *stack, char *ch);
int stack_pop(cstack_t *stack, char *data, int bytes);
int stack_push(cstack_t *stack, const char *data, int bytes);
int stack_cleanup(cstack_t *stack);

int stack_init(cstack_t *stack,int size)
{
	int rv = -1;
	char *buf;
	if (stack == NULL || size == 0)
		return rv;

	buf = (char *)malloc(sizeof(char)* size);
	if (buf == NULL)
		return rv;

	stack->buffer = buf;
	stack->top = 0;
	stack->capacity = size;
	rv = 0;

	return rv;
}

bool stack_isempty(cstack_t *stack)
{
	bool rv = false;
	rv = stack->top == 0;
	return rv;
}

bool stack_isfull(cstack_t *stack)
{
	bool rv = false;
	rv = stack->top == stack->capacity;
	return rv;
}

int stack_top(cstack_t *stack, char *ch)
{
	int rv = -1;

	if (stack == NULL || ch == NULL || stack_isempty(stack))
		return rv;

	*ch = stack->buffer[stack->top-1];
	rv = 0;

	return rv;
}

int stack_pop(cstack_t *stack, char *data, int bytes)
{
	int rv = -1;

	if (bytes > stack->top)
		bytes = stack->top;

	for (int i = 0; i < bytes; i++)
	{
		data[i] = stack->buffer[--stack->top];
	}
	rv = bytes;
	return rv;
}

int stack_cleanup(cstack_t *stack)
{
	int rv = -1;

	if (stack == NULL)
		return rv;

	for(int i = 0; i < stack->capacity; i++)
	{
		stack->buffer[i] = 0;
	}

	stack->top = 0;
	free(stack->buffer);
	stack->buffer = NULL;
	stack->capacity = 0;

	return rv;
}

int stack_push(cstack_t *stack, const char *data, int bytes)
{
	int rv = -1;

	if (stack == NULL || data == NULL || stack_isfull(stack))
		return rv;

	if (bytes > (stack->capacity - stack->top))
		bytes = stack->capacity - stack->top;
	for (int i = 0; i < bytes; i++)
	{
		stack->buffer[stack->top++] = data[i];
	}

	rv = bytes;
	return rv;
}

bool runRehanStack(void)
{
	cstack_t st;
	char buf[10] = {0};
	assert(stack_init(&st, 10) == 0);


    assert(stack_push(&st, "abcdefg", 7) == 7);
    assert(stack_top(&st,buf) == 0);
    assert(stack_push(&st, "hijklmn", 7) == 3);

    assert(stack_pop(&st, buf, 6) == 6);
    assert(strncmp(buf, "jihgfe", 6) == 0);

    assert(stack_push(&st, "klm", 3) == 3);
    assert(stack_pop(&st, buf, 10) == 7);

    assert(strncmp(buf, "mlkdcba", 7) == 0);

    return true;
}



