/*
题目描述

利用字符重复出现的次数，编写一个方法，实现基本的字符串压缩功能。比如，字符串“aabcccccaaa”经压缩会变成“a2b1c5a3”。若压缩后的字符串没有变短，则返回原先的字符串。
给定一个string iniString为待压缩的串(长度小于等于3000)，保证串内字符均由大小写英文字母组成，返回一个string，为所求的压缩后或未变化的串。
测试样例
"aabcccccaaa"
返回："a2b1c5a3"
"welcometonowcoderrrrr"
返回："welcometonowcoderrrrr"
*/

#include <iostream>
#include <string>
using namespace std;

class Zipper 
{
public:
	string zipString(string iniString) 
	{
		// write code here
		if (iniString.empty())
			return iniString;
		string returnString;
		string::iterator ptr = iniString.begin();
		while (ptr != iniString.end())
		{
			char temp = *ptr;
			int tempCount = 0;
			while (ptr != iniString.end() && *ptr == temp)
			{
				tempCount++;
				ptr++;
			}
			returnString.push_back(temp);
			returnString.append(intToStr(tempCount));
			
		}
		if (returnString.size() > iniString.size())
			return iniString;
		else
			iniString = returnString;
		return iniString;
	}
	char* intToStr(int num)
	{
		int tmp = 0;
		int i = 0;
		int j = 0;
		char* buf = (char*)calloc(5,sizeof(char));
		for (i = 0; num != 0; ++i)
		{
			tmp = num % 10;
			buf[i] = (char)(tmp + '0');
			num = num / 10;
		}
		for (i = 0, j = strlen(buf)-1; i < j; ++i, --j)
		{
			swap(buf[i], buf[j]);
		}
		return buf;
	}
	void swap(char &a, char &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
};

int main()
{
	string String = "jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF";
	Zipper zip;
	cout << String << endl;
	String = zip.zipString(String);
	cout << String << endl;
	
	system("pause");
	return 0;
}