##Invert Binary Tree
2015/6/19 18:48:16 

Invert a binary tree.

	     4
	   /   \
	  2     7
	 / \   / \
	1   3 6   9

> to

	     4
	   /   \
	  7     2
	 / \   / \
	9   6 3   1


> Trivia:
> This problem was inspired by this original tweet by Max Howell:
> 
> Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.

>受Max Howell的启发，LeetCode才有了这个问题

>谷歌：90%的工程师用你写的软件（Homebrew），但是你不能在白板上翻转二叉树，你还是玩蛋儿去吧！

这道题最近颇火，原因如上，Homebrew的作者Max Howell去谷歌面试，本应该大牛面试大公司，没什么悬念的，但结果谷歌给人家出了一道翻转二叉树的题目，大牛说“老子不会”。然后谷歌也是霸道，不会啊！？不会滚犊子！之后就成了V2EX，知乎等程序员社区讨论的热门话题。LeetCode在两天后也上线了这道题目，难度定义为Easy，看来人家压根就没想过面试出这种题目啊。我感觉我走在人生的巅峰期了！

###初步想法
遍历树的每个节点，若有孩子，则将左右孩子交换。


```c

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void swap(struct TreeNode* ptr)
{
	struct TreeNode* temp = NULL;
	temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root)
		return;
	else
	{
		swap(root);
		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}

```

程序通过，难度等级为Easy。中间的过程复习了一遍二叉树：

二叉树在程序中的存储结构有两种：

* 顺序存储结构：将一个完全二叉树按照层次从上到下，从左到右的顺序给每一个值编号，然后按编号顺序将每个节点的值存储到对应的数组单元中。顺序存储要注意两个问题：1. 对于非完全二叉树需要转换成完全二叉树，然后再存入一维数组； 2. 对于一些不存在的节点，在数组中会以空值的形式出现，浪费内存空间。
* 链式存储结构：又叫二叉链表，每个节点具有3个域，分别存储本身值，左孩子，右孩子；