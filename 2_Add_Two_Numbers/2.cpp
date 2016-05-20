#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		int a = 0;
		int b = 0;
		int c = 0;	//sum
		int d = 0;	//carry
		ListNode* pre = NULL;
		ListNode* head = NULL;
		while(l1 != NULL || l2 != NULL)
		{
			a = 0;
			b = 0;
			c = 0;
			//d = 0;
			if(l1 != NULL)
			{
				a = l1->val;
				l1 = l1->next;
			}
			if(l2 != NULL)
			{
				b = l2->val;
				l2 = l2->next;
			}
			c = (a + b + d) % 10;
			d = (a + b + d) / 10;
			// cout << "a " << a << endl;
			// cout << "b " << b << endl;
			// cout << "c " << c << endl;
			// cout << "d " << d << endl;
			ListNode* node = new ListNode(c);
			if(pre == NULL)
			{
				pre = node;
				head = node;
			}
			else
			{
				pre->next = node;
				pre = node;
			}
		}
		if(d != 0)
		{
			ListNode* node = new ListNode(d);
			pre->next = node;
			pre = node;
		}
		return head;
	}
};

int main()
{
	Solution s;
	ListNode* n;
	n = new ListNode(3);
	cout << n->val << endl;
	n = s.addTwoNumbers(new ListNode(5), new ListNode(5));
	cout << n->val << endl;
	system("pause");
	return 0;
}