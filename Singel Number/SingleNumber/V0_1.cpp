#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL 0

typedef struct _List
{
	int data;
	int count;
	struct _List* next;
}List;

List* List_Create()
{
	List* ptr = (List*)malloc(sizeof(List));
	memset(ptr,NULL,sizeof(List));
	return ptr;
}

List* List_Search(List* ptr,int data)
{
	while(ptr)
	{
		if(ptr->data == data)
		{
			return ptr;
		}
		ptr = ptr->next;
	}
	return ptr;
}

List* Find_SignelNumber(List* ptr)
{
	List* find = ptr;;
	while(ptr)
	{
		if(find->count == 1)
		{
			return find;
		}
		find = find->next;
	}
	return find;
}

bool List_Insert(List* ptr,int data)
{
	if(!ptr)
		return false;
	
	List* Node = List_Search(ptr,data);
	if(Node != NULL)
	{
		++(Node->count);
	}
	else 
	{
		Node = List_Create();
		Node->data = data;
		Node->count = 1;

		Node->next = ptr->next;
		ptr->next = Node;
	}
	return true;
}

int singleNumber(int* nums, int numsSize) {
    int i=0;
	List* ptr = List_Create();
	List* find;
	for(i=0;i<numsSize;++i)
	{
		List_Insert(ptr,nums[i]);
	}
	find = Find_SignelNumber(ptr);

	return find->data;
}

int main()
{
	int nums[] = {1,2,2,3,3,8,8,6,6};
	int size = sizeof(nums) / sizeof(int);
	int result=0;
	result = singleNumber(nums,size);
	printf("%d\n",result);
	return 0;
}