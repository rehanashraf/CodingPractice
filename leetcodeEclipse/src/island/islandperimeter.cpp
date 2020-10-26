//
//  islandperimeter.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/7/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <utility>

#include "print.h"

bool runIslandPerimeter();
int islandPerimeter(std::vector<std::vector<int>>& grid);
//std::vector<std::vector<int>> getAdjacent(int row, int col, int maxRow, int maxCol);
std::vector<std::pair<int, int>> getAdjacent(int row, int col, int maxRow, int maxCol);

bool runIslandPerimeter() {
    bool rv = true;
    
    std::vector<std::pair<int, int>> listofpairs = getAdjacent(2, 0, 3, 3);
    printPairs(listofpairs);
    std::vector<std::vector<int>> grid = {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    
//    std::cout << islandPerimeter(grid);
    
    return rv;
}

std::vector<std::pair<int, int>> getAdjacent(int row, int col, int maxRow, int maxCol) {
    std::vector<std::pair<int, int>> rv;
  
    if (row >= maxRow || col >= maxCol)
        return rv;
    
    for (int dx = (row > 0 ? -1 : 0); dx <= (row <= maxRow ? 1 : 0); ++dx)
    {
        for (int dy = (col > 0 ? -1 : 0); dy <= (col <= maxCol ? 1 : 0); ++dy)
        {
            /* if want all including diagnals then  (dx != 0 || dy != 0)
             * if want only diagnals then           (dx != 0 || dy != 0) && (dx != 0 && dy != 0)
             * if want all except diagnals          (dx != 0 || dy != 0) && !(dx != 0 && dy != 0)
             */
            if ((dx != 0 || dy != 0) && !(dx != 0 && dy != 0))
            {
                rv.push_back(std::make_pair(row + dx, col + dy));
            }
        }
    }

    return rv;
}

int islandPerimeter(std::vector<std::vector<int>>& grid) {
    int rv, withLand;
    size_t maxRows, maxCols;
    std::vector<std::pair<int, int>> adjacentBlocks;
    
    rv = maxRows = maxCols = withLand = 0;
    maxRows = grid.size();
    
    for (int i = 0; i < maxRows; i++) {
        maxCols = grid[i].size();
        for (int j = 0; j < maxCols; j++) {
            withLand = 0;
            adjacentBlocks = getAdjacent(i, j, maxRows, maxCols);
            for (int k =0; k < adjacentBlocks.size(); k++) {
                if(grid[adjacentBlocks[k].first][adjacentBlocks[k].second] == 1)
                    withLand++;
            }
            rv += 4 - withLand;
        }
    }
    
    return rv;
}
