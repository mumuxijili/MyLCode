#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if(nums.size() == 0) return 0;
		if(nums.size() == 1) return 1;
		int count = 1;
		int a = nums[0];
		for(vector<int>::iterator it = nums.begin() + 1; it != nums.end();)
		{
			if(*it == a)
			{
				a = *it;
				it = nums.erase(it);
				continue;
			}
			else
			{
				count++;
				a = *it;
				it++;
			}
		}
		return count;
	}
};
