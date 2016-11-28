#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// use Reservoir Sampling
class Solution
{
private:
	ListNode *head;
public:
	Solution(ListNode* head)
	{
		this->head = head;
	}
	int getRandom()
	{
		int result;
		result = head->val;
		int count = 1;
		int k = 1;
		ListNode *node = head->next;
		while(node)
		{
			int r = rand() % (k + count);
			if(r < k)
				result = node->val;
			count++;
			node = node->next;
		}
		return result;
	}
};
