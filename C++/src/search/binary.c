/*
 * binary.c
 *
 *  Created on: Oct 1, 2020
 *      Author: rehanashraf
 */

#include <stdint.h>

int BinarySearchI(uint8_t *buffer,int *len, uint8_t data)
{
	int rv;
	int  start,end, mid;

	rv = -1;
	start = 0;
	end = *len -1;
	while(start <= end)
	{
		mid = (start + end)/2;
		if (buffer[mid] == data)
		{
			rv = mid;
			return rv;
		}
		else if (data < buffer[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return rv;
}

int BinarySearchR(uint8_t *buffer,int start, int end, uint8_t data)
{
	int rv = -1;
	int mid = start + (end- start)/2;

	if (start > end)
		return rv;
	if (data == buffer[mid])
	{
		rv = mid;
		return mid;
	}
	else if (data < buffer[mid])
	{
		rv = BinarySearchR(buffer, start, mid-1, data);
		return rv;
	}
	else
	{
		rv = BinarySearchR(buffer, mid+1, end, data);
	}
	return rv;
}

int BinarySearchFirstO(uint8_t *buffer,int *len, uint8_t data)
{
	int result, start, end, mid;

	result = -1;
	start = 0;
	end = *len -1;

	while (start <= end)
	{
		mid = start + (end -start)/2;
		if (data == buffer[mid])
		{
			result = mid;
			end = mid -1;
		}
		else if (data < buffer[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return result;
}

int BinarySearchLastO(uint8_t *buffer,int *len, uint8_t data)
{
	int result, start, end, mid;

	result = -1;
	start = 0;
	end = *len -1;

	while (start <= end)
	{
		mid = start + (end -start)/2;
		if (data == buffer[mid])
		{
			result = mid;
			start = mid + 1;
		}
		else if (data < buffer[mid])
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	return result;
}

int countinsortedarray(uint8_t *buffer, int *len, uint8_t data)
{
	int rv = -1;
	int first, last;

	first = last = 0;

	first = BinarySearchFirstO(buffer, len, data);
	last = BinarySearchLastO(buffer, len, data);

	rv = last -first + 1;
	return rv;
}

/* Moores Voting Algorithm */
uint8_t countMajorityElement(uint8_t *buffer, int len)
{
	uint8_t rv = 0;
	uint8_t me = -1;
	int count = 0;

	me = buffer[0];
	count = 1;
	for (int i = 1; i < len; i++)
	{
		if (buffer[i] == me)
		{
			count++;
		}
		else
		{
			count--;
			if(count == 0)
			{
				me = buffer[i];
				count++;
			}
		}
	}

	return rv;
}
