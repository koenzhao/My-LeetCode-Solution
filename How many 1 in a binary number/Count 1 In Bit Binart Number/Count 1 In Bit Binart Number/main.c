#include <stdio.h>
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

int main()
{
	unsigned int count = 0;
	count = How_many_1(2015);
	printf("%d\n", count);
	return 0;
}