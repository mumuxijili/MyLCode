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
	int minDepth(TreeNode* root)
	{
		// DFS
		if(!root) return 0;
		if(!root->left && !root->right) return 1;
		if(!root->left && root->right) return minDepth(root->right) + 1;
		if(root->left && !root->right) return minDepth(root->left) + 1;
		return min(minDepth(root->left), minDepth(root->right)) + 1;
		// BFS
		queue<TreeNode*> Nodes;
		int level = 0;
		if(!root) return 0;
		Nodes.push(root);
		while(!Nodes.empty())
		{
			level++;
			int size = Nodes.size();
			for(int i = 0; i < size; i++)
			{
				TreeNode* cur = Nodes.front();
				Nodes.pop();
				if(cur->left) Nodes.push(cur->left);
				if(cur->right) Nodes.push(cur->right);
				if(!cur->left && !cur->right) return level;
			}
		}
		return -1;
	}
};
