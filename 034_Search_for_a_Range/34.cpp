#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> result;
		if(nums.size() == 0)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		int lo = 0;
		int hi = nums.size() - 1;
		int mid;
		while(lo < hi)
		{
			mid = (lo + hi) / 2;
			if(nums[mid] < target)
			{
				lo = mid + 1;
			}
			else
			{
				hi = mid;
			}
		}
		if(nums[lo] != target)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		else
			result.push_back(lo);
		lo = 0;
		hi = nums.size() - 1;
		while(lo < hi)
		{
			mid = (lo + hi) / 2 + 1;
			if(nums[mid] > target)
			{
				hi = mid - 1;
			}
			else
			{
				lo = mid;
			}
		}
		result.push_back(hi);
		return result;
	}
};
