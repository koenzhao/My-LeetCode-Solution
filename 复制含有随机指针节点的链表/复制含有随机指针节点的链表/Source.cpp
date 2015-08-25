/*
一种特殊的链表节点类描述如下:
class Node
{
	public int value;
	public Node next;
	public Node rand;
	public Node(int data) 
	{
		this.value = data;
	} 
}
    
	Node类中的value是节点值，next指针和正常单链表中next指针的意义
一样，都指向下一个节点，rand指针是Node类中新增的指针，这个指针可能
指向链表中的任意一个节点，也可能指向null。给定一个由Node节点类型组
成的无环单链表的头节点 head，请实现一个函数完成这个链表中所有结构的
复制，并返回复制的新链表的头节点。要求除了需要返回的东西外，不再使用
额外的数据结构并且在时间复杂度为 O(N)内完成原问题要实现的函数。
*/

/*
题目描述

输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节
点，另一个特殊指针指向任意一个节点）。
*/

#include <iostream>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};



class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		CloneNode(pHead);
		ConnectRandomNodes(pHead);
		return ReturnNodes(pHead);
	}
	void CloneNode(RandomListNode* head);
	void ConnectRandomNodes(RandomListNode* head);
	RandomListNode* ReturnNodes(RandomListNode* head);
};


void Solution::CloneNode(RandomListNode* head)
{
	RandomListNode* ptr = head;
	while (ptr != NULL)
	{
		RandomListNode* newNode = new RandomListNode(ptr->label);
		newNode->next = ptr->next;
		ptr->next = newNode;
		ptr = ptr->next->next;
	}
}

void Solution::ConnectRandomNodes(RandomListNode* head)
{
	RandomListNode* ptr = head;
	while (ptr != NULL)
	{
		ptr->next->random = ((ptr->random == NULL)? NULL:ptr->random->next);
		ptr = ptr->next->next;
	}
}

RandomListNode* Solution::ReturnNodes(RandomListNode* head)
{
	RandomListNode* ptr = head;
	RandomListNode* new_head = head->next;
	RandomListNode* new_ptr = head->next;
	
	while (NULL != new_ptr || NULL != ptr)
	{
		ptr->next = ptr->next->next;
		new_ptr->next = (new_ptr->next == NULL) ? NULL : new_ptr->next->next;
		ptr = ptr->next;
		new_ptr = new_ptr->next;
	}
	return new_head;
}

int main()
{
	RandomListNode* head = new RandomListNode(1);
	RandomListNode* second = new RandomListNode(2);
	RandomListNode* third = new RandomListNode(3);
	RandomListNode* copy_head = NULL;
	head->next = second;
	second->next = third;
	head->random = third;
	second->random = head;
	Solution sol;
	copy_head = sol.Clone(head);
	
	system("pause");
	return 0;
}
