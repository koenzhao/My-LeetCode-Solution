/*
题目描述

对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返
回一个链表ListNode，代表该深度上所有结点的值，请按树上从左往右的
顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过
100000。
*/

#include <iostream>
using namespace std;
struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) :
val(x), left(NULL), right(NULL) {
}
};

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class TreeLevel {
public:
	ListNode* getTreeLevel(TreeNode* root, int dep) {
		// write code here
		if (root == NULL || dep > GetTreeDeep(root))
			return NULL;

	}
	//求二叉树深度
	int GetTreeDeep(TreeNode* node)
	{
		int deep = 0;
		if (node)
		{
			int leftDeep = GetTreeDeep(node->left);
			int rightDeep = GetTreeDeep(node->right);
			deep = leftDeep >= rightDeep ? (leftDeep+1) : (rightDeep+1);
		}
		return deep;
	}
};

int main()
{
	
	return 0;
}