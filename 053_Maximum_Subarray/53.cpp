#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxSubArray(vector<int>& nums)
	{
		int sum = 0;
		int result = nums[0];
		for(int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			result = (result > sum) ? result : sum;
			sum = (sum > 0) ? sum : 0;
		}
		return result;
	}
};
