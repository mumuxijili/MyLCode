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
	int sumNumbers(TreeNode* root)
	{
		int sum = 0;
		if(!root) return 0;
		sumNumbers(root, 0, sum);
		return sum;
	}

	void sumNumbers(TreeNode* root, int parentSum, int& sum)
	{
		if(!root->left && !root->right)
		{
			sum += (parentSum * 10 + root->val);
			return;
		}
		parentSum = parentSum * 10 + root->val;
		if(root->left) sumNumbers(root->left, parentSum, sum);
		if(root->right) sumNumbers(root->right, parentSum, sum);
	}
};
