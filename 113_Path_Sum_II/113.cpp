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
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<vector<int>> result;
		vector<int> path;
		if(!root) return result;
		findPath(root, sum, result, path);
		return result;
	}

	void findPath(TreeNode* root, int sum, vector<vector<int>>& result, vector<int>& path)
	{
		if(!root) return;
		if(!root->left && !root->right && root->val == sum)
		{
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root->val);
		if(root->left) findPath(root->left, sum - root->val, result, path);
		if(root->right) findPath(root->right, sum - root->val, result, path);
		path.pop_back();
	}
};
