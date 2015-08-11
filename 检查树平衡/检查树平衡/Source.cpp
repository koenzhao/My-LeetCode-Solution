/**************************************************
题目描述

实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于
树中的任意一个结点，其两颗子树的高度差不超过1。
给定指向树根结点的指针TreeNode* root，请返回一个bool，
代表这棵树是否平衡。
**************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Balance {
public:
	bool isBalance(TreeNode* root) {
		// write code here
		if (root == NULL)
			return true;
		int left_depth = Get_Depth(root->left);
		int right_depth = Get_Depth(root->right);
		int diff = left_depth-right_depth;
		diff = abs(diff);
		if (diff > 1)
			return false; 
		else
			return (isBalance(root->left) && isBalance(root->right));

	}

	int Get_Depth(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left_depth = Get_Depth(root->left);
		int right_depth = Get_Depth(root->right);
		if (left_depth > right_depth)
			return left_depth + 1;
		else
			return right_depth + 1;
	}
	
};

int main()
{
	
	
	return 0;
}