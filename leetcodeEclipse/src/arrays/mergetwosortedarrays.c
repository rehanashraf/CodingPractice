/*
 * mergetwosortedarrays.c
 *
 *  Created on: Oct 19, 2020
 *      Author: rehanashraf
 */
#include <stdlib.h>
#include <stdint.h>

uint32_t ArrayMerge(uint32_t Asize, uint32_t *A, uint32_t Bsize, uint32_t *B, uint32_t *C) {

	if (C == NULL)
	{
		return 0;
	}
	else if ((A == NULL) && (B == NULL))
	{
		return 0;
	}

	uint32_t a_pointer = 0;
	uint32_t b_pointer = 0;
	uint32_t c_pointer = 0;

	while ((a_pointer < Asize) && (b_pointer < Bsize))
	{
		if (A[a_pointer] < B[b_pointer])
		{

			if (c_pointer > 0)
			{
				if (C[c_pointer - 1] != A[a_pointer])
				{
					C[c_pointer] = A[a_pointer];
					a_pointer++;
					c_pointer++;
				}
				else
				{
					// Detected a duplicate....
					a_pointer++;
				}
			}
			else
			{
				C[c_pointer] = A[a_pointer];
				a_pointer++;
				c_pointer++;
			}
		}
		else
		{

			if (c_pointer > 0)
			{
				if (C[c_pointer - 1] != B[b_pointer])
				{
					C[c_pointer] = B[b_pointer];
					b_pointer++;
					c_pointer++;
				}
				else
				{
					// Detected a duplicate....
					b_pointer++;
				}
			}
			else
			{
				C[c_pointer] = B[b_pointer];
				b_pointer++;
				c_pointer++;
			}
		}
	}

	while (a_pointer < Asize)
	{

		if (c_pointer > 0)
		{
			if (C[c_pointer - 1] != A[a_pointer])
			{
				C[c_pointer] = A[a_pointer];
				a_pointer++;
				c_pointer++;
			}
			else
			{
				a_pointer++;
			}
		}
		else
		{
			C[c_pointer] = A[a_pointer];
			a_pointer++;
			c_pointer++;
		}
	}

	while (b_pointer < Bsize)
	{
		if (c_pointer > 0)
		{
			if (C[c_pointer - 1] != B[b_pointer])
			{
				C[c_pointer] = B[b_pointer];
				b_pointer++;
				c_pointer++;
			}
			else
			{
				b_pointer++;
			}
		}
		else
		{
			C[c_pointer] = B[b_pointer];
			b_pointer++;
			c_pointer++;
		}
	}

	return c_pointer;
}

