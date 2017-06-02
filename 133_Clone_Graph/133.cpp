#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct UndirectedGraphNode
{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution
{
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if(!node) return NULL;
		vector<UndirectedGraphNode*> neighbors;
		UndirectedGraphNode* newNode = new(node->label);

	}
};
