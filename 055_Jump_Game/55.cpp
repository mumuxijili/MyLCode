#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
// 	// time exceed
// private:
// 	bool canJump2(vector<int>& nums, int begin)
// 	{
// 		int n = nums.size();
// 		if(begin == n - 1)
// 			return true;
// 		for(int i = 1; i <= nums[begin]; i++)
// 		{
// 			if(canJump2(nums, begin + i))
// 				return true;
// 		}
// 		return false;
// 	}
// public:
// 	bool canJump(vector<int>& nums)
// 	{
// 		return canJump2(nums, 0);
// 	}
public:
	bool canJump(vector<int>& nums)
	{
		int n = nums.size();
		int reach = 0;
		int i;
		for(i = 0; i < n && i <= reach; i++)
			reach = max(reach, nums[i] + i);
		return i == n;
	}
};
