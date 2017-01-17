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
	ListNode* swapPairs(ListNode* head)
	{
		ListNode top(INT_MIN);
		ListNode* new_head = &top;
		new_head->next = head;
		ListNode* pre_head;
		pre_head = new_head;
		while(head && head->next)
		{
			ListNode* tmp = head->next;
			pre_head->next = head->next;
			head->next = tmp->next;
			tmp->next = head;
			pre_head = head;
			head = head->next;
		}
		return new_head->next;
	}
};
