##Rotate List
2015/6/14 18:41:06 

> Given a list, rotate the list to the right by k places, where k is non-negative.
> 
> For example:
> Given 1->2->3->4->5->NULL and k = 2,
> return 4->5->1->2->3->NULL.


>对于一个给定的链表，把链表后面的k个节点轮转到链表前面。

###初步想法：
先找到链表的尾节点，把链表连成循环链表，轮转k位，则尾节点向前倒退(k-1)位即为新的链表。但发现它是单向链表！单向链表要倒退的回上一节点的话，就要遍历整个链表的长度。尝试之后，发现如果k它给的非常大的话，O(abs(len-k-1))，时间复杂度会变得很大。在这里面其实做了很多无谓的轮转，所以轮转的基准值要修改，int std = len-k%len-1，以std作为轮转次数的基准值。
	
```c
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if(!head || k<0)
		    return NULL;
		tail = findTail(head);
		tail->next = head;
		k = k +len;
		int std = len-k%len-1;
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
```

以上程序通过，耗时12ms。