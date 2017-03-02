#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		if(nums.size() == 0) return -1;
		int lo = 0;
		int hi = nums.size() - 1;
		while(lo < hi)
		{
			int mid = (lo + hi) / 2;
			if(nums[mid] == target) return mid;
			if(nums[lo] <= nums[mid])
			{
				if(nums[lo] <= target && target < nums[mid])
				{
					hi = mid - 1;
				}
				else
				{
					lo = mid + 1;
				}
			}
			else
			{
				if(nums[mid] < target && nums[hi] >= target)
				{
					lo = mid + 1;
				}
				else
				{
					hi = mid - 1;
				}
			}
		}
		return nums[lo] == target ? lo : -1;
	}
}