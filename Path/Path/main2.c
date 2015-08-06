#include <stdio.h>
#define N 5
int MATRIX[N][N] = {
	//   A B C D E
	{ 0, 999, 999, 999, 5 },  //A 
	{ 0, 0, 5, 999, 7 },		//B
	{ 0, 0, 0, 8, 999 }, 		//C
	{ 0, 0, 0, 0, 10 },		//D
	{ 0, 0, 0, 0, 0 }, 		//E
};

void Path()
{
	int minPath = 0;
	for (int i = 0; i<N-1; ++i)
	{
		for (int j= i+1;j<N;++j)
		{
			minPath = MATRIX[i][j];
			for (int k = j + 1; k < N; ++k)
			{
				if (minPath > (MATRIX[i][k] + MATRIX[k][j]))
					minPath = MATRIX[i][k] + MATRIX[k][j];
			}
			MATRIX[i][j] = minPath;
			MATRIX[j][i] = minPath;
		}
	}
}

void Martix()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			MATRIX[j][i] = MATRIX[i][j];
		}
	}
}

void PrintMartix()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%3d ", MATRIX[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	
	/*Martix();
	PrintMartix();
	printf("\n");
	Path();
	PrintMartix();*/
	int i = 1;
	int j = -1;
	printf("%d, %d\n", ~1, j);
	return 0;
}