#include <iostream>
/*
For example :
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/
//Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || k<0)
			return NULL;
		tail = findTail(head);
		tail->next = head;
		k = k + len;
		int std = len - k%len - 1;
		for (int i = 0; i < std; ++i)
		{
			head = head->next;
		}
		tail = head;
		head = head->next;
		tail->next = NULL;
		return head;
	}
private:
	int len = 1;
	ListNode* tail;
	ListNode* findTail(ListNode* head);
};

ListNode* Solution::findTail(ListNode* head)
{
	if (!head)
		return NULL;
	ListNode* ptr = head;
	while (ptr->next)
	{
		ptr = ptr->next;
		++len;
	}
	return ptr;
}

int main()
{
	return 0;
}