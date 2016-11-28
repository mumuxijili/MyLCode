#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		map<int, int> m;
		for(vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
		{
			// if ((++m[*it] > (m.size() / 2)) && it > (nums.begin() + nums.size() / 2)) return *it;
			m[*it]++;
		}
		int max = m.begin()->second;
		int maxidx = m.begin()->first;
		for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			// if((*it).second >= (int)(nums.size() / 2)) return (*it).first;
			if (max < it->second)
			{
				max = it->second;
				maxidx = it->first;
			}
		}
		return maxidx;
	}
};

int main()
{
	Solution s;
	// int n[3] = {3, 2, 3};
	int n[3] = {6, 5, 5};
	vector<int> v(n, n+3);
	cout << s.majorityElement(v) << endl;
	return 0;
}