#include <iostream>
#include "solution.h"
using namespace std;
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if (!l1 || !l2)
		return NULL;

	while (l1 && l2)
	{
		sum = l1->val + l2->val + C;
		List_Insert(result, sum % 10);
		C = sum / 10;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1 || l2)
	{
		if (l1)
		{
			sum = l1->val + C;
			List_Insert(result, sum % 10);
			C = sum / 10;
			l1 = l1->next;
		}
		else
		{
			sum = l2->val + C;
			List_Insert(result, sum % 10);
			C = sum / 10;
			l2 = l2->next;
		}
	}
	if (C > 0)
	{
		sum = C;
		List_Insert(result, sum % 10);
		C = sum / 10;
	}
	return result->next;
}

void Solution::List_Insert(ListNode* head, int data)
{
	if (data < 0)
		return;
	ListNode* tail = Find_Tail(head);
	ListNode* ptr = (ListNode*) malloc(sizeof(ListNode));
	ptr->val = data;
	ptr->next = tail->next;
	tail->next = ptr;
}

ListNode* Solution::Find_Tail(ListNode* head)
{
	ListNode* ptr = head;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return ptr;
}

ListNode* Solution::List_Create()
{
	ListNode* ptr;
	ptr = (ListNode*)malloc(sizeof(ListNode));
	memset(ptr, NULL, sizeof(ListNode));
	return ptr;
}

void Solution::Print_List(ListNode* head)
{
	ListNode* ptr = head->next;
	while (ptr)
	{
		cout << ptr->val << "->";
		ptr = ptr->next;
	}
	cout << "NULL";
	cout << endl;
}