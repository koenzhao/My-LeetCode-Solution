#include <iostream>
using namespace std;
int *p = (int *)malloc(4);
void swap_int(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
void swap2(int *a, int *b)
{
	*a = (*a)*(*b);
	*b = (*a) / (*b);
	*a = (*a) / (*b);
}
int main()
{
	//int a = 2100000001;
	//int b = 2100000002;
	//swap_int(&a, &b);
	//swap2(&a, &b);
	//cout << "a = " << a << endl;
	//cout << "b = " << b << endl;
	*p = 10;
	cout << *p << endl;
   	system("pause");
	return 0;
}