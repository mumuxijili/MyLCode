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
	int sumOfLeftLeaves(TreeNode* root)
	{
		return sumOfLeftLeaves2(root, 0);
	}
private:
	int sumOfLeftLeaves2(TreeNode* root, int flag)
	{
		// flag: 0 is root, 1 is left, 2 is right
		if (!root) return 0;
		if (flag == 0)
		{
			return (sumOfLeftLeaves2(root->left, 1) + sumOfLeftLeaves2(root->right, 2));
		}
		else if (flag == 1)
		{
			if ((root->left == NULL) && (root->right == NULL)) return root->val;
			else
				return (sumOfLeftLeaves2(root->left, 1) + sumOfLeftLeaves2(root->right, 2));
		}
		else
		{
			return (sumOfLeftLeaves2(root->left, 1) + sumOfLeftLeaves2(root->right, 2));
		}
		// if((root->left==NULL) && (root->right==NULL)) return
	}
};
