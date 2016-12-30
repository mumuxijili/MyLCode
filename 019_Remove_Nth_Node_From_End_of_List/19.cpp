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
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		int counter = 0;
        ListNode new_head(-1);
        new_head.next = head;
		ListNode *cur = &new_head;
		ListNode *nth = &new_head;
		while(cur->next)
		{
			if(counter < n)
			{
				counter++;
				cur = cur->next;
			}
			else
			{
				nth = nth->next;
				cur = cur->next;
			}
		}
		nth->next = nth->next->next;
		return new_head.next;
	}
};

int main()
{
	Solution s;
	ListNode a(1);
	ListNode b(2);
	a.next = &b;
	s.removeNthFromEnd(&a, 2);
	return 0;
}