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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		TreeNode* root = NULL;
		if(postorder.empty() || inorder.empty()) return root;
		root = new TreeNode(postorder.back());
		vector<int>::iterator it = find(inorder.begin(), inorder.end(), postorder.back());
		int count = it - inorder.begin();
		vector<int> inorderleft(inorder.begin(), it);
		vector<int> postorderleft(postorder.begin(), postorder.begin() + count);
		root->left = buildTree(inorderleft, postorderleft);
		vector<int> inorderright(it + 1, inorder.end());
		vector<int> postorderright(postorder.begin() + count, postorder.end() - 1);
		root->right = buildTree(inorderright, postorderright);
		return root;
	}
};
