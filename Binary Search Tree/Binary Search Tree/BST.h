#ifndef __BST_H__
#define __BST_H__
#include <vector>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int n):val(n), left(NULL), right(NULL){};
};

class BinarySearchTree
{
public:
	BinarySearchTree(){}
	~BinarySearchTree(){}
	bool appendNode(int val);
	bool deleteNode(int val);
	bool appendNodes(vector<int> &node);
	void printInPre();
	void printInPost();
	void printInMid();
private:
	int Height_Tree = 0;
	int Num_Node = 0;
	int Height_Node = 0;
	TreeNode* root = NULL;
	vector<int> valInTree;
	
	void printNode(TreeNode* &nodeToPrint);
	void preOrder(TreeNode* &node);
	void postOrder(TreeNode* &node);
	void midOrder(TreeNode* &node);
	bool addNode(TreeNode* &ptr, TreeNode* &newNode);
	bool isExist(int val);
};



#endif