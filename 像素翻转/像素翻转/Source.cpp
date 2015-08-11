/***************************************
时间限制：3秒       空间限制：32768K

题目描述:
有一副由NxN矩阵表示的图像，这里每个像素用一个
int表示，请编写一个算法，在不占用额外内存空间
的情况下(即不使用缓存矩阵)，将图像顺时针旋转90度。
给定一个NxN的矩阵，和矩阵的阶数N,请返回旋转后
的NxN矩阵,保证N小于等于500，图像元素小于等于256。

测试样例：[[1,2,3],
		  [4,5,6],
		  [7,8,9]],
返回：[[7,4,1],
	   [8,5,2],
	   [9,6,3]]
***************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#define N 5
using namespace std;

class Transform {
public:
	vector<vector<int> > transformImage(vector< vector<int> > mat, int n)
	{
		// write code here
		if (n > 500)
			return mat;
		int start = 0;
		int end = n - 1;
		int i = 0;
		for (; start < (n / 2); ++start, --end)
		{
			while (i < (end-start))
			{
				mat = transform(mat, start, end);
				++i;
			}
			i = 0;			
		}
		return mat;
	}
	vector< vector<int> > transform(vector< vector<int> > mat, int start, int end)
	{
		int i = start;
		int j = start;
		int tmp = 0;
		for (j = start; j <= end; ++j)
		{
			swap(mat[i][j], tmp);
		}
		j--;
		for (i = i + 1; i <= end; ++i)
		{
			swap(mat[i][j], tmp);
		}
		i--;
		for (j = j - 1; j >= start; --j)
		{
			swap(mat[i][j], tmp);
		}
		j++;
		for (i = i - 1; i >= start; --i)
		{
			swap(mat[i][j], tmp);
		}
		i++;
		return mat;
	}
	void swap(int &a, int &b)
	{
		int temp;
		temp = b;
		b = a;
		a = temp;
	}
};

void Print_Mat(vector< vector<int> > mat)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << setw(3) << mat[i][j] << " ";
		}
		cout << endl;
	}
}
int main()
{
	vector< vector<int> > mat(N);
	for (int i = 0; i < N; ++i)
	{
		mat[i].resize(N);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j] = (N*i)+(j+1);
		}
	}
	Print_Mat(mat); 
	Transform tran;
	mat = tran.transformImage(mat, N);
	cout << endl;
	Print_Mat(mat);

	return 0;
}