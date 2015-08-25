#include <iostream>
#include <vector>
#include "BST.h"
using namespace std;
int main()
{
	vector<int> node = {5,2,3,1,7};
	BinarySearchTree BST1;
	BST1.appendNodes(node);
	//BST1.appendNode(5);
	BST1.printInPre();
	BST1.printInMid();
	BST1.printInPost();
	printf("\n");

	system("pause");
	return 0;
}