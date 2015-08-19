#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__
#include <iostream>
using namespace std;
template<class T>
struct ListNode
{
	T val;
	struct ListNode* next;
	ListNode(T data) :val(data), next(NULL){}
};

template<class T>
class Single_List
{
public:
	Single_List()
	{
		head = new ListNode<T>(0);
	}
	~Single_List()
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

	bool push_front(T val);
	bool push_back(T val);
	bool push_back(T* arr, int size);
	bool push_front(T* arr,int size);
	bool pop_front();
	bool pop_back();
	ListNode<T>* List_head();
	ListNode<T>* List_tail();
	void print();
	ListNode<T>* GetNNode(int n);
private:
	ListNode<T>* head = NULL;
	int ListNode_Sum = 0;
};

template <class T>
bool Single_List<T>::push_back(T val)
{
	ListNode<T>* NodeToPush = new ListNode<T>(val);
	ListNode<T>* LastNode = List_tail();
	LastNode->next = NodeToPush;
	ListNode_Sum++;
	return true;
}

template <class T>
bool Single_List<T>::push_front(T val)
{
	ListNode<T>* NodeToPush = new ListNode<T>(val);
	NodeToPush->next = head->next;
	head->next = NodeToPush;
	ListNode_Sum++;
	return true;
}

template <class T>
bool Single_List<T>::push_back(T* arr, int size)
{
	if (arr == NULL || size < 1)
		return false;
	for (int i = 0; i < size; ++i)
	{
		push_back(arr[i]);
	}
	return true;
}

template <class T>
bool Single_List<T>::push_front(T* arr, int size)
{
	if (arr == NULL || size < 1)
		return false;
	for (int i = 0; i < size; ++i)
	{
		push_front(arr[i]);
	}
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
void Single_List<T>::print()
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
		cout << NodeToPrint->val << " -> ";
		NodeToPrint = NodeToPrint->next;
	}
	cout << "NULL" << endl;
}

template <class T>
ListNode<T>* Single_List<T>::GetNNode(int n)
{
	if (n > ListNode_Sum)
		return NULL;
	ListNode<T>* p = head->next;
	for (int i = 1; i < n; ++i)
	{
		p = p->next;
	}
	return p;
}

#endif