#include <iostream>
#include "List.h"
using namespace std;

void List_Add(ListNode** head,int val)
{
	ListNode* ptr;
	ListNode* ptr_new;
	ptr_new = new ListNode(val);
	if (*head == NULL)
		*head = ptr_new;
	else
	{
		ptr = *head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = ptr_new;
	}
	
}

void List_Print(ListNode* head)
{
	ListNode* ptr = head;
	while (ptr != NULL)
	{
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << "NULL" << endl;
}

void List_Reverse(ListNode* pHead, ListNode* pTail)
{
	if (pHead == pTail)
	{
		return;
	}
	List_Reverse(pHead->next, pTail);
	pHead->next->next = pHead;
	pHead->next = NULL;
}