#include <iostream>
#include <string>
#include <vector>
#include <queue>

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
	bool isSymmetric(TreeNode* root)
	{
		// iteration solution
		if(!root) return true;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		queue<TreeNode*> p, q;
		p.push(left);
		q.push(right);
		while(!p.empty() && !q.empty())
		{
			left = p.front();
			p.pop();
			right = q.front();
			q.pop();
			if(left == NULL && right == NULL) continue;
			if(left == NULL || right == NULL) return false;
			if(left->val != right->val) return false;
			p.push(left->left);
			p.push(left->right);
			q.push(right->right);
			q.push(right->left);
		}
		return true;
		// recursive solution
		/*if(!root) return true;
		return isSymmetric(root->left, root->right);*/
	}

	bool isSymmetric(TreeNode* left, TreeNode* right)
	{
		if(left == NULL && right == NULL) return true;
		if(left == NULL || right == NULL) return false;
		if(left->val != right->val) return false;
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};
