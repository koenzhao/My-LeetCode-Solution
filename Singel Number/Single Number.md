##Single Number
2015/6/12 13:51:42 


> Given an array of integers, every element appears twice except for one. Find that single one.
> 
> Note:
> Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

>在给定的整型数组中，所有的元素都出现两遍，除了一个元素不是，找出这个元素。
>后记：你的算法应该有一个线性的时间复杂度。你能不使用额外的数组去完成它吗？


###初步想法：
使用链表数据结构，每个节点记录有data值和这个data值出现的次数count。最后从链表中找出count不为的2的一个数，即使要找的元素。

	int singleNumber(int* nums, int numsSize) 
	{
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


上面的程序超时了，不能满足线性时间复杂度的要求。下面做改进，采用map来装nums的值，每个元素作为map的key值，出现次数为对应key值的value值。最后从map里面找value值为2的key。时间复杂度为O(N)。
	

	class Solution
	{
	public:
		int singleNumber(vector<int>& nums)
		{
			for (it_vec = nums.begin(); it_vec != nums.end(); ++it_vec)
			{
				if ((it_map = nums_map.find(*it_vec)) == nums_map.end())
				{
					nums_map[*it_vec] = 1;
				}
				else
				{
					++it_map->second;
				}
			}
			for (it_map = nums_map.begin();it_map!=nums_map.end();++it_map)
			{
				if (it_map->second == 1)
					return it_map->first;
			}
			return NULL;
		}
	private:
		vector<int>::iterator it_vec;
		map<int, int> nums_map;
		map<int, int>::iterator it_map;
	};