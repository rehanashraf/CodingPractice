//
//  ListNode.cpp
//  lt
//
//  Created by Ashraf, Rehan on 3/17/21.
//

#include "../../include/templates/ListNode.h"

#include <stdio.h>

template <typename T>

ListNode<T>::ListNode(T dataIn)
{
    data = dataIn; //stores data in node
    next = nullptr; //initializes point to next node to null
#ifdef ENABLE_DOUBLE_LINK_LIST
    previous = nullptr;
#endif
}

template <typename T>
T ListNode<T>::getData() //returns data stored in node
{
    return data;
}
