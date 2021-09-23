//
//  removenthnodefromend.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 1/8/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/**
 Given a linked list, remove the n-th node from the end of list and return its head.

 Example:

 Given linked list: 1->2->3->4->5, and n = 2.

 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:

 Given n will always be valid.
 */

#include <stdio.h>
#include "print.h"

ListNode* removeNthFromEnd(ListNode* head, int n);
bool runRemoveNthNodeFromEnd();

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *rv  = NULL, *iterator = NULL, *previous = NULL;
    int totalSize = 0, listlocation = 0;
    
    if((head == NULL) || (n <= 0))
    {
        rv = NULL;
        return rv;
    }
    
    iterator = head;
    
    while(iterator)
    {
        totalSize++;
        iterator = iterator->next;
    }
    
    iterator = head;
    if (n < totalSize)
    {
        listlocation = totalSize - n;
        for (int i = 0; i < listlocation; i++)
        {
            previous = iterator;
            iterator = iterator->next;
        }
        
    }
    
    head = previous? head: iterator->next;
    previous? previous->next = iterator->next: NULL;
    delete iterator;
//    temp = iterator->next;
//    iterator->val = temp->val;
//    iterator->next = temp->next;
//    rv = iterator;
//    delete temp;
  

    return head;
}

bool runRemoveNthNodeFromEnd()
{
    bool rv = true;
    ListNode *list1, *iterator1 = nullptr;
    list1 = iterator1 = new ListNode(1);
    
    for(int i = 1; i < 5; i++)
    {
        iterator1->next = new ListNode(i*2);
        iterator1 = iterator1->next;
    }
    
    printf("Initial List ");
    printList(list1);
    iterator1 = removeNthFromEnd(list1, 10);
    printf("After removing 4th element ");
    printList(iterator1);
    
    iterator1 = NULL;
    
    return rv;
}
