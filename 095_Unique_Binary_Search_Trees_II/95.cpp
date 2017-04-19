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
private:
	vector<TreeNode*> generateTrees(int start, int end)
	{
		vector<TreeNode*> res;
		if(start == end)
		{
			res.push_back(new TreeNode(start));
			return res;
		}
		if(start > end)
		{
			res.push_back(NULL);
			return res;
		}
		for(int i = start; i <= end; i++)
		{
			vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
			vector<TreeNode*> rightTrees = generateTrees(i + 1, end);

			for(int j = 0; j < leftTrees.size(); j++)
				for(int k = 0; k < rightTrees.size(); k++)
				{
					TreeNode *rootptr = new TreeNode(i);
					rootptr->left = leftTrees[j];
					rootptr->right = rightTrees[k];
					res.push_back(rootptr);
				}
		}
		return res;
	}
public:
	vector<TreeNode*> generateTrees(int n)
	{
	    if (n == 0) return vector<TreeNode*>(NULL);
		return generateTrees(1, n);
	}
};
