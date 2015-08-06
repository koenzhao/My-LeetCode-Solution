#include <stdio.h>
#define N 5
#define uint unsigned int
uint MATRIX[N][N] = {
	//   A B C D E
	{ 0, 999, 999, 999, 5 },  //A 
	{ 0, 0, 5, 999, 7 },		//B
	{ 0, 0, 0, 8, 999 }, 		//C
	{ 0, 0, 0, 0, 10 },		//D
	{ 0, 0, 0, 0, 0 }, 		//E
};
struct TYPE_NODE
{
	uint path;//从第0位到第N位上有1的两位,表示这段路径的起点和终点 
	uint distance;//表示这段路径的长度 
};
struct TYPE_NODE NODE[N*(N - 1) / 2];
uint init_node()//给NODE们的参数赋值 
{
	int i = 0, j = 0, k = 0;
	for (i = 1; i < (N + 1); ++i)
	{
		for (j = 0; j < i; ++j)
		{
			NODE[k].distance = MATRIX[i][j];
			NODE[k].path = 0;
			NODE[k].path = (1 << i) | (1 << j);
			k++;
		}
	}
	return 0;
}
uint mirror_1()//就是把右上的矩阵翻到左下 
{
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			MATRIX[i][j] = MATRIX[j][i];
		}
	}
	return 0;
}

uint mirror_2()//把左下的矩阵翻到右上 
{
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < i; ++j)
		{
			MATRIX[j][i] = MATRIX[i][j];
		}
	}
	return 0;
}

uint calculate_node()//计算最短路径 for用的有点多 
{
	int i, j, k;
	for (i = 0; i < (N*(N - 1) / 2); ++i)
	{
		for (j = 0; j < (N*(N - 1) / 2); ++j)
		{
			for (k = 0; k < (N*(N - 1) / 2); ++k)
			{
				if ((NODE[k].path) == ((NODE[i].path) ^ (NODE[j].path)))
				{
					if (NODE[k].distance >((NODE[i].distance) + (NODE[j].distance)))
					{
						NODE[k].distance = ((NODE[i].distance) + (NODE[j].distance));//如果AB+BC<AC 则AC= AB+BC 
						//printf("oba!\n");
					}
				}
			}
		}
	}
	return 0;
}

uint printf_MATRIX()//输出矩阵= = 
{
	int i = 0, j = 0;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("%3d ", MATRIX[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n\n\n");
	return 0;
}

uint return_node()
{
	int i = 0, j = 0, k = 0;
	for (i = 1; i < (N + 1); ++i)
	{
		for (j = 0; j < i; ++j)
		{
			MATRIX[i][j] = NODE[k].distance;
			k++;
		}
	}
	return 0;
}
uint print_NODE()
{
	int i;
	for (i = 0; i < (N*(N - 1) / 2); ++i)
	{
		printf("%3d %3d \n", NODE[i].distance, NODE[i].path);
	}
	return 0;
}
int main()
{
	//int i, j;
	mirror_1();
	printf_MATRIX();
	init_node();
	
	print_NODE();
	printf("\n");
	
	calculate_node();
	
	print_NODE();
	printf("\n");

	return_node();
	//	print_NODE();
	mirror_2();
	printf_MATRIX();
	return 0;
}