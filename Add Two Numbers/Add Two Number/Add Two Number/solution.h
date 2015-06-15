#ifndef __SOLUTION_H__
#define __SOLUTION_H__

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {};
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	void List_Insert(ListNode* head, int data);
	ListNode* List_Create();
	void Print_List(ListNode* head);
private:
	int sum = 0;
	int C = 0;
	ListNode* result = List_Create();
	ListNode* Find_Tail(ListNode* head);
};

#endif;