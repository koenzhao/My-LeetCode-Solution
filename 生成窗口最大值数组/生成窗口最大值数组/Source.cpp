/*
有一个整型数组arr和一个大小为w的窗口从数组的最左边滑到最右边，窗口每次向右边滑一个位置。
例如，数组为[4,3,5,4,3,3,6,7]，窗口大小为3时：

[4 3 5] 4 3 3 6 7 窗口中最大值为5
4 [3 5 4] 3 3 6 7 窗口中最大值为5
4 3 [5 4 3] 3 6 7 窗口中最大值为5
4 3 5 [4 3 3] 6 7 窗口中最大值为4
4 3 5 4 [3 3 6] 7 窗口中最大值为6
4 3 5 4 3 [3 6 7] 窗口中最大值为7

如果数组长度为n，窗口大小为w，则一共产生n-w+1个窗口的最大值。请实现一个函数，给定一个数
组arr，窗口大小w。返回一个长度为n-w+1的数组res,res[i]表示每一种窗口状态下的最大值。以本
题为例，结果应该返回[5,5,5,4,6,7]。
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxInWindows(const vector<int> num, unsigned int size)
{
	vector<int> maxInWindow;
	if (num.size() >= size && size >= 1)
	{
		deque<int> index;//存放滑动窗口中最大值的下标
		for (unsigned int i = 0; i < size; ++i)//一开始先将滑动窗口装满
		{
			while (!index.empty() && num[i] >= num[index.back()])//若待插入数>=index尾数
				index.pop_back();//将index中尾数弹出
			index.push_back(i);//将待插入数下标压入index中
		}

		for (unsigned int i = size; i < num.size(); ++i)//每次滑动窗口一位
		{
			maxInWindow.push_back(num[index.front()]);

			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= (int)(i - size))//index头部数字被滑出
				index.pop_front();
			index.push_back(i);
		}
		maxInWindow.push_back(num[index.front()]);

	}

	return maxInWindow;
}




int main()
{
	vector<int> max;
	vector<int> num = {2,3,4,2,6,2,5,1};
	unsigned int windowSize = 3;
	max = maxInWindows(num, windowSize);
	for (unsigned int i = 0; i < max.size(); ++i)
	{
		cout << max[i] <<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}
