//
//  print.hpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/1/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

#ifndef print_hpp
#define print_hpp

#include <stdio.h>

#include <iostream>
#include <vector>
#include <utility>
#include <cstdarg>

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct Point
{
    int x;
    int y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
};

//template <typename T>
void printVector(std::vector<int>& list);
void printVector(std::vector<char>& list);
void printVector(std::vector<std::string>& list);
void printList(ListNode *list);
void Myprintf(char *,...);                 //Our printf function
char* convert(unsigned int, int);         //Convert integer number into octal, hex, etc.
void print2DVector(std::vector<std::vector<char>> &grid);
void print2DVector(std::vector<std::vector<int>> &grid);
void printPairs(std::vector<std::pair<int, int>> &list);

template <typename T>
void printTVector(const std::vector<T>& list)
{
    for(int i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
}

template <typename T>
void print2DTVector(const std::vector<const std::vector<T>>& list)
{
    for(int i = 0; i < list.size(); i++)
    {
        printTVector(list[i]);
        std::cout << std::endl;
    }
}

#endif /* print_hpp */
