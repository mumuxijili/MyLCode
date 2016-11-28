#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums)
	{
		unordered_map<int, int> m;
		for(int i = 0; i < nums.size(); i++)
			++m[nums[i]];
		for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++)
			if (it->second != 3) return it->first;
		return 0;
	}
};
