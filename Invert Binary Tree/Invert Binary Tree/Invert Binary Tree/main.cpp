#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
/*Invert Binary Tree*/
/*集合二叉树相关算法*/
struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* Create_BinaryTree(int* data,int ArrSize)
{
	TreeNode* Node = NULL;
	TreeNode* Node_Array[10] = {NULL};
	int i = 1;
	int j = 0;
	
	for (i = 1; i < ArrSize; ++i)
	{
		Node = (TreeNode*)malloc(sizeof(TreeNode));
		Node->data = data[i];
		Node->left = NULL;
		Node->right = NULL;
		Node_Array[i] = Node;
		if (i != 1)
		{
			j = i / 2;
			if (i % 2 == 0)
				Node_Array[j]->left = Node;
			else
				Node_Array[j]->right = Node;
		}
	}
	return Node_Array[1];
}

void PreOrder(TreeNode* ptr)//先序遍历
{
	if (!ptr)
		return;
	else
	{
		printf("%d ", ptr->data);
		PreOrder(ptr->left);
		PreOrder(ptr->right);
	}
}

void InOrder(TreeNode* ptr)//中序遍历
{
	if (!ptr)
		return;
	else
	{
		InOrder(ptr->left);
		printf("%d ", ptr->data);
		InOrder(ptr->right);
	}
}

void InOrder_Traverse(TreeNode* root)//中序遍历（非递归版）
{
	TreeNode* Stack[10], *ptr = root;
	int top = 0;
	bool Bool = true;
	if (root == NULL)
		printf("Binary Tree is Empty!\n");
	else
	{
		do
		{
			while (ptr != NULL)
			{
				Stack[++top] = ptr;
				ptr = ptr->left;
			}
			if (top == 0)
				Bool = false;
			else
			{
				ptr = Stack[top];
				top--;
				printf("%d ", ptr->data);
				ptr = ptr->right;
			}
		} while (Bool != false);
	}
}

void PostOrder(TreeNode* ptr)//后序遍历
{
	if (!ptr)
		return;
	else
	{
		PostOrder(ptr->left);
		PostOrder(ptr->right);
		printf("%d ", ptr->data);
	}

}
void swap(TreeNode* ptr)//交换左右孩子
{
	TreeNode* temp = NULL;
	temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

void InvertBinaryTree(TreeNode* ptr)//翻转二叉树
{
	if (!ptr) 
		return;
	else
	{
		swap(ptr);
		InvertBinaryTree(ptr->left);
		InvertBinaryTree(ptr->right);
	}
}

void Level(TreeNode* root)
{
	TreeNode* Queue[MAXSIZE], *ptr;
	int fornt, rear;
}

int main()
{
	int data[] = {0,4,2,7,1,3,6,9};
	TreeNode* Root_Node = NULL;
	int ArrSize = sizeof(data) / sizeof(int);
	Root_Node = Create_BinaryTree(data,ArrSize);
	
	/******************************
	PreOrder(Root_Node);
	printf("\n");
	InvertBinaryTree(Root_Node);
	PreOrder(Root_Node);
	printf("\n");
	******************************/
	
	InOrder(Root_Node);
	printf("\n");
	InOrder_Traverse(Root_Node);

	return 0;
}