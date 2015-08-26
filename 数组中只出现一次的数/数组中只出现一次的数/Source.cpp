#include <iostream>
#include <vector>
using namespace std;

/*num数组中只有一个数出现一次，其他数出现2次*/
int singleNumber_1(vector<int> num)
{
	if (num.empty())
		return NULL;
	int result = 0;
	vector<int>::iterator i = num.begin();
	for (; i != num.end(); ++i)
	{
		result ^= *i;
	}
	return result;
}

/*num数组中只有一个数出现一次，其他数出现times次*/
int singleNumber_2(vector<int> num,int times)
{
	if (num.empty())
		return NULL;
	int result=0;
	vector<int>::iterator p = num.begin();
	for (int i = 0; i < 32; ++i)
	{
		int count = 0;
		int bitValue = 0;
		int mask = 1<<i;
		for (p = num.begin(); p != num.end(); ++p)
		{
			bitValue = ((*p) & mask);
			if (bitValue>0 || bitValue < 0)
				count++;
		}
		if ((count % times) > 0)
		{
			result = result | mask;
		}
	}
	return result;
}

int singleNumber_3(vector<int> num)
{
	int one = 0;
	// 出现一次的标志位
	int accumulation = 0;
	// 积累标志位
	vector<int>::iterator i;
	for (i = num.begin(); i!=num.end(); ++i)
	{
		accumulation |= (*i) & one;
		// 只要第二次或者以上出现，就为1
		one ^= (*i);
		// 出现奇数次保留，偶数次抛弃
		int t = one & accumulation;
		// 第三次的时候one和accumulation都保留了该位的值
		one &= ~t;
		// 清零出现三次的该位的值
		accumulation &= ~t;
	}
	return one;
	
}


int main()
{
	vector<int> num = { 1,1,1,3,2,2,2};
	int result = 0;
	result = singleNumber_3(num);
	cout << result << endl;

	
	
	system("pause");
	return 0;
}