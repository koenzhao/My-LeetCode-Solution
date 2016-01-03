//#include <iostream>
//using namespace std;
//
//int LengthOfLastWord(char* arr)
//{
//	if (arr == NULL)
//		return 0;
//	char* ptr = arr;
//	char* lastWord = NULL;
//	int length = 0;
//	while (*ptr != '\0')
//	{
//		while (*ptr == ' ')
//		{
//			ptr++;
//		}
//		lastWord = ptr;
//		while (*ptr != ' ' && *ptr != '\0')
//		{
//			ptr++;
//		}
//		if (*ptr == '\0')
//		{
//			while (*lastWord != '\0')
//			{
//				length++;
//				lastWord++;
//			}
//		}
//	}
//	return length;
//}
//
//int main()
//{
//	char str[100]; 
//	gets(str);
//	int length = 0;
//	length = LengthOfLastWord(str);
//	cout << length << endl;
//
//	system("pause");
//	
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void swap(char &a, char &b)
//{
//	char temp = b;
//	b = a;
//	a = temp;
//}
//void ReverseString(char* str, int size)
//{
//	if (str == NULL || size <= 0)
//		return;
//	int front = 0;
//	int back = size - 1;
//	while (front<back)
//	{
//		swap(str[front],str[back]);
//		front++;
//		back--;
//	}
//}
//int main()
//{
//	char str[100];
//	gets_s(str); 
//	int size = strlen(str);
//	ReverseString(str,size);
//	cout << str << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void swap(char &a, char &b)
//{
//	char temp = b;
//	b = a;
//	a = temp;
//}
//int Partition(char str[], int first, int last)
//{
//	int i = first;
//	int j = last;
//	char pvo = str[first];
//	while (i < j)
//	{
//		while (i<j && str[j] >= pvo)
//			j--;
//		while (i<j && str[i] <= pvo)
//			i++;
//		if (i < j)
//			swap(str[i], str[j]);
//	}
//	swap(str[first], str[i]);
//	return i;
//}
//void QuickSort(char str[],int first,int last)
//{
//	if (str == NULL)
//		return;
//	if (first < last)
//	{
//		int k = Partition(str, first, last);
//		QuickSort(str, first, k - 1);
//		QuickSort(str, k + 1, last);
//	}
//}
//
//int main()
//{
//	char str[128];
//	gets_s(str);
//	int size = strlen(str);
//	QuickSort(str, 0,size-1);
//	cout << str << endl;
//	return 0;
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ValueOfString(string str)
{
	int value = 0;
	for (unsigned int i = 0; i < str.size(); ++i)
	{
		value += (int)str[i]-'a'+1;
	}
	return value;
}
int main()
{	
	int N = 0;
	int value = 0;
	string new_str;
	vector<string> arr;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		cin >> new_str;
		arr.push_back(new_str);
	}
	for (int i = 0; i < N; ++i)
	{
		value = ValueOfString(arr[i]);
		cout << value << endl;
	}
	return 0;
}