//
//  numberofislands.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 1/9/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/**
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

#include <stdio.h>
#include <vector>
#include <iostream>

#include "print.h"
int numIslands(std::vector<std::vector<char>>& grid);
bool runNumIslands();
std::vector<Point>  getAdjacent(Point &p, int rows, int cols);
int numIslands(std::vector<std::vector<char>>& grid)
{
    int rv = 0;
    size_t rows = 0, cols = 0;
    
    rows = grid.size();
    cols = grid[0].size();
    
    if((rows == 0) && (cols == 0))
    {
        return 0;
    }
    
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(grid[i][j] == '1')
            {
//                std::vector<Point> list;
//                Point currentPoint(i,j);
                
            }
        }
    }
    return rv;
}

bool runNumIslands()
{
    bool rv = true;
    
    
    return rv;
}

std::vector<Point> getAdjacent(Point &p, int rows, int cols)
{
    std::vector<Point> rv;
    if(p.x > 0 )
    {
        Point temp;
        if(p.x < rows)
        {
            temp.x = 1;
        }
    }
    else
    {

    }

    return rv;
}
