//
//  deletenodeinlinklist.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/11/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

#include <stdio.h>
#include"print.h"

bool runDeleteNode();
void deleteNode(ListNode* node, int x);

void deleteNode(ListNode* node, int x)
{
    ListNode* temp;
    if (node->next == NULL)
        return;
    temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
    
    return;
}

bool runDeleteNode()
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
    
    printList(list1);
    printList(list2);
    deleteNode(list1, 6);
    deleteNode(list2, 8);
    printList(list1);
    printList(list2);
    return true;
}
