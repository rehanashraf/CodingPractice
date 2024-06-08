/*
 * spiralorder.cpp
 *
 *  Created on: Aug 14, 2020
 *      Author: rehanashraf
 */

#include "print.h"

#include <iostream>
#include <vector>



std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
    std::vector<int> rv;
	int top, bottom, right, left, size;

	if (matrix.size() == 0)
		return rv;

	top = 0;
	bottom = matrix.size() -1;
	left = 0;
	right = matrix[0].size() -1;

	size = matrix.size() * matrix[0].size();

	while(rv.size() < size)
	{
		for(int i = left; i <= right && rv.size() < size; i++)
		{
			rv.push_back(matrix[top][i]);
		}
		top++;

		for(int i = top; i <= bottom && rv.size() < size; i++)
		{

			rv.push_back(matrix[i][right]);
		}
		right--;

		for (int i = right; i >= left && rv.size() < size;i--)
		{
			rv.push_back(matrix[bottom][i]);
		}
		bottom--;

		for(int i = bottom; i >= top && rv.size() < size;i--)
		{
			rv.push_back(matrix[i][left]);
		}
		left++;
	}

	return rv;
}

vector<vector<int>> generateMatrix(int n) {
    std::vector<int> rv;
    vector<vector<int>> temp;
    int top, bottom, right, left, size;
    int count = 1;
    
    top = 0;
    bottom = n - 1;
    left = 0;
    right = n - 1;
    
    size = n * n;
    for (int i = 0; i < n; i++) {
        vector<int> vec;
        for (int j = 0; j < n; j++) {
            vec.push_back(count++);
        }
        temp.push_back(vec);
    }
    count = 1;
    while (count <= size) {
        for (int i = left; i <= right && count <= size; i++) {
            temp[top][i] = count++;
        }
        top++;
        
        for (int i = top; i <= bottom && count <= size; i++) {
            temp[i][right] = count++;
        }
        right--;
        
        for (int i = right; i >= left && count <= size; i--) {
            temp[bottom][i] = count++;
        }
        bottom--;
        
        for (int i = bottom; i >= top && count <= size; i--) {
            temp[i][left] = count++;
        }
        left++;
    }
    return temp;
}
