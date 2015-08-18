#include <iostream>
#include "SingleList.h"
using namespace std;

template <class T>
Single_List<T>::Single_List()
{
	head = new ListNode(0);
}

template <class T>
Single_List<T>::~Single_List()
{
	ListNode<T>* p = NULL;
	ListNode<T>* next = NULL;
	for (p = head; p != NULL; p = next)
	{
		next = p->next;
		delete p;
		p = NULL;
	}
	ListNode_Sum = 0;
}
template <class T>
bool Single_List<T>::push_back(T val)
{
	ListNode<T>* NodeToPush = ListNode(val);
	ListNode<T>* LastNode = List_tail();
	LastNode->next = NodeToPush;
	ListNode_Sum++;
	return true;
}
template <class T>
bool Single_List<T>::push_front(T val)
{
	ListNode<T>* NodeToPush = ListNode(val);
	NodeToPush->next = head->next;
	head->next = NodeToPush;
	ListNode_Sum++;
	return true;
}

template <class T>
bool Single_List<T>::pop_front()
{
	while (ListNode_Sum < 1)
		return false;
	ListNode<T>* NodeToPop = head->next;
	head->next = NodeToPop->next;
	NodeToPop->next = NULL;
	delete NodeToPop;
	NodeToPop = NULL;
	ListNode_Sum--;
	return true;
}
template <class T>
bool Single_List<T>::pop_back()
{
	while (ListNode_Sum < 1)
		return false;
	ListNode<T>* NodeToPop = NULL;
	ListNode<T>* p = head;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	NodeToPop = p->next;
	p->next = NodeToPop->next;
	NodeToPop->next = NULL;
	delete NodeToPop;
	NodeToPop = NULL;
	ListNode_Sum--;
	return true;

}

template <class T>
ListNode<T>* Single_List<T>::List_head()
{
	return head->next;
}

template <class T>
ListNode<T>* Single_List<T>::List_tail()
{
	ListNode<T>* p = NULL;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;
	}
	return p;
}

template <class T>
void Single_List<T>::List_print()
{
	ListNode<T>* NodeToPrint = head->next;
	if (ListNode_Sum == 0)
	{
		cout << "List have " << ListNode_Sum << " node" << endl;
		return;
	}
	else
		cout << "List have " << ListNode_Sum << " nodes : " << endl;
	while (NodeToPrint != NULL)
	{
		cout << NodeToPrint->val << "->";
	}
	cout << NULL << endl;
}