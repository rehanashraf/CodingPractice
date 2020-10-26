//
//  palindromelkinkedlist.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/14/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
 Given a singly linked list, determine if it is a palindrome.

 Example 1:

 Input: 1->2
 Output: false
 Example 2:

 Input: 1->2->2->1
 Output: true
 Follow up:
 Could you do it in O(n) time and O(1) space?
 */

#include <stdio.h>
#include "print.h"
#include <vector>

bool runIsPalindrome(void);
bool isLinkedListPalindrome(ListNode* head);

bool isLinkedListPalindrome(ListNode* head) {
    bool rv = true;
    std::vector<int> array;
    ListNode *iterator;
    
    iterator = head;
    
    if (iterator == nullptr || iterator->next == nullptr)
    {
        rv = false;
        return rv;
    }
    while (iterator)
    {
        array.push_back(iterator->val);
        iterator = iterator->next;
    }
    
    iterator = head;
    for(int i = array.size(); i >= 0; i--)
    {
        if (array[i] != iterator->val)
        {
            rv = false;
            return rv;
        }
    }
    
    return rv;
}

bool runIsLinkedListPalindrome(void)
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
    std::cout << isLinkedListPalindrome(list1) << std::endl;
    std::cout << isLinkedListPalindrome(list2) << std::endl;
    
    return rv;
}
