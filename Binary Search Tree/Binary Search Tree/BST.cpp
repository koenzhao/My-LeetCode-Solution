#include <iostream>
#include "BST.h"
using namespace std;

bool BinarySearchTree::appendNode(int val)
{
	if (isExist(val))
		return false;
   	TreeNode* newNode = new TreeNode(val);
	return addNode(root, newNode);
}

bool BinarySearchTree::isExist(int val)
{
	vector<int>::iterator i = valInTree.begin();
	for (; i != valInTree.end(); ++i)
	{
		if (val == *i)
			return true;
	}
	return false;
}

bool BinarySearchTree::addNode(TreeNode* &ptr, TreeNode* &newNode)
{
	if (NULL == ptr)
	{
		ptr = newNode;
		valInTree.push_back(newNode->val);
		return true;
	}
	if (newNode->val < ptr->val)
	{
		return addNode(ptr->left, newNode);
	}
	else if (newNode->val > ptr->val)
	{
		return addNode(ptr->right, newNode);
	}
	return false;
}

bool BinarySearchTree::appendNodes(vector<int> &node)
{
	if (node.empty())
		return false;
	bool flag = false;
	vector<int>::iterator i = node.begin();
	for (; i != node.end(); ++i)
	{
		flag = appendNode(*i);
	}
	return flag;
}

void BinarySearchTree::printNode(TreeNode* &nodeToPrint)
{
	if (nodeToPrint != NULL)
	{
		printf("%3d ", nodeToPrint->val);
	}
}

void BinarySearchTree::preOrder(TreeNode* &node)
{
	if (node != NULL)
	{
		printNode(node);
		preOrder(node->left);
		preOrder(node->right);
	}
}

void BinarySearchTree::postOrder(TreeNode* &node)
{
	if (node != NULL)
	{
		preOrder(node->left);
		preOrder(node->right);
		printNode(node);
	}
}

void BinarySearchTree::midOrder(TreeNode* &node)
{
	if (node != NULL)
	{
		preOrder(node->left);
		printNode(node);
		preOrder(node->right);
	}
}

void BinarySearchTree::printInPre()
{
	cout << "先序遍历：";
	preOrder(root);
	printf("\n");
}

void BinarySearchTree::printInPost()
{
	cout << "后序遍历：";
	postOrder(root);
	printf("\n");
}

void BinarySearchTree::printInMid()
{
	cout << "中序遍历：";
	midOrder(root);
	printf("\n");
}