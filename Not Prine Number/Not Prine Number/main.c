#include <stdio.h>
int main()
{
	int num;
	int i, j;
	scanf("%d",&num);
	if (num >= 100 || num <= 1)
		printf("Input error!");
	else
	{
		for (i = 2; i < num; ++i)
		{
			for (j = 2; j < i; ++j)
			{
				if (i%j == 0)
				{
					printf("%d ", i);
					break;
				}
			}
		}
	}
	printf("\n");
	return 0;
}