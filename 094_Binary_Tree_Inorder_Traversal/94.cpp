#include <iostream>
#include <string>
#include <vector>
#include <stack>

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
	// recursive version
	// vector<int> inorderTraversal(TreeNode* root)
	// {
	// 	vector<int> result;
	// 	if(root == NULL) return result;
	// 	if(root->left != NULL)
	// 		result = inorderTraversal(root->left);
	// 	result.push_back(root->val);
	// 	if(root->right != NULL)
	// 	{
	// 		vector<int> tmp = inorderTraversal(root->right);
	// 		result.insert(result.end(), tmp.begin(), tmp.end());
	// 	}
	// 	return result;
	// }

	// iterative version
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode *> s;
		TreeNode *p = root;
		while(!s.empty() || p != NULL)
		{
			if(p != NULL)
			{
				s.push(p);
				p = p->left;
			}
			else
			{
				TreeNode *tmp = s.top();
				s.pop();
				result.push_back(tmp->val);
				p = tmp->right;
			}
		}
		return result;
	}
};
