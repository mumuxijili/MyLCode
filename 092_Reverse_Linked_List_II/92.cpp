#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* reverseBetween(ListNode *head, int m, int n)
	{
		if(m == n) return head;
		int count = n - m;
		ListNode prehead(0);
		prehead.next = head;
		ListNode* pre = &prehead;
		while(--m) pre = pre->next;
		ListNode* cur = pre->next;
		while(count--)
		{
			ListNode* nextNode = cur->next;
			cur->next = nextNode->next;
			nextNode->next = pre->next;
			pre->next = nextNode;
		}
		return prehead.next;
	}
};
