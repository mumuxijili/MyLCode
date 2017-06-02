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
		if(!root) return;
		
		TreeLinkNode *cur, *head, *tail;
		cur = root;
		head = tail = NULL;
		while(cur)
		{
			if(cur->left)
			{
				if(tail)
				{
					tail->next = cur->left;
					tail = tail->next;
				}
				else
				{
					head = tail = cur->left;
				}
			}
			if(cur->right)
			{
				if(tail)
				{
					tail->next = cur->right;
					tail = tail->next;
				}
				else
				{
					head = tail = cur->right;
				}
			}
			cur = cur->next;
			if(!cur)
			{
				cur = head;
				head = tail = NULL;
			}
		}
	}
};
