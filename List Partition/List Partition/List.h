#ifndef _LIST_H_
#define _LIST_H_

typedef struct Node
{
	int val;
	struct Node* next;
}ListNode;

void List_Init(ListNode** head);
void List_Insert(ListNode** head, int val);
void List_Delete(ListNode** head, int val);
void List_Print(ListNode** head);

#endif