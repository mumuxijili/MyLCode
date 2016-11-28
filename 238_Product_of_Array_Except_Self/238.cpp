#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	vector<int> productExceptSelf(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> front(n);
		front[0] = 1;
		vector<int> back(n);
		back[0] = 1;
		vector<int> result(n);
		for(int i = 1; i < n; i++)
		{
			front[i] = front[i-1] * nums[i-1];
			back[i] = back[i-1] * nums[n-i];
		}
		for(int i = 0; i < n; i++)
			result[i] = front[i] * back[n-i-1];
		return result;
	}
};
