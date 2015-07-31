#include <stdio.h>
#include <stdlib.h>
void print_line(int** martix, int i, int j, int n);
void print_rotate_martix(int** martix, int n)
{
	int i = 0;
	int j = n - 1;
	
	while (i <= n - 1 && j >= 0)
	{
		print_line(martix, i, j, n);
		if (j == 0)
			++i;
		else
			--j;

	}
}
void print_line(int** martix,int i,int j,int n)
{
	for (i, j; i <= (n - 1) && j <= (n - 1); ++i, ++j)
	{
		printf("%d\t", martix[i][j]);
	}
	printf("\n");
}


int main()
{
	int* _martix[3] = {NULL};
	int** martix = _martix;
	for (int i = 0;i<3;++i)
	{
		_martix[i] = (int*)malloc(3 * sizeof(int));
		for (int j = 0;j<3;++j)
		{
			martix[i][j] = i * 3 + j + 1;
		}
	}
	print_rotate_martix(martix, 3);
	return 0;
}