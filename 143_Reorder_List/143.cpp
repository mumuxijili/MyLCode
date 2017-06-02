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
	ListNode* reverse(ListNode *head)
	{
		if(!head || !head->next) return head;

		ListNode *cur = head->next, *pre = head, *next = cur->next;
		while(cur)
		{
			cur->next = pre;
			pre = cur;
			cur = next;
			next = next ? next->next : NULL;
		}
		head->next = NULL;
		return pre;
	}

	void reorderList(ListNode* head)
	{
		if(!head || !head->next) return;

		ListNode *slow = head, *fast = head, *pre;
		while(fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;

		ListNode *head2 = reverse(slow);

		ListNode *cur = head;
		while(cur->next)
		{
			ListNode *tmp = cur->next;
			cur->next = head2;
			head2 = head2->next;
			cur->next->next = tmp;
			cur = tmp;
		}
		cur->next = head2;
	}
};
