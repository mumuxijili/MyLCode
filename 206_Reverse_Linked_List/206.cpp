#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 注意指针的拷贝和赋值之间的区别，以及拷贝之前需要先分配空间。
class Solution
{
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* newhead = NULL;
		while(head)
		{
			if(newhead == NULL)
			{
				newhead = new ListNode(0);
				*newhead = *head;
				newhead->next = NULL;
				head = head->next;
			}
			else
			{
				ListNode* tmp = new ListNode(0);
				*tmp = *head;
				head = head->next;
				tmp->next = newhead;
				newhead = tmp;
			}
		}
		return newhead;
	}
};

int main()
{
	Solution s;
	ListNode* r;
	ListNode a = {5};
	ListNode b = {4};
	a.next = &b;
	r = s.reverseList(&a);
	return 0;
}