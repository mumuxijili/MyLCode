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
	ListNode *detectCycle(ListNode *head)
	{
		ListNode *slow, *fast;
		slow = head;
		fast = head;
		while(fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow == fast)
			{
				ListNode *slow2 = head;
				while(slow2 != slow)
				{
					slow = slow->next;
					slow2 = slow2->next;
				}
				return slow2;
			}
		}
		return NULL;
	}
};
