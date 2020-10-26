/*
 * douplepointer.cpp
 *
 *  Created on: Sep 16, 2020
 *      Author: rehanashraf
 */

#include<stdlib.h>
#include<stdio.h>

#define ROWS 5
#define COLS 5

void usingCPlusPlus(void)
{

}


void usingC(void)
{
	int rows = ROWS, cols = COLS;
	int count = 0;

	/* Using a single pointer */
	int *spointer = (int *)malloc(rows * cols * sizeof(int));

	for(int i = 0; i < rows; i++)
	{
		for(int j = 0; j < cols; j++)
		{
			*(spointer + i*rows + j) = count;
			count++;
		}
	}

	printf("\nUsing single Pointer\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%02i ", *(spointer + i*rows + j));
		}
		printf("\n");
	}

	/* Using an array of pointers (You will need to know the number of rows here) */
	int *apointer[rows];

	for (int i = 0; i < rows; i++)
	{
		apointer[i] = (int *)malloc(cols * (sizeof(int)));
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			apointer[i][j] = count++;
		}
	}

	printf("\nArray of pointers example.\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%i ", apointer[i][j]);
		}
		printf("\n");
	}

	/* Using double pointer */
	int **dpointer = (int **)malloc(rows * (sizeof(int *)));

	for (int i = 0; i < rows; i++)
	{
		dpointer[i] = (int *)malloc(cols * (sizeof(int)));
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			dpointer[i][j] = count++;
		}
	}

	printf("\nUsing Double Pointer.\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%i ", dpointer[i][j]);
		}
		printf("\n");
	}

	/* Using Double pointer as well as one malloc call */
	int **donepointer = (int **)malloc(rows * (sizeof(int*)) + rows*cols*(sizeof(int)));
	int *ptr = (int *)(donepointer + rows);

	for (int i = 0; i < rows; i++)
	{
		donepointer[i] = ptr + cols*i;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			donepointer[i][j] = count++;
		}
	}

	printf("\nUsing Double Pointer with one malloc call\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ",donepointer[i][j]);
		}
		printf("\n");
	}

}
