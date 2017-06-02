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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		vector<vector<int>> result;
		if(!root) return result;
		bool flag = false;
		vector<int> level;
		queue<TreeNode*> Nodes;
		Nodes.push(root);
		Nodes.push(NULL);
		while(!Nodes.empty())
		{
			TreeNode* cur = Nodes.front();
			Nodes.pop();
			if(!cur)
			{
				if(flag)
					reverse(level.begin(), level.end());
				result.push_back(level);
				level.clear();
				flag = !flag;
				if(!Nodes.empty()) Nodes.push(NULL);
			}
			else
			{
				level.push_back(cur->val);
				if(cur->left) Nodes.push(cur->left);
				if(cur->right) Nodes.push(cur->right);
			}
		}
		return result;
	}
};
