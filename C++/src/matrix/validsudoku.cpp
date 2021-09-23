//
//  validsudoku.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/5/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 Example 1:

 Input:
 [
   ["5","3",".",".","7",".",".",".","."],
   ["6",".",".","1","9","5",".",".","."],
   [".","9","8",".",".",".",".","6","."],
   ["8",".",".",".","6",".",".",".","3"],
   ["4",".",".","8",".","3",".",".","1"],
   ["7",".",".",".","2",".",".",".","6"],
   [".","6",".",".",".",".","2","8","."],
   [".",".",".","4","1","9",".",".","5"],
   [".",".",".",".","8",".",".","7","9"]
 ]
 Output: true
 Example 2:

 Input:
 [
   ["8","3",".",".","7",".",".",".","."],
   ["6",".",".","1","9","5",".",".","."],
   [".","9","8",".",".",".",".","6","."],
   ["8",".",".",".","6",".",".",".","3"],
   ["4",".",".","8",".","3",".",".","1"],
   ["7",".",".",".","2",".",".",".","6"],
   [".","6",".",".",".",".","2","8","."],
   [".",".",".","4","1","9",".",".","5"],
   [".",".",".",".","8",".",".","7","9"]
 ]
 Output: false
 Explanation: Same as Example 1, except with the 5 in the top left corner being
     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 */
#include <stdio.h>
#include <vector>
#include <iostream>
#include "print.h"
#include "macros.h"
using namespace std;


bool runIsValidSudoku();
bool isValidSudoku(vector<vector<char>>& board);
bool checkSmallGrid(vector<vector<char>>& board);
void printSudoku(vector<vector<int>> &grid);

bool isValidSudoku(vector<vector<char>>& board) {
    bool rv = true;
    vector<int> check = {0,0,0,0,0,0,0,0,0};
//    int xrow = 0 ,xcol = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(ISDIGIT(board[i][j]))
            {
                check[GETDIGIT(board[i][j]) - 1]++;
                if (check[GETDIGIT(board[i][j]) - 1] > 1)
                    return false;
            }
        }
        check = {0,0,0,0,0,0,0,0,0};

        for(int j = 0; j < 9; j++)
        {
            if(ISDIGIT(board[j][i]))
            {
                check[GETDIGIT(board[j][i]) - 1]++;
                if (check[GETDIGIT(board[j][i]) - 1] > 1)
                    return false;
            }
        }
        check = {0,0,0,0,0,0,0,0,0};
    }
    rv = checkSmallGrid(board);
    return rv;
}

bool runIsValidSudoku()
{
    bool rv = true;
    
    vector<vector<char>> list1, list2, list3, list4;
    list1 = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
        print2DVector(list1);
    rv = isValidSudoku(list1);
    cout << "Sudoku is " << rv << endl << endl;
    list2 = {{'8','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    print2DVector(list2);
    rv = isValidSudoku(list2);
    cout << "Sudoku is " << rv << endl << endl;
    
    list3 = {{'.','.','.','3','.','.','.','1','.'},{'.','.','.','.','.','7','.','.','.'},{'.','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','8','2','7','.'},{'1','.','.','.','.','.','.','.','.'},{'.','.','.','5','.','.','.','.','.'},{'2','.','.','.','8','.','.','.','7'},{'7','.','.','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.','.'}};
    print2DVector(list3);
    rv = isValidSudoku(list3);
    cout << "Sudoku is " << rv << endl << endl;
    
    list4 = {{'.','.','.','.','5','.','.','1','.'},{'.','4','.','3','.','.','.','.','.'},{'.','.','.','.','.','3','.','.','1'},{'8','.','.','.','.','.','.','2','.'},{'.','.','2','.','7','.','.','.','.'},{'.','1','5','.','.','.','.','.','.'},{'.','.','.','.','.','2','.','.','.'},{'.','2','.','9','.','.','.','.','.'},{'.','.','4','.','.','.','.','.','.'}};
    print2DVector(list4);
    rv = isValidSudoku(list4);
    cout << "Sudoku is " << rv << endl<< endl ;
    
    return rv;
}

bool checkSmallGrid(vector<vector<char>>& board)
{
    bool rv = true;
    vector<int> check = {0,0,0,0,0,0,0,0,0};
    vector<vector<int>> vertices = {{0,0}, {0,3}, {0,6}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}};
    
    for (int i = 0; i < 9; i++)
    {
        check = {0,0,0,0,0,0,0,0,0};
        for(int j = vertices[i][0]; j < vertices[i][0]+3; j++)
         {
             for(int k = vertices[i][1]; k < vertices[i][1] + 3; k++)
             {
//                 printf(" %d,%d", j,k);
//                 cout << " " << j << "," << k;
                 if(ISDIGIT(board[j][k]))
                 {
                     check[GETDIGIT(board[j][k]) - 1]++;
                     if (check[GETDIGIT(board[j][k]) - 1] > 1)
                     {
//                         cout << "3x3 grid failed at: (" << j << "," << k << "). Value is " << board[j][k] << endl;
                         return false;
                     }

                 }
             }
//             cout << endl;
         }
//        cout << endl;
    }
    return rv;
}
