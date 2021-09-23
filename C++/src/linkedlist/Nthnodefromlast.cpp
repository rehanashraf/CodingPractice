/*
 * Nthnodefromlast.cpp
 *
 *  Created on: Oct 19, 2020
 *      Author: rehanashraf
 */

#include "print.h"

ListNode *getKNodeFromEnd(ListNode *head, int n)
{
    ListNode *rv, *temp;
	int len = 0;
    rv = temp = NULL;

	temp = head;
	/* Two pass */
	while(temp != NULL)
	{
		temp = temp->next;
		len++;
	}

	temp = head;
	for (int i = 0; i < len - n -1 ; i++)
	{
		temp = temp->next;
	}

    temp->next = temp->next->next;

    /* One Pass but has issues */
#if 0

    ListNode *first, *second;

    first = second = NULL;

    first = second = head;
    for (int i = 0; i < n; i++)
        first = first->next;

    while(first != NULL && first->next != NULL)
    {
        first = first->next;
        second = second->next;
    }

    second->next = second->next->next;

    return head;
#endif

	return head;
}

void printNthFromLastRecursion(struct ListNode* head, int n)
{
    static int i = 0;
    if (head == NULL)
        return;
    printNthFromLastRecursion(head->next, n);
    if (++i == n)
        printf("%d", head->val);
}

void printNthFromLast(struct ListNode* head, int n)
{
    int len = 0, i;
    struct ListNode* temp = head;

    // count the number of nodes in Linked List
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }

    // check if value of n is not
    // more than length of the linked list
    if (len < n)
        return;

    temp = head;

    // get the (len-n+1)th node from the beginning
    for (i = 1; i < len - n + 1; i++)
        temp = temp->next;

    cout << temp->val;

    return;
}
