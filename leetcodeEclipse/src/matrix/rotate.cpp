/*
 * rotate.cpp
 *
 *  Created on: Oct 23, 2020
 *      Author: rehanashraf
 */

#define M 3
#define N 4
#include <vector>
#include "utility.h"

void rotateMatrix(int mat[][N]);
void rotate90Clockwise(int a[N][N]);

void transposefromleft(std::vector<std::vector<int>>& matrix);
void rotate90AntiClockwise(std::vector<std::vector<int>>& matrix);
void swapCols(std::vector<std::vector<int>>& matrix)
void transposefromright(std::vector<std::vector<int>>& matrix)

void rotateMatrix(int mat[][N])
{
	// Consider all squares one by one
	for (int x = 0; x < N / 2; x++) {
		// Consider elements in group
		// of 4 in current square
		for (int y = x; y < N - x - 1; y++) {
			// Store current cell in
			// temp variable
			int temp = mat[x][y];

			// Move values from right to top
			mat[x][y] = mat[y][N - 1 - x];

			// Move values from bottom to right
			mat[y][N - 1 - x]
				   = mat[N - 1 - x][N - 1 - y];

			// Move values from left to bottom
			mat[N - 1 - x][N - 1 - y]
						   = mat[N - 1 - y][x];

			// Assign temp to left
			mat[N - 1 - y][x] = temp;
		}
	}
}

// Function to rotate the matrix 90 degree clockwise
// you can do that with (transpose or transposeleft) and then (reverse items in rows or swap cols)
// you can also do this by (reverse items in rows or swap cols) and transposeright
void rotate90Clockwise(std::vector<std::vector<int>>& matrix)
{

	// Traverse each cycle
/*	for (int i = 0; i < N / 2; i++) {
		for (int j = i; j < N - i - 1; j++) {

			// Swap elements of each cycle
			// in clockwise direction
			int temp = a[i][j];
			a[i][j] = a[N - 1 - j][i];
			a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = temp;
		}
	}*/

	int rows, cols;
	rows = matrix.size();
	cols = matrix[0].size();

	transposefromleft(matrix);
	swapCols(matrix);

}

// you can do that by (reverse items in rows or swap cols) and then (transpose or transposeleft)
void rotate90AntiClockwise(std::vector<std::vector<int>>& matrix)
{
	int rows, cols;
	rows = matrix.size();
	cols = matrix[0].size();

	swapCols(matrix);
	transposefromleft(matrix);

}

// This function stores transpose of A[][] in B[][]
void transpose(int A[][N], int B[][M])
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			B[i][j] = A[j][i];
}

void transpose(int A[][N])
{
	for (int i = 0; i < N; i++)
		for (int j = i+1; j < N; j++)
			swap(A[i][j], A[j][i]);
}

void sawpCols(int a[][N])
{
	int temp;
	for (int i = 0;i < N; i++)
	{
		for (int j = 0; j < N/2; j++)
		{
			temp = a[i][j];
			a[i][j] = a[i][N-j-1];
			a[i][N-j-1] = temp;
		}
	}
}

void swapCols(std::vector<std::vector<int>>& matrix)
{
	int rows, cols;
	rows = matrix.size();
	cols = matrix[0].size();

	for(int i = 0; i < rows; i++)
		for (int j = 0, k = cols - 1; j < cols/2; j++, k--)
			swap(matrix[i][j], matrix[i][k]);

}

void transposefromright(std::vector<std::vector<int>>& matrix)
{
	int rows, cols;
	rows = matrix.size();
	cols = matrix[0].size();

	for (int i = 0; i < rows ; i++)
		for (int j = i+1; j < cols; j++)
			swap(matrix[i][cols -j -1], matrix[j][cols -i -1]);
}

void transposefromleft(std::vector<std::vector<int>>& matrix)
{
	int rows, cols;
	rows = matrix.size();
	cols = matrix[0].size();

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			swap(matrix[i][j], matrix[j][i]);
}
