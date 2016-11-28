#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
public:
	vector<int> topKFrequent(vector<int>&nums, int k)
	{
		unordered_map<int, int> m;
		vector<int> result;
		for(int i = 0; i < nums.size(); i++)
			++m[nums[i]];
		priority_queue<pair<int, int>> pq;
		for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			pq.push(make_pair(it->second, it->first));
			if(pq.size() > m.size()-k)
			{
				result.push_back(pq.top().second);
				pq.pop();
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	int n[6] = {1,1,1,2,2,3};
	vector<int> v(n, n+6);
	vector<int> r;
	r = s.topKFrequent(v, 2);
	for(vector<int>::iterator it=r.begin(); it!=r.end(); it++)
		cout << *it << endl;
	return 0;
}