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
	size_t top, bottom, right, left, size;

	if (matrix.size() == 0)
		return rv;

	top = 0;
	bottom = matrix.size() -1;
	left = 0;
	right = matrix[0].size() -1;

	size = matrix.size() * matrix[0].size();

	while(rv.size() < size)
	{
		for(uint8_t i = left; i <= right && rv.size() < size; i++)
		{
			rv.push_back(matrix[top][i]);
		}
		top++;

		for(uint8_t i = top; i <= bottom && rv.size() < size; i++)
		{

			rv.push_back(matrix[i][right]);
		}
		right--;

		for (uint8_t i = right; i >= left && rv.size() < size;i--)
		{
			rv.push_back(matrix[bottom][i]);
		}
		bottom--;

		for(uint8_t i = bottom; i >= top && rv.size() < size;i--)
		{
			rv.push_back(matrix[i][left]);
		}
		left++;
	}

	return rv;
}

