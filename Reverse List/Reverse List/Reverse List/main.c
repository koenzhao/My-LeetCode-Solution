#include <stdio.h>
#include <stdlib.h>
#include "List.h"

ListNode* g_head = NULL;

void ReverseList(ListNode** head)
{
	if (head == NULL || *head == NULL)
		return;
	ListNode* ptr_1 = (*head)->next;
	ListNode* ptr_2 = ptr_1->next;
	ListNode* reserve = NULL;
	ptr_1->next = NULL;
	while (ptr_2 != NULL)
	{
		reserve = ptr_2->next;
		ptr_2->next = ptr_1;
		ptr_1 = ptr_2;
		ptr_2 = reserve;
	}
	(*head)->next = ptr_1;
}
/************************************
反转演示：
1->2->3->4->5->NULL
1->3->2->4->5->NULL
1->4->3->2->5->NULL
1->5->4->3->2->NULL
5->4->3->2->1->NULL
************************************/
void ReverseList_2(ListNode** head)
{
	ListNode* first = (*head)->next;
	ListNode* ptr_1 = first->next;
	ListNode* ptr_2;
	while (ptr_1->next != NULL)
	{
		ptr_2 = ptr_1->next;
		ptr_1->next = ptr_2->next;
		ptr_2->next = first->next;
		first->next = ptr_2;
	}

	ptr_1->next = first;
	(*head)->next = ptr_1->next->next;
	first->next = NULL;
}
/********************************************
功能：递归反转链表
思路：设置两个指针指向相邻的两个元素，依次递归往
后移，直到最后两个，然后将这两个元素的链表反转，
接着返回上层继续反转
********************************************/
void Reverse3(ListNode* head)
{
	ListNode* ptr_Prev = head;
	ListNode* ptr_Next = ptr_Prev->next;

	if (ptr_Next == NULL)
	{
		g_head = ptr_Prev;
		return;
	}
	else
		Reverse3(ptr_Next);
	ptr_Next->next = ptr_Prev;
}

int main()
{
	ListNode* head = NULL;
	List_Init(&head);
	for (int i = 0; i < 10; ++i)
	{
		List_Insert(&head, i);
	}
	List_Print(&head);
	//ReverseList(&head);
	//List_Print(&head);
	//ReverseList_2(&head);
	//List_Print(&head);
	Reverse3(head->next);
	head->next->next = NULL;
	head->next = g_head;
	List_Print(&head);
	return 0;
}