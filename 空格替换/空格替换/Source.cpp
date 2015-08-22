/*
题目描述

请编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串有足够的空间存放新增的字符，并且知道字符串的真实长度(小于等于1000)，同时保证字符串由大小写的英文字母组成。
给定一个string iniString 为原始的串，以及串的长度 int len, 返回替换后的string。
测试样例：
"Mr John Smith”,13
返回："Mr%20John%20Smith"
”Hello  World”,12
返回：”Hello%20%20World”
*/
#include <iostream>
#include <string>
using namespace std;
class Replacement {
public:
	string replaceSpace(string iniString, int length) 
	{
		// write code here
		if (iniString.empty() || length < 0)
			return iniString;
		int spaceCount = 0;
		int start = 0;
		while (iniString[start] != '\0')
		{
			if (iniString[start] == ' ')
				spaceCount++;
			start++;
		}
		
		int last = length + 2 * spaceCount;
		string::size_type new_capacity{ 100u };
		iniString.reserve(new_capacity);
		while (start != last && start >= 0 && last >= 0)
		{
			if (iniString[start] == ' ')
			{
				iniString[last--] = '0';
				iniString[last--] = '2';
				iniString[last--] = '%';
				start--;
			}
			else
			{
				iniString[last] = iniString[start];
				last--;
				start--;
			}
		}
		return iniString;
	}
};
int main()
{
	string str = "he wo a";
	/*string::size_type new_capacity{ 100u };
	str.reserve(new_capacity);*/
	//cout << str.size() << endl;
	cout << str << endl;
	Replacement rep;
	str = rep.replaceSpace(str, str.size());
	cout << str << endl;
}
