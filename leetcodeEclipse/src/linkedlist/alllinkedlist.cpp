/*
 * alllinkedlist.cpp
 *
 *  Created on: Sep 30, 2020
 *      Author: rehanashraf
 */

#include <stdio.h>
#include "print.h"
/*
Reverse Linked List
Delete Node from Linked List
Detect loop in linked list
Find/Insert middle of linked list
Check where linked list is even or odd without using counter
Get k node from the end
*/

struct Node
{
	int data;
	Node* next;
};
typedef struct Node node_S;

ListNode* middleoflinkedlist(ListNode *head)
{
	ListNode *rv = NULL;
	ListNode *slowptr, *fastptr;
	slowptr = fastptr = NULL;

	if (head == NULL)
		return rv;
	slowptr = fastptr = head;
	while(fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	rv = slowptr;
	return rv;
}

ListNode* reverseLinkedList(ListNode *head)
{
	ListNode *rv;
	ListNode *current, *previous;
	rv = previous = current = NULL;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		current->next = previous;
		previous = current;
	}
	rv = previous;
	return rv;
}

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

void deleteNodeformList(ListNode *head, int data)
{
	ListNode* previous = NULL;

	while(head != NULL)
	{
		if (head->val == data)
			break;
		previous = head;
		head = head->next;
	}

	previous->next = head->next;

#ifdef __cplusplus
	delete head;
#else
	free(head);
#endif
}

/*  Returns true if the number of elements in the list are an even number */
bool isListEven(ListNode *head)
{
	bool rv = true;
	ListNode *slowptr, *fastptr;

	slowptr = fastptr = NULL;

	while(fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	rv = fastptr ? true :false;
	return rv;
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