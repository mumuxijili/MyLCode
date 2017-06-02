#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		// recursive
		/*if(!root) return;
		TreeLinkNode* pre = root;
		TreeLinkNode* cur = NULL;
		while(pre->left)
		{
			cur = pre;
			while(cur)
			{
				cur->left->next = cur->right;
				if(cur->next)
					cur->right->next = cur->next->left;
				cur = cur->next;
			}
			pre = pre->left;
		}*/
		// non-recursive
		if(!root) return;
		while(root->left)
		{
			TreeLinkNode* root2 = root;
			root->left->next = root->right;
			while(root2->next)
			{
				root2->right->next = root2->next->left;
				root2 = root2->next;
				root2->left->next = root2->right;
			}
			root = root->left;
		}
	}
};
