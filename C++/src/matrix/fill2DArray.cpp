//
//  fill2DArray.cpp
//  leetcode
//
//  Created by Rehan Ashraf on 4/3/23.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define SIZE 3

void fillVector(vector<vector<int>> &vec, uint8_t size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        vector<int> temp;
        for(int j = 0; j < size; j++) {
            count++;
            temp.push_back(count);
        }
        vec.push_back(temp);
    }
}

/* Horizontal
1 2 3
4 5 6
7 8 9
*/
void fillVector1(vector<vector<int>> &vec) {
    uint8_t count = 0;
    size_t noOfRows, noOfCols;
    noOfRows = vec.size();
    for (uint16_t i = 0; i < noOfRows; i++) {
        noOfCols = vec[i].size();
        for(int j = 0; j < noOfCols; j++) {
            count++;
            vec[i][j] = count;
        }
    }
}

/* Horizontal
1 4 7
2 5 8
3 6 9
*/
void fillVector2(vector<vector<int>> &vec) {
    size_t noOfRows, noOfCols;
    noOfRows = vec.size();
    for (uint16_t i = 0; i < noOfRows; i++) {
        noOfCols = vec[i].size();
        for(uint16_t j = 0; j < noOfCols; j++) {
            vec[i][j] = (int)(i + j*noOfRows);
        }
    }
}

/* Horizontal
1 6 7
2 5 8
3 4 9
*/
void fillVector3(vector<vector<int>> &vec) {
    size_t noOfRows, noOfCols;
    noOfRows = vec.size();
    for (int i = 0; i < noOfRows; i++) {
        noOfCols = vec[i].size();
        for(int j = 0; j < noOfCols; j++) {
            if (j%2) {
                vec[i][j] = (int)((j+1) * noOfRows -i);
            } else {
                vec[i][j] = (int)((j* noOfRows) + i+1);
            }

        }
    }
}

/* Vertical
1 6 7
2 5 8
3 4 9
*/
void fillVector4(vector<vector<int>> &vec) {
    size_t noOfRows, noOfCols;
    noOfRows = vec.size();
    int count = 0;
    for (int i = 0; i < noOfRows; i++) {
        noOfCols = vec[i].size();
            if (i%2 == 0) {
                for(int j = 0; j < noOfCols; j++) {
                    count++;
                    vec[j][i] = count;
                }
            } else {
                for(int j = noOfCols; j >= 0; j--) {
                    count++;
                    vec[j][i] = count;
                }
            }
    }
}

void printVector(vector<vector<int>> &vec){
        for (int i = 0; i < vec.size(); i++) {
            for(int j = 0; j < vec[i].size(); j++) {
                cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
