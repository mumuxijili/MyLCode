#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;
		int lval = maxDepth(root->left) + 1;
		int rval = maxDepth(root->right) + 1;
		return (lval > rval) ? lval : rval;
	}
};