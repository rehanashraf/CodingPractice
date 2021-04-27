//
//  main.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 11/29/19.
//  Copyright © 2019 Rehan Ashraf. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "main.h"
#include "playground.h"
#include "print.h"
#include "utility.h"

int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";

    for (int i = 0; i < 0; ++i)
        std::cout << "Hello World " << i << std::endl;
        // insert code here...
//    runMaxProfit();
    runRehanStack();
    return 0;
}

inline void shiftRight(vector<int>& arr, int index) {
    for (size_t i = arr.size() - 1; i > index; i--) {
        arr[i] = arr[i-1];
    }
}

void duplicateZeros(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            shiftRight(arr, i);
            i +=2;
        }
    }
}

//char* removeExt(const char *data) {
//    int length = strchr(data, '.') - data + 1;
//    char temp[length];
//
//
//    return temp;
//}

ListNode* oddEvenList(ListNode* head) {
    ListNode *odd = NULL, *even = NULL, *ehead = NULL;

    if (head == NULL || head->next == NULL) {
        return head;
    }
    odd = head;
    ehead = even = head->next;

    while (odd->next->next && even->next->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    if (odd->next->next) {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = NULL;
    }
    odd->next = ehead;
    return head;
}

void addListNode(ListNode *head, int val) {
    while(head != NULL && head->next != NULL) {
        head = head->next;
    }
    head->next = new ListNode(val);
}

void runOddEvenList()
{
    ListNode head(1);
    for (int i = 2; i < 6; i++) {
        addListNode(&head, i);
    }
    printList(&head);
    oddEvenList(&head);
    printList(&head);
}

bool isBadVersion(int numeber) {
    static bool var = false;
    var = !var;
    return var;
}

int firstBadVersion(int n)
{
    int result, start, end, mid;

    result = -1;
    start = 0;
    end = n;

    while (start <= end)
    {
        mid = start + (end -start)/2;
        if (isBadVersion(mid))
        {
            result = mid;
            end = mid -1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}
