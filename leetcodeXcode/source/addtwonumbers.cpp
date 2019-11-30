//
//  addtwonumbers.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 11/29/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

/*
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

 You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 Example:

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 Explanation: 342 + 465 = 807.
 */
#include <stdio.h>
#include <iostream>

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *head, *iterator = nullptr;
    int sum = 0;
    head = iterator = new ListNode(-1);
    
    while((l1 != nullptr) || (l2 !=nullptr) || (sum))
    {

        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        
        if(sum > 9)
        {
            iterator->next = new ListNode(sum - 10);
            sum = 1;
        }
        else
        {
            iterator->next = new ListNode(sum);
            sum = 0;
        }
        iterator = iterator->next;

    }
    
    return head->next;
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

bool runAddTwoNumbers()
{
    ListNode *list1, *list2, *iterator1, *iterator2 = nullptr;
    list1 = iterator1 = new ListNode(1);
    list2 = iterator2 = new ListNode(2);
    
    for(int i = 1; i < 3; i++)
    {
        iterator1->next = new ListNode(i*2);
        iterator2->next = new ListNode(i*3);
        
        iterator1 = iterator1->next;
        iterator2 = iterator2->next;
    }
    iterator1 = iterator2 = nullptr;
    
    ListNode *rv = nullptr;
    printList(list1);
    printList(list2);
    rv = addTwoNumbers(list1, list2);
    printList(rv);
    return true;
}


