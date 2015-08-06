#ifndef __LIST_H__
#define __LIST_H__
//struct ListNode;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
void List_Add(ListNode** head, int val);
void List_Print(ListNode* head);
void List_Reverse(ListNode* pHead, ListNode* pTail);
#endif