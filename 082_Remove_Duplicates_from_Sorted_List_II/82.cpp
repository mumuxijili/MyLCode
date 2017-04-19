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

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		if(head == NULL) return NULL;
		ListNode newhead(-1);
		newhead.next = head;
		ListNode* pre = &newhead;
		ListNode* cur = head;
		ListNode* curhead = head;
		int curval;
		bool flag = false;
		while(cur->next)
		{
			if(cur->next->val == cur->val)
			{
				flag = true;
				curval = cur->val;
				if(cur->next->next)
				{
					if(curhead == cur)
						curhead = cur->next->next;
					pre->next = cur->next->next;
					cur = cur->next->next;
				}
				else
				{
					if(curhead == cur)
						curhead = NULL;
					pre->next = NULL;
					cur = NULL;
					break;
				}
			}
			else if(flag && cur->val == curval)
			{
				if(curhead == cur)
					curhead = cur->next;
				pre->next = cur->next;
				cur = cur->next;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
		if(cur && curval == cur->val)
		{
			if(curhead == cur)
				curhead = NULL;
			else
				pre->next = NULL;
		}
		return curhead;
	}
};
