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

Discuss区里有一段简短的C++实现程序，```Easy recursive solution in C++```


```c++
ListNode* addList(ListNode* l1, ListNode* l2, int carry) {
    if(!l1 && !l2) {
        if(carry) return new ListNode(carry);
        else return NULL;
    }
    int val = carry + (l1?l1->val:0) + (l2?l2->val:0);
    ListNode* newNode = new ListNode(val%10);
    newNode->next = addList(l1?l1->next:NULL, l2?l2->next:NULL, val/10);
    return newNode;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addList(l1, l2, 0);
}
```

确实挺简短，这段程序是递归实现的，并且用了条件运算符，所以才能达到这么简短；还有另外一段20ms的C程序，思路差不多，但看到后就明白了一个前面没搞懂的东西。我前面新建一个节点的时候总是用malloc去新开辟一段内存空间，里面存着0，这样就导致了链表一开始总是以0开头。在这个C程序里面看到了新建一个节点是其实可以直接对指针赋值NULL，就没那么多问题了。