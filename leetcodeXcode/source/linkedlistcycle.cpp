//
//  linkedlistcycle.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/15/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

#include <stdio.h>
#include "print.h"

bool runLinkedListHasCycle(void);
bool linkedListHasCycle(ListNode *head);

bool linkedListHasCycle(ListNode *head) {
    bool rv = false;
    ListNode *slowPtr, *fastPtr;
    
    if (head == nullptr || head->next == nullptr)
    {
        rv = false;
        return rv;
    }
    
    slowPtr = head;
    fastPtr = head;
    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (slowPtr == fastPtr)
        {
            rv = true;
            return rv;
        }
    }
    
    return rv;
}

bool runLinkedListHasCycle(void)
{
    bool rv = false;
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
    std::cout << linkedListHasCycle(list1) << std::endl;
    std::cout << linkedListHasCycle(list2) << std::endl;
    
    iterator1->next = list1;
    iterator2->next = list2->next->next;
    
    std::cout << linkedListHasCycle(list1) << std::endl;
    std::cout << linkedListHasCycle(list2) << std::endl;
    return rv;
}
