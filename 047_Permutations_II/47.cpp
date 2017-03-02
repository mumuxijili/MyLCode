#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		permutation(nums, 0, nums.size() - 1, result);
		return result;
	}
private:
	void swap(vector<int>& nums, int a, int b)
	{
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}
	void permutation(vector<int> nums, int begin, int end, vector<vector<int>> &result)
	{
		if(begin == end)
		{
			result.push_back(nums);
			return;
		}
		else
		{
			for(int j = begin; j <= end; j++)
			{
				if(j != begin && nums[j] == nums[begin]) continue;
				swap(nums, j, begin);
				permutation(nums, begin + 1, end, result);
			}
		}
	}
};
