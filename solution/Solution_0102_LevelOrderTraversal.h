#include "SolutionBase.h"

#include "TreeNode.h"
#include <stack>
#include <vector>

class Solution_0102_LevelOrderTraversal : public SolutionBase
{
public:

    virtual void RunTest()
    {
		// create tree
		TreeNode *root = new TreeNode(1);
		TreeNode *left1 = new TreeNode(2);
		TreeNode *right1 = new TreeNode(3);
		root->left = left1;
		root->right = right1;
		TreeNode *left22 = new TreeNode(4);
		TreeNode *right22 = new TreeNode(5);
		right1->left = left22;
		right1->right = right22;

		std::vector<std::vector<int>> result = levelOrder(root);
		std::cout << "Solution_0094_InorderTraversal result" << std::endl;
		for (size_t i = 0; i < result.size(); i++)
		{
			for (size_t j = 0; j < result[i].size(); j++)
			{
				std::cout << result[i].at(j) << std::endl;
			}
		}

		// free tree
		TreeNode::FreeTreeNode(root);
    }

private:
	std::vector<std::vector<int>> levelOrder(TreeNode* root);
};

// level order traversal
static void levelorder(const TreeNode* root, std::vector<int> &result)
{
	if (nullptr == root)
		return;

	levelorder(root->left, result);
	result.push_back(root->val);
	inorder(root->right, result);
}

std::vector<std::vector<int>> Solution_0102_LevelOrderTraversal::levelOrder(TreeNode* root)
{
	std::vector<std::vector<int>> result;
	if (nullptr == root)
		return result;

	//inorder(root, result);

	return result;
}