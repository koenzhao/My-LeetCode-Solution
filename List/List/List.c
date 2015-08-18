#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node* next;
}ListNode;

void List_Init( ListNode** head)
{
	(*head) = (ListNode*)malloc(sizeof(ListNode));
	(*head)->next = NULL;
}

void List_Insert(ListNode** head, int data)
{
	if (head == NULL)
		return ;
	
	ListNode* ptr_new = (ListNode*)malloc(sizeof(ListNode));
	ptr_new->data = data;
	ptr_new->next = NULL;
	
	ListNode* ptr = (*head);
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = ptr_new;
}

void List_Delete(ListNode** head, int data)
{
	if (head == NULL || *head == NULL)
		return;
	ListNode* ptr = (*head);
	//if (ptr->data == data)
		//ptr = ptr->next;
	while (ptr->next != NULL)
	{
		if (ptr->next->data == data)
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
		printf("%d", ptr->data);
		printf("->");
		ptr = ptr->next;
	}
	printf("NULL ");
	printf("\n");
}

int main()
 {
	ListNode* head = NULL;
	List_Init(&head);
	for (int i = 0; i < 10; ++i)
	{
		List_Insert(&head, i);
	}
	List_Delete(&head, 2);
	List_Print(&head);

	return 0;
}