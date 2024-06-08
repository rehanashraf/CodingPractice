//
//  reverselinklist.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/14/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 Reverse a singly linked list.

 Example:

 Input: 1->2->3->4->5->NULL
 Output: 5->4->3->2->1->NULL
 Follow up:

 A linked list can be reversed either iteratively or recursively. Could you implement both?
 */
#include <stdio.h>
#include "print.h"

bool runReverseList(void);
ListNode* reverseList(ListNode* head);


ListNode* rList(ListNode* head) {
    ListNode *previous, *temp;

    if (head == NULL) {
        return head;
    }
    
    previous = temp = NULL;
    while (head && head->next) {
        temp = head->next;
        head->next = previous;
        previous = head;
        head = temp;
    }
    head->next = previous;
    
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode *rv = nullptr, *previous = nullptr, *temp = nullptr;
    
    if (head == nullptr)
        return rv;
    else if (head->next == nullptr)
    {
        rv = head;
        return rv;
    }
    
    rv = head;
    temp = head;
    while(rv)
    {
        temp = rv;
        rv = rv->next;
        temp->next = previous;
        previous = temp;
    }

    rv = previous;
    return rv;
}

bool runReverseList(void)
{
    bool rv = true;
    ListNode *list1, *list2, *iterator1, *iterator2 = nullptr;
    list1 = iterator1 = new ListNode(1);
    list2 = iterator2 = new ListNode(2);
    
    for(int i = 1; i <= 3; i++)
    {
        iterator1->next = new ListNode(i*2);
        iterator2->next = new ListNode(i*3);
        
        iterator1 = iterator1->next;
        iterator2 = iterator2->next;
    }
    iterator1 = iterator2 = nullptr;
    
    printList(list1);
    printList(list2);
    reverseList(list1);
    reverseList(list2);
    printList(list1);
    printList(list2);
    return rv;
}
