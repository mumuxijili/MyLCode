#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int maxProduct(vector<int>& nums)
	{
		if(nums.size() == 0) return 0;
		int maxhere = nums[0];
		int minhere = nums[0];
		int maxsofar = nums[0];
		for(int i = 1; i < nums.size(); i++)
		{
			int mx = maxhere, mn = minhere;
			maxhere = max(max(nums[i], nums[i] * mx), nums[i] * mn);
			minhere = min(min(nums[i], nums[i] * mn), nums[i] * mx);
			maxsofar = max(maxhere, maxsofar);
		}
		return maxsofar;
	}
};
