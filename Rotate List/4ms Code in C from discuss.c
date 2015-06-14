struct ListNode* rotateRight(struct ListNode* head, int k) 
{
	if(head==NULL) //链表为空
		return NULL;
	if(k==0 || head->next==NULL) //k=0或链表中只有一个节点
		return head;
	struct ListNode* ptr1=head；
	struct ListNode* ptr2=head;
	int i=1;
	int length=0;
	while(ptr1)//计算链表的长度
	{
    	length++;
    	ptr1=ptr1->next;
	}
	ptr1=head;
	if(k>length)//k比长度len长时，取模
		k = k%length;
	if(k==length)
		return head;
	for(i=1;i<=k;i++)
	{
		if(ptr2->next==NULL)
			return head;
		ptr2=ptr2->next;
	}
    while(ptr2->next!=NULL)
	{
        ptr2=ptr2->next;
        ptr1=ptr1->next;
    }
    ptr2->next=head;
	head = ptr1->next;
	ptr1->next=NULL; 
	return head;
}