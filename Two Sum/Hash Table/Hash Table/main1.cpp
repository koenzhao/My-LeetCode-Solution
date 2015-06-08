#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0
#define LEN 10

typedef struct _NODE
{
	int data;
	int index;
	struct _NODE* next;
}NODE;

typedef struct _HASH_TABLE
{
	NODE* value[LEN];
}HASH_TABLE;

int Hash_Fun(const int data, int TableSize)
{
		return abs(data % TableSize);
}

HASH_TABLE* HashTable_Create()
{
	HASH_TABLE* ptr = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
	memset(ptr,NULL,LEN*sizeof(NODE*));
	return ptr;
}

NODE* Hash_Search(HASH_TABLE* ptr,int data)
{
	int d,i=0;
	NODE* ptr_NODE;
	if(NULL == ptr)
		return NULL;
	d = Hash_Fun(data,LEN);
	ptr_NODE = ptr->value[d];
	
	/*while (ptr_NODE)
	{
		if(data == ptr_NODE->data)
			return ptr_NODE;
		ptr_NODE = ptr_NODE->next;
	}
	return NULL;*/

	
	while(ptr_NODE && ptr_NODE->data != data)
	{
		ptr_NODE = ptr_NODE->next;
	}
	
	/*for(ptr_NODE = ptr->value[d];ptr_NODE != NULL;ptr_NODE = ptr_NODE->next)
	{
		if(ptr_NODE->data == data && ptr_NODE->index != index)
		{
			return ptr_NODE;
		}
	}*/
	return ptr_NODE;
}

bool Hash_Insert(HASH_TABLE* ptr,int data,int index)
{
	int d;
	NODE* ptr_NODE;
	if(NULL == ptr)
		return false;
	/*if(NULL != Hash_Search(ptr,data,index))
		return false;*/
	d = Hash_Fun(data,LEN);
	
	/*β�巨*/
	/*if (NULL == ptr->value[d])
	{
		ptr_NODE = (NODE*)malloc(sizeof(NODE*));
		memset(ptr_NODE,0,sizeof(NODE));
		ptr_NODE->data = data;
		ptr->value[d] = ptr_NODE;
		return true;
	}
	ptr_NODE = ptr->value[d];
	while(ptr_NODE->next != NULL)
		ptr_NODE = ptr_NODE->next;
	ptr_NODE->next = (NODE*)malloc(sizeof(NODE*));
	memset(ptr_NODE->next,0,sizeof(NODE));
	ptr_NODE->next->data = data;
	return true;*/
	
	/*ͷ�巨*/
	ptr_NODE = (NODE*)malloc(sizeof(NODE*));
	memset(ptr_NODE,0,sizeof(NODE));
	ptr_NODE->data = data;
	ptr_NODE->index = index;
	
	ptr_NODE->next = ptr->value[d];
	ptr->value[d] = ptr_NODE;
	return true;
}

int* twoSum(int* nums, int numsSize, int target) 
{
    int i=0;
    int data=0;
	int test = 0;
	int test2 =0; 
    HASH_TABLE* ptr;
    NODE* ptr_NODE;
    int *p = (int*)malloc(2*sizeof(int));
    ptr = HashTable_Create();
    
	for (i=0;i<numsSize;++i)
    {
        Hash_Insert(ptr,nums[i],i);
    }
    
	for(i=0;i<numsSize;++i)
    {
        data = target-nums[i];
        ptr_NODE = Hash_Search(ptr,data);
		if(ptr_NODE)
		{
			if(ptr_NODE->index == i)
			{
				continue;
			}
			else if(ptr_NODE->index < i)
			{
				p[0]=(ptr_NODE->index) +1;
				p[1]= i+1;
				break;
			}
			else if(ptr_NODE->index > i)
			{
				p[0]=i+1;
				p[1]=(ptr_NODE->index) +1;
				break;
			}
		}	
    }
	//test = ptr_NODE->data;
	if(ptr_NODE != NULL)
	{
		return p;
	}
	else 
		return NULL;
}

int main()
{
	int* p;
	int i =0;
	int num[8] = {2,7,5,4,4,56,90,3};
	p = twoSum(num,8,8);
	if(p)
		printf("index1 = %d, index2 = %d \n",p[0],p[1]);
	else 
		printf("error!");
	return 0;
}