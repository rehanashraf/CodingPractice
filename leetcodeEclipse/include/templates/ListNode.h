//
//  Node.h
//  lt
//
//  Created by Ashraf, Rehan on 3/17/21.
//

#ifndef LIST_NODE_H
#define LIST_NODE_H

#define ENABLE_DOUBLE_LINK_LIST
template <typename T>
class List;

template <typename T>
class ListNode //nodes to be contained with a list
{
    friend class List<T>;

public:
    ListNode(T);
    T getData();

private:
    T data; //templatized data stored in node
    ListNode* next; //pointer to the next node in list
#ifdef ENABLE_DOUBLE_LINK_LIST
    ListNode* previous;
#endif
};

#endif
