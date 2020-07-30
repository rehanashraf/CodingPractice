//
//  print.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 12/1/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

#include "print.h"


void printVector(std::vector<int>& list)
{
    std::vector<int>::iterator it;
    std::cout << "Vector contains:";

    for (it=list.begin(); it<list.end(); it++)
        std::cout << ' ' << *it;

    std::cout << '\n';
}

void printVector(std::vector<char>& list)
{
    std::vector<char>::iterator it;
    std::cout << "Vector contains:";

    for (it=list.begin(); it<list.end(); it++)
        std::cout << ' ' << *it;

    std::cout << '\n';
}

void printVector(std::vector<std::string>& list)
{
    std::vector<std::string>::iterator it;
    std::cout << "Vector contains:";

    for (it=list.begin(); it<list.end(); it++)
        std::cout << ' ' << *it;

    std::cout << '\n';
}

void printList(ListNode *list)
{
    if (list == nullptr)
    {
        return;
    }
    
    while(list->next)
    {
        std::cout << list->val << "->";
        list = list->next;
    }
    std::cout<< list->val << std::endl;
}

//template <typename T>
//void printVector(std::vector<T>& list)
//{
//    typedef typename std::vector<T>::iterator iterator;
//    iterator it;
//    std::cout << "Vector contains:";
//
//    for (it=list.begin(); it<list.end(); it++)
//        std::cout << ' ' << *it;
//
//    std::cout << '\n';
//}

void Myprintf(char* format,...)
{
    char *traverse;
    unsigned int i;
    char *s;

    //Module 1: Initializing Myprintf's arguments
    va_list arg;
    va_start(arg, format);

    for(traverse = format; *traverse != '\0'; traverse++)
    {
        while( *traverse != '%' )
        {
            putchar(*traverse);
            traverse++;
        }

        traverse++;

        //Module 2: Fetching and executing arguments
        switch(*traverse)
        {
            case 'c' : i = va_arg(arg,int);        //Fetch char argument
                        putchar(i);
                        break;

            case 'd' : i = va_arg(arg,int);         //Fetch Decimal/Integer argument
                        if(i<0)
                        {
                            i = -i;
                            putchar('-');
                        }
                        puts(convert(i,10));
                        break;

            case 'o': i = va_arg(arg,unsigned int); //Fetch Octal representation
                        puts(convert(i,8));
                        break;

            case 's': s = va_arg(arg,char *);         //Fetch string
                        puts(s);
                        break;

            case 'x': i = va_arg(arg,unsigned int); //Fetch Hexadecimal representation
                        puts(convert(i,16));
                        break;
        }
    }

    //Module 3: Closing argument list to necessary clean-up
    va_end(arg);
}

char *convert(unsigned int num, int base)
{
    static char Representation[]= "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do
    {
        *--ptr = Representation[num%base];
        num /= base;
    }while(num != 0);

    return(ptr);
}

void print2DVector(std::vector<std::vector<char>> &grid)
{
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void print2DVector(std::vector<std::vector<int>> &grid)
{
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printPairs(std::vector<std::pair<int, int>> &list) {
    std::cout << "{";
    for (int i = 0; i < list.size(); i++) {
        std::cout << "(" << list[i].first << "," << list[i].second << ")";
    }
    std::cout << "}"  << std::endl;
}
