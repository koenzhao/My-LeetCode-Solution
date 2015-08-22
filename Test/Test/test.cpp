#include <iostream>
using namespace std;

int fuck(int* a)
{
	return (sizeof(a) / sizeof(int));
}

int main()
{
	int a[4] = { 2, 5, 8, 4 };
	int size = 0;
	size = ((a + 1) - a);
	cout << size << endl;
	return 0;
}