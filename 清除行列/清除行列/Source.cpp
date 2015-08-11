/**********************************************************
题目描述

请编写一个算法，若MxN矩阵中某个元素为0，则将其所在的行与列清零。
给定一个MxN的int[][]矩阵(C++中为vector>)mat和矩阵的阶数n，请返
回完成操作后的int[][]矩阵(C++中为vector>)，保证n小于等于300，矩
阵中的元素为int范围内。
测试样例：
[[1,2,3],
 [0,1,2],
 [0,0,1]]
返回：
[[0,0,3],
 [0,0,0],
 [0,0,0]]
**********************************************************/

#include <iostream>
#include <vector>
#include <iomanip>
#define N 3
using namespace std;

class Clearer {
public:
	vector<vector<int> > clearZero(vector<vector<int> > mat, int n) 
	{
		// write code here
		if (n >= 300)
			return mat;
		int* row = new int[n];
		int* col = new int[n];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mat[i][j] == 0)
				{
					row[i] = 1;
					col[j] = 1;
				}
			}
		}
		GetRowCol(mat,row,col,n);
		return mat;
	}
private:
	void GetRowCol(vector<vector<int> >& mat, int* row, int* col, int n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (row[i] == 1)
			{
				ClearRow(mat,i,n);
			}
			if (col[i] == 1)
			{
				ClearCol(mat, i,n);
			}
		}
	}
	void ClearRow(vector<vector<int> >& mat, int row,int n)
	{
		for (int i = 0; i < n; ++i)
		{
			mat[row][i] = 0;
		}
	}
	void ClearCol(vector<vector<int> >& mat, int col,int n)
	{
		for (int i = 0; i < n; ++i)
		{
			mat[i][col] = 0;
		}
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
	vector<vector<int> > mat(N);
	for (int i = 0; i < N; ++i)
	{
		mat[i].resize(N);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j] = N*i + (j + 1);
		}
	}
	//mat[1][1] = 0;
	mat[1][0] = 0;
	Print_Mat(mat);
	cout << "=============================" << endl;
	Clearer cle;
	mat = cle.clearZero(mat, N);
	Print_Mat(mat);

	//system("pause");
	return 0;
}