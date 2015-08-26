/*
题目：从1、2、3、4、5、6、7、8、9中任意选一部分数（至少一个）形成一个组合，能得到多少种不同的乘积？

（组合数学，算不来，写程序跑一下......）
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	unsigned short num = 1;
	unsigned short Max = 0x01FF;
	long long result = 1;
	vector<long long> arr;
	vector<long long>::iterator isExist;
	while (num < Max)
	{
		for (int i = 0; i < 9; ++i)
			if (((num >> i) & 0x0001) == 1)
				result = result * (i+1);
		isExist = find(arr.begin(), arr.end(), result);
		if (isExist == arr.end())
			arr.push_back(result);
		result = 1;
		num++;
	}
	return 0;
}