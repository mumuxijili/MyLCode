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
	ListNode* insertionSortList(ListNode* head)
	{
		if(!head || !head->next) return head;
		ListNode *cur = head->next;
		ListNode *end = head;
		ListNode *start = head;
		ListNode *newhead = NULL;
		ListNode *pre = head;
		ListNode *minNode = head;
		ListNode *minPre = NULL;
		int min = head->val;
		while(start->next)
		{
			pre = start;
			cur = start->next;
			min = start->val;
			minNode = start;
			while(cur)
			{
				if(cur->val < min)
				{
					min = cur->val;
					minNode = cur;
					minPre = pre;
				}
				pre = cur;
				cur = cur->next;
			}

			if(minNode == start)
			{
				start = minNode->next;
			}
			else
			{
				minPre->next = minNode->next;
				minNode->next = NULL;
			}
			
			if(newhead == NULL)
			{
				newhead = minNode;
				end = minNode;
			}
			else
			{
				end->next = minNode;
				end = minNode;
			}
			
		}
		end->next = start;
		end = start;
		return newhead;
	}
};
