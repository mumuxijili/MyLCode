#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		TreeNode* root = NULL;
		if(preorder.empty() || inorder.empty()) return root;
		root = new TreeNode(preorder.front());
		//vector<int>::iterator it = find(inorder.begin(), inorder.end(), preorder.front());
		int countleft, countright;
		for(int i = 0; i < inorder.size(); i++)
			if(inorder[i] == preorder.front())
			{
				countleft = i;
				break;
			}
		countright = inorder.size() - countleft - 1;
		vector<int> left1(preorder.begin() + 1, preorder.begin() + countleft + 1);
		vector<int> right1(inorder.begin(), inorder.begin() + countleft);
		root->left = buildTree(left1, right1);
		vector<int> left2(preorder.begin() + countleft + 1, preorder.end());
		vector<int> right2(inorder.begin() + countleft + 1, inorder.end());
		root->right = buildTree(left2, right2);
		return root;
	}
};
