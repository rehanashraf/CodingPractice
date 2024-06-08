//
//  mergetwosortedlist.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/14/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//
/*
 Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

 Example:

 Input: 1->2->4, 1->3->4
 Output: 1->1->2->3->4->4
 */

#include <stdio.h>
#include "print.h"

bool runMergeTwoLists(void);
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

ListNode* mTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL, *tail = NULL;

        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }
        if (list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }
        tail = head;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) {
            tail->next = list1;
        }
        if (list2) {
            tail->next = list2;
        }
        return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//    ListNode *rv, *it1, *it2, *temp1, *temp2;
    ListNode *rv, *it1, *it2, *temp;
    rv = temp = nullptr;
    
    it1 = l1;
    it2 = l2;
    
    if (it1 == nullptr)
        return it2;
    if (it2 == nullptr)
        return it1;
    
    rv = new ListNode(0);
    temp = rv;
    while(it1 && it2)
    {
        if ( it1->val < it2->val)
        {
            temp->next = new ListNode(it1->val);
            temp = temp->next;
            it1 = it1->next;
        }
        else if (it1->val > it2->val)
        {
            temp->next = new ListNode(it2->val);
                        temp = temp->next;
            it2 = it2->next;
        }
        else
        {
            temp->next = new ListNode(it1->val);
            temp = temp->next;
            temp->next = new ListNode(it2->val);
            temp = temp->next;
            it1 = it1->next;
            it2 = it2->next;
        }
    }
    
    if ((it1 == nullptr) && (it2 != nullptr))
        temp->next = it2;
    else if ((it2 == nullptr) && (it1 != nullptr))
        temp->next = it1;
    
    return rv->next;
}

bool runMergeTwoLists(void)
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
    list1 = mergeTwoLists(list1, list2);
//    reverseList(list2);
    printList(list1);
//    printList(list2);
    return rv;
}
