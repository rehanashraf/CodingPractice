/*
 * rotate.cpp
 *
 *  Created on: Oct 23, 2020
 *      Author: rehanashraf
 */

#define M 3
#define N 4

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

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
void rotate90Clockwise(int a[N][N])
{

    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {

            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
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
