##统计一个二进制数中有多少个1
2015/6/17 19:27:59 

这道题是在“牛客网”上看到的，准确说应该是这个算法，当时我没理解到这个算法的作用，后面才发觉。统计一个数的二进制形式中有多少个1，以前的想法就是一位一位的比较然后计数，今天看到了一个跟好的算法，重点在于一个表达式：

	num = num & (num - 1);

这个表达式可以每运算一次，num最右边的1减少一个。因为当1在最小位上时，即最右边，-1后该位上的1就变成了0，与原来num相与后，最右边的1就变成了0。如果最右边的1不在最小位上，即最右边的1的右边全是0，那么-1的话每一位就会向前借位，直到最右边的1被借位变为0，所以与num相与后相应位上的1就变成了0。一直这样下去，直到所有的1变成0，在这个过程中计数，便可求出1的个数。


```c
unsigned int How_many_1(long num)
{
	unsigned int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);//每进行一次运算，最右边的1减少一个
	}
	return count;
}
```