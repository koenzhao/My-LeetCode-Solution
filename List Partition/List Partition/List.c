#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void List_Init( ListNode** head)
{
	(*head) = (ListNode*)malloc(sizeof(ListNode));
	(*head)->next = NULL;
}

void List_Insert(ListNode** head, int val)
{
	if (head == NULL)
		return ;
	
	ListNode* ptr_new = (ListNode*)malloc(sizeof(ListNode));
	ptr_new->val = val;
	ptr_new->next = NULL;
	
	ListNode* ptr = (*head);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = ptr_new;
}

void List_Delete(ListNode** head, int val)
{
	if (head == NULL || *head == NULL)
		return;
	ListNode* ptr = (*head);
	//if (ptr->val == val)
		//ptr = ptr->next;
	while (ptr->next != NULL)
	{
		if (ptr->next->val == val)
			ptr->next = ptr->next->next;
		ptr = ptr->next;
	}
}

void List_Print(ListNode** head)
{
	if (head == NULL || *head == NULL)
		return;
	ListNode* ptr = (*head)->next;
	while (ptr != NULL)
	{
		printf("%d", ptr->val);
		printf("->");
		ptr = ptr->next;
	}
	printf("NULL ");
	printf("\n");
}
