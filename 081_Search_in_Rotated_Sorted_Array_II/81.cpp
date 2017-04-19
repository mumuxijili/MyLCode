#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	bool search(vector<int>& nums, int target)
	{
		int left = 0;
        if(nums.size() == 0) return false;
		int right = nums.size() - 1;
		int mid;
		while(left < right)
		{
			mid = (left + right) / 2;
			if(nums[mid] == target) return true;
			if(nums[mid] > nums[right])
			{
				if(target < nums[mid] && target >= nums[left])
					right = mid;
				else
					left = mid + 1;
			}
			else if(nums[mid] < nums[right])
			{
				if(target <= nums[right] && target > nums[mid])
					left = mid + 1;
				else
					right = mid;
			}
			else
				right--;
		}
		return target == nums[left] ? true : false;
	}
};
