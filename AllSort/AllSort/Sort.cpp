#include <iostream>
#include <vector>
using namespace std;

/*交换元素*/
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
/*打印数组*/
void print(vector<int> &num)
{
	vector<int>::iterator i;
	for (i = num.begin(); i != num.end(); ++i)
	{
		printf("%3d", *i);
	}
	printf("\n");
}
/*快排核心：Partition算法*/
unsigned int Partition(vector<int> &num, unsigned int left, unsigned int right)
{
	unsigned int i = left;
	unsigned int j = right;
	int Pivot = num[left];
	while (i < j)
	{
		while (i<j && num[j] >= Pivot)
			j--;
		while (i<j && num[i] <= Pivot)
			i++;
		if (i < j)
			swap(num[i], num[j]);
	}
	swap(num[i], num[left]);
	return i;
}
/*大根堆调整函数*/
void AdjustHeap_maxroot(vector<int> &num,int node,int size)
{
	if (num.empty())
		return;
	int max = node;
	int left = 2 * node + 1;
	int right = 2 * node + 2;
	if (left < size && num[left] > num[max])
	{
		max = left;
	}
	if (right < size && num[right] > num[max])
	{
		max = right;
	}
	if (max != node)
	{
		swap(num[max], num[node]);
		AdjustHeap_maxroot(num, max, size);
	}
}
/*建堆函数*/
void BuildHeap(vector<int> &num)
{
	if (num.empty())
		return;
	for (int i = (num.size() / 2); i >= 0; i--)
	{
		AdjustHeap_maxroot(num, i, num.size());
	}

}
/*归并核心*/
void MergeSortCore(vector<int> &num,unsigned int first,unsigned int mid,unsigned last)
{
	unsigned int i = first;
	unsigned int j = mid + 1;
	unsigned int end_i = mid;
	unsigned int end_j = last;
	vector<int> buff;
	while (i <= end_i && j <= end_j)
	{
		if (num[i] < num[j])
		{
			buff.push_back(num[i]);
			i++;
		}
		else if (num[i] > num[j])
		{
			buff.push_back(num[j]);
			j++;
		}
	}
	while (i<=end_i)
	{
		buff.push_back(num[i]);
		i++;
	}
	while (j <= end_j)
	{
		buff.push_back(num[j]);
		j++;
	}
	vector<int>::iterator ptr = buff.begin();
	for (i = first; i <= last; ++i,ptr++)
	{
		num[i] = *ptr;
	}
}

/*插入排序*/
void InsertSort(vector<int> &num)
{
	if (num.empty())
		return;
	for (unsigned int i = 1; i < num.size(); i++)
	{
		int temp = num[i];
		int j = i - 1;
		while (j >= 0 && num[j] >= temp)
		{
			num[j + 1] = num[j];
			j--;
		}
		num[j + 1] = temp;
	}
}
/*二分插入排序（未完成，后续修复bug）*/
void BinInsertSort(vector<int> &num)
{
	if (num.empty())
		return;
	for (unsigned int i = 1; i < num.size(); i++)
	{
		int temp = num[i];
		int left = 0;
		int right = i - 1;
		while (left <= right)
		{
			int middle = (right - left) / 2;
			if (num[middle] > temp)
			{
				right = middle - 1;
			}
			else if (num[middle] < temp)
			{
				left = middle + 1;
			}
		}
		for (int j = i - 1; j >= left; --j)
		{
			num[j + 1] = num[j];
		}
		num[left] = temp;
	}
		
}
/*希尔排序*/
void ShellSort(vector<int> &num)
{
	const int n = 5;
	unsigned int i;
	int temp,j;
	unsigned int gap = 0;
	while (gap <= num.size())
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < num.size(); i++)
		{
			j = i - gap;
			temp = num[i];
			while ((j >= 0) && (num[j] > temp))
			{
				num[j + gap] = num[j];
				j = j - gap;
			}
			num[j + gap] = temp;
		}
		gap = (gap - 1) / 3;
	}
}
/*选择排序*/
void SelectSort(vector<int> &num)
{
	if (num.empty())
		return;
	for (unsigned int i = 0; i < num.size()-1; ++i)
	{
		int Min = i;
		for (unsigned int j = i + 1; j < num.size(); ++j)
		{
			if (num[j] < num[Min])
			{
				Min = j;
			}
		}
		if (Min != i)
		{
			swap(num[Min], num[i]);
		}
	}
}
/*冒泡排序*/
void BubbleSort(vector<int> &num)
{
	if (num.empty())
		return;
	//总共需要比较n-1次，第i次需比较n-i趟
	for (unsigned int i = 0; i < num.size()-1; i++)
	{
		for (unsigned int j = 0; j < (num.size() - (i + 1)); ++j)
		{
			if (num[j] > num[j+1])
			{
				swap(num[j+1], num[j]);
			}
		}
	}
}
/*快速排序*/
void QuickSort(vector<int> &num,unsigned left,unsigned right)
{
	if (num.empty())
		return;
	if (left < right)
	{
		int i = Partition(num, left, right);
		QuickSort(num,left, i - 1);
		QuickSort(num, i+1, right);
	}
}
/*堆排序*/
void HeapSort(vector<int> &num)
{
	if (num.empty())
		return;
	BuildHeap(num);
	for (int i = num.size() - 1; i >= 0; i--)
	{
		swap(num[i], num[0]);
		AdjustHeap_maxroot(num, 0, i);
	}
}
/*归并排序*/
void MergeSort(vector<int> &num,unsigned int first,unsigned int last)
{
	if (num.empty())
		return;
	if (first < last)
	{
		unsigned int mid = (first + last) / 2;
		MergeSort(num, first, mid);
		MergeSort(num, mid + 1, last);
		MergeSortCore(num, first, mid, last);
	}

}
/*桶排序*/
void BucketSort(vector<int> &num)
{
	if (num.empty())
		return;
	vector< vector<int> > bucket(10,vector<int>(0,0));
	for (unsigned int i = 0;(!num.empty()); ++i)
	{
		int flag = num.back() / 10;
		bucket[flag].push_back(num.back());
		num.pop_back();

	}
	for (unsigned int i = 0; i < bucket.size(); ++i)
	{
		if (!bucket.empty())
			InsertSort(bucket[i]);
	}
	//num.clear();
	for (unsigned int i = 0; i < bucket.size(); ++i)
	{
		if (!bucket[i].empty())
		{
			for (unsigned int j = 0; j < bucket[i].size(); ++j)
			{
				num.push_back(bucket[i][j]);
			}
		}
	}
}
/*计数排序*/
void CountSort(vector<int> &num)
{
	if (num.empty())
		return;
	int max = 0;
	for (unsigned int i = 0; i < num.size(); ++i)
	{
		if (num[i]>max)
			max = num[i];
	}
	vector<int> count(max+1);
	for (unsigned int i = 0; i < num.size(); ++i)
	{
		count[num[i]]++;
	}
	for (unsigned int i = 0; i < count.size(); ++i)
	{
		if (count[i] != 0)
		{
			cout << " " << i << " ";
			count[i]--;
		}
			
	}
	cout << endl;
}


int main()
{
	//vector<int> num = { 5, 3, 7, 1, 9, 2, 4, 8, 6 };
	//vector<int> num = {9,8,7,6,5,4,3,2,1};
	vector<int> num = { 92, 87, 74, 63, 51, 44, 39, 20, 12 };
	CountSort(num);
	print(num);
	system("pause");
	return 0;
}