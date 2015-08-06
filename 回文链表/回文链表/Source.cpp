#include <iostream>
#include "List.h"
using namespace std;

class Palindrome {
public:
	bool isPalindrome(ListNode* pHead) 
	{
		// write code here
		if (pHead == NULL)
			return false;
		ListNode* ptr_count = pHead;
		ListNode* ptr_mid = pHead;
		ListNode* ptr_mid_copy = new ListNode(0);
		ListNode* ptr_tail = pHead;
		int count = 0;
		while (ptr_count != NULL)
		{
			count++;
			ptr_count = ptr_count->next;
		}
		if (count<3)
		{
			if (count == 1)
				return true;
			else
			{
				if (pHead->val == pHead->next->val)
					return true;
				return false;
			}
		}
		if (count%2 == 1)//ÆæÊý
		{
			while (ptr_tail->next != NULL)
			{
				ptr_mid = ptr_mid->next;
				ptr_tail = ptr_tail->next->next;
			}
			ptr_mid_copy->val = ptr_mid->val;
			ptr_mid_copy->next = ptr_mid->next;
			//List_Reverse(pHead, ptr_mid);
		}
		else
		{
			while (ptr_tail->next->next != NULL)
			{
				ptr_mid = ptr_mid->next;
				ptr_tail = ptr_tail->next->next;
			}
			ptr_mid_copy = ptr_mid->next;
			//List_Reverse(pHead, ptr_mid);
		}
		List_Reverse(pHead, ptr_mid);
		while ((ptr_mid != NULL) && (ptr_mid_copy != NULL))
		{
			if (ptr_mid->val != ptr_mid_copy->val)
				return false;
			ptr_mid = ptr_mid->next;
			ptr_mid_copy = ptr_mid_copy->next;
			
		}
		if (ptr_mid == NULL && ptr_mid_copy == NULL)
			return true;
		return false;
	}
};

int main()
{
	ListNode* head = NULL;
	int val[] = {8,8};
	for (int i = 0; i < (sizeof(val)/sizeof(int)); ++i)
	{
		List_Add(&head, val[i]);
	}
	List_Print(head);
	Palindrome pal;
	if (pal.isPalindrome(head))
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	cout << "Done" << endl; 
	return 0;
}
