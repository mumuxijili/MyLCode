#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	int next;
	ListNode(int x) : val(x), next(NULL) {}	
};

class Solution
{
public:
	ListNode* rotateRight(ListNode* head, int k)
	{
        if(!head) return head;
		ListNode* right = head;
		ListNode* newhead = head;
		int count = 1;
		while(right->next)
		{
			count++;
			right = right->next;
		}
		right->next = head;
		if(k %= count)
		{
			for(int i = 0; i < count - k; i++)
				right = right->next;
		}
		newhead = right->next;
		right->next = NULL;
		return newhead;
	}
};
