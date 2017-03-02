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
		/*
		ListNode* cur = head;
        if(cur == NULL) return head;
		while(cur->next != NULL)
		{
			ListNode* after = cur->next;
			while(cur->val == after->val)
			{
			    if(after->next == NULL)
				{
					cur->next = NULL;
					return head;
				}
				cur->next = after->next;
				after = cur->next;
			}
			cur = after;
		}
		return head;
		 */
		ListNode* cur = head;
		while(cur)
		{
			while(cur->next && cur->val == cur->next->val)
			{
				cur->next = cur->next->next;
			}
			cur = cur->next;
		}
		return head;
	}
};
