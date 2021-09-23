/*
 * circularlist.c
 *
 *  Created on: Oct 19, 2020
 *      Author: rehanashraf
 */
#include <stdio.h>
#include <stdlib.h>
#include "print.h"

bool circularList(ListNode *head)
{
	bool rv = false;
	ListNode *slowptr, *fastptr;

	if(head == NULL || head->next == NULL)
		return rv;

	slowptr = fastptr = head;

	while (fastptr != NULL && fastptr->next != NULL)
	{
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
		if (slowptr == fastptr)
		{
			rv = true;
			return rv;
		}
	}
	return rv;
}
