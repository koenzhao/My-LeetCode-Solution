#include <stdio.h>
#include <stdlib.h>

int InversePairsCore(int* data, int* copy, int start, int end);
int InversePairs(int* data, int length)
{
	if (data == NULL || length < 0)
		return 0;
	int* copy = (int* )malloc(length*sizeof(int));
	for (int i = 0; i < length; ++i)
		copy[i] = data[i];
	int count = InversePairsCore(data,copy,0,length-1);
	
	return count;
}

int InversePairsCore(int* data,int* copy,int start,int end)
{
	if (start == end)
	{
		copy[start] = data[start];
		return 0;
	}

	int length = (end - start) / 2;
	int left = InversePairsCore(copy, data, start, start + length);
	int right = InversePairsCore(copy, data, start + length + 1, end);

	int i = start + length;
	int j = end;
	int indexCopy = end;
	int count = 0;
	while (i>=start && j>=start+length+1)
	{
		if (data[i] > data[j])
		{
			copy[indexCopy--] = data[i--];
			count += j - start - length;
		}
		else
		{
			copy[indexCopy--] = data[j--];
		}
	}

	for (; i >= start; --i)
	{
		copy[indexCopy--] = data[i];
	}
	for (; j >= start + length + 1; --j)
	{
		copy[indexCopy--] = data[j];
	}

	return left + right + count;
}

int main()
{
	int count = 0;
	int data[] = { 7, 5, 6, 4 };
	int length = (sizeof(data) / sizeof(int));
	count = InversePairs(data,length);
	printf("%d\n", count);
	return 0;
}