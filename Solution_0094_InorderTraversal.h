#include "SolutionBase.h"

#include "TreeNode.h"
#include <stack>
#include <vector>

class Solution_0094_InorderTraversal : public SolutionBase
{
public:

    virtual void RunTest()
    {
		// create tree
		TreeNode *root = new TreeNode(1);
		TreeNode *right = new TreeNode(2);
		root->right = right;
		TreeNode *left2 = new TreeNode(3);
		right->left = left2;

		std::vector<int> result = inorderTraversal(root);
		std::cout << "Solution_0094_InorderTraversal result" << std::endl;
		for (size_t i = 0; i < result.size(); i++)
		{
			std::cout << result[i] << std::endl;
		}

		// free tree
		TreeNode::FreeTreeNode(root);
    }

private:
	std::vector<int> inorderTraversal(TreeNode* root);
};

// zhong xu traversal
static void levelorder(const TreeNode* root, std::vector<int> &result)
{
	if (nullptr == root)
		return;

	levelorder(root->left, result);
	result.push_back(root->val);
	levelorder(root->right, result);
}

std::vector<int> Solution_0094_InorderTraversal::inorderTraversal(TreeNode* root)
{
	std::vector<int> result;
	if (nullptr == root)
		return result;

	levelorder(root, result);

	return result;
}