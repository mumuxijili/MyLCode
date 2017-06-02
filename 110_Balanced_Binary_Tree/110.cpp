#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	// top down method
	int level(TreeNode* root)
	{
		if(!root) return 0;
		return max(level(root->left), level(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root)
	{
		if(!root) return true;
		int left = level(root->left);
		int right = level(root->right);

		return (abs(left - right) <= 1) && isBalanced(root->left) && isBalanced(root->right);
	}
	// bottom up method
	int height(TreeNode* root)
	{
		if(!root) return 0;
		int leftHeight = height(root->left);
		if(leftHeight == -1) return -1;
		int rightHeight = height(root->right);
		if(rightHeight == -1) return -1;
		if(abs(leftHeight - rightHeight) > 1) return -1;
		return max(leftHeight, rightHeight) + 1;
	}
	bool isBalanced(TreeNode* root)
	{
		return (height(root) != -1);
	}
};
