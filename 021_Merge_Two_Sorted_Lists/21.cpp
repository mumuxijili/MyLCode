#include <iostream>
#include <string>

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *head;
		ListNode top(INT_MIN);
		head = &top;
		while(l1 && l2)
		{
			if(l1->val < l2->val)
			{
				head->next = l1;
				l1 = l1->next;
			}
			else
			{
				head->next = l2;
				l2 = l2->next;
			}
			head = head->next;
		}
		head->next = l1 ? l1 : l2;
		return top.next;
	}
};
