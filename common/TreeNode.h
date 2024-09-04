#include "stdio.h"
#include <iostream>

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

public:
	static void FreeTreeNode(TreeNode *root)
	{
		if (nullptr == root)
			return;

		FreeTreeNode(root->left);
		FreeTreeNode(root->right);
		
		free(root);
		root = nullptr;
	}

};