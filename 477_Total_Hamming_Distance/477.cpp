#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int totalHammingDistance(vector<int>& nums)
	{
		int result = 0;
		if(nums.size() <= 1) return 0;
		for(int i = 0; i < 32; i++)
		{
			int count = 0;
			for(auto n : nums)
			{
				if(n & (1 << i)) count++;
			}
			result += (count * (nums.size() - count));
		}
		return result;
	}
};
