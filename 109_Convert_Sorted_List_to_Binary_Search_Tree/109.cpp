#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
	TreeNode* sortedListToBST(ListNode* head)
	{
		//快慢法，寻找中间点
		if(!head) return NULL;
		if(!head->next) return new TreeNode(head->val);

		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *pre = head;

		while(fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		// slow is middle node
		pre->next = NULL;
		TreeNode *root = new TreeNode(slow->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(slow->next);
		return root;
	}
};
