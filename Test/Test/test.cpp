#include <iostream>
using namespace std;

class Base
{
public:
	void fun(int n);
	void fun(char c);
};

void Base::fun(int n)
{
	cout << n << endl;
}

void Base::fun(char c)
{
	int n = (int)c;
	fun(n); // 可以直接调用
	this->fun(n); // 或者加上this
}

int main()
{
	Base b;
	b.fun('A');
	return 0;
}