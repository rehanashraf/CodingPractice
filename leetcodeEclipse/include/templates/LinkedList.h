//
//  LinkedList.hpp
//  lt
//
//  Created by Ashraf, Rehan on 3/17/21.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include "ListNode.h"

using namespace std;

template <typename T>
class LinkedList {
public:
    
    LinkedList();
    ~LinkedList();
    void insertNewNode(T); //fucntion used to insert new node in order in the list
    void print(); //prints the contents of the linked list
    ListNode<T>* search(T); //searches for a value in the linked list and returns the point to object that contains that value
    T get(int index);
    void addAtIndex(int index, T val);
    void deleteAtIndex(int index);
    bool isEmpty(); //utility functions used to see if the list contains no elements
    int getSize();
private:
    ListNode<T> *head; //stores the pointer of first object in the linked list
    ListNode<T> *tail; //stored the pointer of the last object in the linked list
    int size;
    void insertBegin(T); //inserts new node before the first node in the list
    void insertEnd(T); //inserts new node after the last node in the list
};

#endif /* LinkedList_hpp */
