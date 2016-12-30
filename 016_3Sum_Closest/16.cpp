#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int result = INT_MIN;
		int closest = INT_MAX;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i++)
		{
			int front = i + 1;
			int back = nums.size() - 1;
			while(front < back)
			{
				int sum = nums[i] + nums[front] + nums[back];
				int gap = abs(sum - target);
				if(gap <= closest)
				{
					closest = gap;
					result = sum;
					// if(closest == 0) return result;
				}
				if(sum - target > 0) back--;
				else front++;
			}
		}
		return result;
	}
};
