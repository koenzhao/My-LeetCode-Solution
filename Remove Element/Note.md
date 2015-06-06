##Remove Element
2015/6/6 20:33:04 

> Given an array and a value, remove all instances of that value in place and return the new length.
 
> The order of elements can be changed. It doesn't matter what you leave beyond the new length.

>给定一个数组和一个值，然后将数组内与该值相等的元素移除，最后返回新数组的长度。

>元素的顺序是可以改变的。无论你做什么修改都行，但除了新数组的长度。

**初步想法：**

一个外部的for循环负责找val，找到后由一个内部的wihle循环将val从nums中移除，即val后面的元素都向前移一位。因为不能排除后面没有val值，所以还得接着往后找，但接着往后找这时会出现一个问题，元素全部往前移了一位，同时下一次for循环是i也向后移了一位，i++。相对的，i看起来就像在一次for循环中向后移了两次，有一个元素被跳过了。所以每一次找到val并完成相关操作后，i要向前移一位，i--，同时numsSize也要减1。这样下一次for循环i就指向正确的元素了。最后返回numsSize。

###My accepted solution:
    int removeElement(int* nums, int numsSize, int val)
	{
    for (int i = 0;i<numsSize;++i)
    {
        if(nums[i] == val)
        {
            int j = 0;
            while((i+j+1) != numsSize)
            {
                nums[i+j] = nums[i+j+1];
                ++j;
            }
            --i;
            numsSize--;
        }
    }
    return numsSize;
	}

我在Discuss看到了，另一种C解法：[iworker-priest](https://leetcode.com/discuss/user/iworker-priest "iworker-priest")
	
	//solution by iworker-priest
	int removeElement(int* nums, int numsSize, int val) {
    	if (!nums || numsSize == 0) {
        	return 0;
    	}
   		int idx_fill = 0;
    	int idx_search;
    	for (idx_search = 0; idx_search < numsSize; ++idx_search) {
        	if (nums[idx_search] != val) {
            	nums[idx_fill++] = nums[idx_search];
        	}
    	}
    	return idx_fill;
	}

首先一点我没做好的，就是对传尽量的指针和值做检查，切记切记！

这个解法挺有趣，大概就是：我不管什么移除不移除的，反正数组我遍历一遍，找到和val不相等的就把它存到数组中从开头开始的某一位里，和val相等的不管，反正这些值会被后面与val不相等的替换掉，或留在了最后面。最后只要读idx_fill的值就行了。简单粗暴~
