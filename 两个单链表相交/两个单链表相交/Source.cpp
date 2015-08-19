/**********************************************************************************************
1、两个单链表相交的一系列问题
单链表可能有环,也可能无环。给定两个单链表的头节点 head1 和 head2, 这两个链表可能相交,也可能不相交。
请实现一个函数,如果两个链表相交,请返回相交 的第一个节点;如果不相交,返回 null 即可。
要求:如果链表1的长度为N，链表2的长度为M，时间复杂度请达到O(N+M)，额外空间复杂度请达到O(1)。
**********************************************************************************************/
#include <iostream>
#include "SingleList.h"

ListNode<int>* CrossNode(Single_List<int> &list1, Single_List<int> &list2)
{
	int minus = list1.GetLength() > list2.GetLength() ? list1.GetLength() - list2.GetLength() : list2.GetLength() - list1.GetLength();
	ListNode<int>* p1 = list1.List_head();
	ListNode<int>* p2 = list2.List_head();
	if (list1.GetLength() > list2.GetLength())
	{
		for (int i = 0; i < minus; ++i)
		{
			p1 = p1->next;
		}
	}
	else
	{
		for (int i = 0; i < minus; ++i)
		{
			p2 = p2->next;
		}
	}
	while (p1 != p2 && p1 != NULL && p2 != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

int main()
{
	Single_List<int> list1;
	Single_List<int> list2;
	int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arr2[] = { 1, 2, 3, 4 };
	list1.push_back(arr1, (sizeof(arr1) / sizeof(int)));
	list2.push_back(arr2, (sizeof(arr2) / sizeof(int)));
	ListNode<int>* p2 = list2.List_tail();
	ListNode<int>* p1 = list1.GetNNode(7);
	p2->next = p1;
	list1.print();
	list2.print();
	ListNode<int>* cNode = CrossNode(list1, list2);
	cout << "The first cross Node is : " << cNode->val << endl;
	//system("pause");
	return 0;
}