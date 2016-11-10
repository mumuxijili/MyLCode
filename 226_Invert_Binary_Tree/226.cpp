#include <iostream>
#include <string>

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
	TreeNode* invertTree(TreeNode* root)
	{
		if (root == NULL) return root;
		TreeNode* lt = root->left;
		TreeNode* rt = root->right;
		root->left = invertTree(rt);
		root->right = invertTree(lt);
		return root;
	}
};
