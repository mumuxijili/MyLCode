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
	vector<int> preorderTraversal(TreeNode* root)
	{
		if(!root) return vector<int>();
		vector<int> result;
		vector<TreeNode*> treeStack;
		treeStack.push_back(root);
		while(!treeStack.empty())
		{
			TreeNode *cur = treeStack.back();
			treeStack.pop_back();
			result.push_back(cur->val);
			if(!cur->right) treeStack.push_back(cur->right);
			if(!cur->left) treeStack.push_back(cur->left);
		}
		return result;
	}
};
