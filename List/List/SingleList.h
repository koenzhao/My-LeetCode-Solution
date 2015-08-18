#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__
#define NULL 0
//#include <iostream>

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
	Single_List();
	~Single_List();

	bool push_front(T val);
	bool push_back(T val);
	bool pop_front();
	bool pop_back();
	ListNode<T>* List_head();
	ListNode<T>* List_tail();
	void List_print();
private:
	ListNode<T>* head = NULL;
	int ListNode_Sum = 0;
};

#endif