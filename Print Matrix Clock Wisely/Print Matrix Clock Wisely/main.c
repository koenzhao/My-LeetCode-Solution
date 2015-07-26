#include <stdio.h>

void PrintNumber(int number)
{
	printf("%d\t", number);
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	for (int i = start; i <= endX; ++i)
	{
		int number = numbers[start][i];
		PrintNumber(number);
	}

	if (start<endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			PrintNumber(number);
		}
	}

	if (start<endX && start<endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endX][i];
			PrintNumber(number);
		}
	}

	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
		{
			int number = numbers[i][start];
			PrintNumber(number);
		}
	}
}


void PrintMatrixClockwisely(int **numbers, int columns, int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while (columns > start*2 && rows > start*2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		++start;
	}
}



int main()
{
	int numbers[4][4] = {1,  2,  3,  4,
					     12, 13, 14, 5,
	                     11, 16, 15, 6,
	                     10, 9,  8,  7};
	int** ptr = numbers;
	PrintMatrixClockwisely(ptr, 4, 4);

	return 0;
}