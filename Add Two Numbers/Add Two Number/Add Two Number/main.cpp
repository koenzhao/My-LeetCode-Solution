#include <iostream>
#include "solution.h"
using namespace std;

void num_in_list(int data, ListNode* head)
{
	Solution so;
	while (data)
	{
		so.List_Insert(head,data%10);
		data = data / 10;
	}
}

int main()
{
	Solution solu;
	ListNode* l1;
	ListNode* l2;
	ListNode* result;
	l1 = solu.List_Create();
	l2 = solu.List_Create();
	int num_1 = 342;
	int num_2 = 465;
	num_in_list(num_1, l1);
	num_in_list(num_2, l2);
	solu.Print_List(l1);
	solu.Print_List(l2);
	result = solu.addTwoNumbers(l1, l2);
	solu.Print_List(result);

	return 0;
}