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
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> result;
		if(!root) return result;
		vector<int> level;
		queue<TreeNode*> Nodes;
		Nodes.push(root);
		while(!Nodes.empty())
		{
			int size = Nodes.size();
			while(size)
			{
				TreeNode* cur = Nodes.front();
				Nodes.pop();
				level.push_back(cur->val);
				if(cur->left) Nodes.push(cur->left);
				if(cur->right) Nodes.push(cur->right);
				size--;
			}
			result.push_back(level);
			level.clear();
		}
		reverse(result.begin(), result.end());
		return result;
	}
};
