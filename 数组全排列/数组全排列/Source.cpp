#include <iostream>
using namespace std;
#define N 5
void Print(int* arr, int length);
void swap(int &a, int &b);

void perm(int* arr, int* ptr, int length)
{
	if (length == 1)
	{
		Print(arr, N);
		return;
	}
		

	for (int i = 0; i < length; ++i)
	{
		swap(ptr[0], ptr[i]);
		perm(arr, ptr+1, length-1);
		swap(ptr[0], ptr[i]);
	}
}

void Print(int* arr, int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	cout << endl;
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int* arr = new int[];
	for (int i = 0;i<N;++i)
	{
		arr[i] = i + 1;
	}
	perm(arr, arr, N);
	
	return 0;
}