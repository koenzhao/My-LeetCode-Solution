#include <stdio.h>
const int i = 0;
int main()
{
	int *j = (int *)&i;
	*j = 1;
	printf("%d\n%d\n%d\n%d\n", &i, j, i, *j);
	
	return 0;
}

