#include <stdio.h>
#include <stdlib.h>
#define N 8
void PrintArr(const int* head);
void NQueen();
void Permutation(const int* head, int* chessboard, int length);
void swap(int* a, int* b);
int isNQueen(const int* head);
long int count = 0;
void NQueen()
{
	int* chessboard = malloc(N * sizeof(int));
	for (int i = 0; i < N; ++i)
		chessboard[i] = i;
	Permutation(chessboard, chessboard, N);
}
void Permutation(const int* head, int* chessboard, int length)
{
	if (length == 1)
	{
		if (isNQueen(head))
			count++;
		return;
	}
	for (int i = 0; i < length; ++i)
	{
		swap(&chessboard[0], &chessboard[i]);
		Permutation(head,chessboard + 1, length - 1);
		swap(&chessboard[0], &chessboard[i]);
	}
}
void swap(int* a, int* b)
{
	int temp = 0;
	temp = *b;
	*b = *a;
	*a = temp;
} 
void PrintArr(const int* head)
{
	int* ptr = (int *)head;
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", ptr[i]);
	}
	printf("\n");
}
int isNQueen(const int* head)
{
	int* ptr = (int*)head;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if ((j - i) == (ptr[j] - ptr[i]))
				return 0;
		}
	}
	return 1;
}

int main()
{
	NQueen();
	printf("%d \n", count);
	return 0;
}