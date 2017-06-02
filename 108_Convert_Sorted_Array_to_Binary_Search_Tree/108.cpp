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
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		TreeNode* root = NULL;
		if(nums.empty()) return root;
		int idx = nums.size() / 2;
		root = new TreeNode(nums[idx]);
		vector<int> left(nums.begin(), nums.begin() + idx);
		root->left = sortedArrayToBST(left);
		vector<int> right(nums.begin() + idx + 1, nums.end());
		root->right = sortedArrayToBST(right);
		return root;
	}
};
