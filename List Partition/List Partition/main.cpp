#include <iostream>
//#include <string.h>
using namespace std;

typedef struct Node
{
	int val;
	struct Node* next;
}ListNode;

void List_Init(ListNode** head)
{
	(*head) = (ListNode*)malloc(sizeof(ListNode));
	(*head)->next = NULL;
}

void List_Insert(ListNode** head, int val)
{
	if (head == NULL)
		return;

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



class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == NULL)
			return NULL;
		ListNode* head = (ListNode*)malloc(sizeof(ListNode));
		ListNode* ptr = (ListNode*)malloc(sizeof(ListNode));
		ListNode* ptr_tail = pHead;
		int count = 0;
		ptr->next = pHead;
		head = ptr;
		while (ptr_tail->next != NULL)
		{
			ptr_tail = ptr_tail->next;
			count++;
		}
		for (int i = 0;i<=count;++i)
		{
			if (ptr->next->val >= x)
			{
				ptr_tail->next = ptr->next;
				ptr->next = ptr->next->next;
				ptr_tail->next->next = NULL;
				ptr_tail = ptr_tail->next;
			}
			else
				ptr = ptr->next;
		}
		return(head->next);
	}
};

int main()
{
	ListNode* head = NULL;
	List_Init(&head);
	int num[10] = { 5, 3, 1, 8, 6, 4, 5, 6, 2, 9 };
	for (int i = 0; i < 10; i++)
	{
		List_Insert(&head, num[i]);
	}
	//List_Print(&head);
	Partition par;
	head->next = par.partition(head->next, 2);
	List_Print(&head);
	return 0;
}