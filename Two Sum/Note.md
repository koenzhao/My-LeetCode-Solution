##Two Sum
2015/6/6 22:17:22 

> Given an array of integers, find two numbers such that they add up to a specific target number.
> 
> The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
> 
> You may assume that each input would have exactly one solution.
> 
> Input: numbers={2, 7, 11, 15}, target=9
> Output: index1=1, index2=2

>对于给定的一个整形数组，找出其中的两个整数满足相加等于target。
>
>函数twoSum()应该返回两个满足条件的数的索引值，其中index1必须小于index2。请确保返回值不为0。
>
>你可以认为每一组输入只有一组数满足条件


####初步想法：
一开始感觉不难，两个for嵌套遍历数组，找到相加等于target的两个数，记录下索引值（加1确保不为0），并返回。程序没问题，但程序超时了。在最坏的情况下下面程序时间复杂度为O(N^2)。不符合要求！

	/**
 	* Note: The returned array must be malloced, assume caller calls free().
	*/
	int* twoSum(int* nums, int numsSize, int target) 
	{
    	int* p;
		int i;
		int j;
		p = (int*) malloc(2*sizeof(int));
		for (i=0;i<numsSize-1;i++)
		{
			for (j=1;(i+j)<numsSize;j++)
			{
				if((nums[i]+nums[i+j])==target)
				{
					p[0] = i+1;
					p[1] = i+j+1;
					return p;
				}
			}
		}
	}

后面根据《LeetCode题解》指导，应该使用哈希表存储数据，这就是我数据结构的薄弱点了！另一份笔记中记录了哈希表的学习。

**有了哈希表之后，思路是这样的：**

先建立一个哈希表，每一个节点存放数组中「某个元素的值」和「该元素的下标」，把数组全部先存进哈希表里，这里不检查哈希表中是否已存在该数据，因为数组里值是可以重复的。要是加上下标一起检查的话，后面查找就不好办了：
	
	ptr = HashTable_Create();//创建哈希表
    for (i=0;i<numsSize;++i)//存入数据
    {
        Hash_Insert(ptr,nums[i],i);
    }

然后从头开始对数组每个元素进行如下操作：```data = target-nums[i];```,data就是对与元素nums[i]来说我们要去哈希表里找的数，找完之后，如果没找到则进行下一个元素寻找，如果找到的数的下标和i相等，则忽略，剩下就是找到的情况了，找到的数的下标和i按小到大放都某个数组里，然后返回。因为题目假设只有一组满足条件：

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


完整的程序在Hash Table的工程文件中。