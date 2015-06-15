##Add Two Numbers 
2015/6/15 16:53:25 

> You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
> 
> Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
> Output: 7 -> 0 -> 8

>现有一包括了两个非负整数的链表。链表中每个节点里存了一个数字，且数字以相反的顺序存放在链表中。现在把这两个数字加起来，然后返回一个新的链表。

###初步思路：
因为链表里数字的顺序是倒序，所以从表头开始第一位是个位，第二位是十位，第三位是百位......所以加的时候可以直接取两数的各个位相加，其中C记录进位，相加结果模10为和的相应位上的数。下面只把类贴出来，工程文件里还写了打印链表、测试部分，文件里还有debug的结果。

```c
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

```

运行时间44ms，属于C++中中等偏慢的。本次的练习可以检查出我链表的操作写起来不熟悉，多加练习！

