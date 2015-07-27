#include <stdio.h>

int Count_Zero(int num)
{
	int count = 0;
	if (num < 0)
		return -1;
	while (num)
	{
		if (!(num&1))
			count++;
		num = num >> 1;
	}
	return count;
}

int main()
{
	int count = 0;
	count = Count_Zero(8);
	printf("%d\n", count);
	return 0;
}