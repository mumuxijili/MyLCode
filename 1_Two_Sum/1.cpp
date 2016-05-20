#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <windows.h>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int sum;
		int len = nums.size();
		vector<int> result;
		unordered_map<int, int> mymap;
		for(int i = 0; i < len; i++)
		{
			mymap[nums[i]] = i;
		}
		for(int i = 0; i < len; i++)
		{
			int gap = target - nums[i];
			if (mymap.find(gap) != mymap.end() && mymap[gap] > 0)
			{
				result.push_back(i);
				result.push_back(mymap[gap]);
				return result;
			}
		}
		return result;
		// for(int i = 0; i < len; i++)
		// {
		// 	for(int j = i + 1; j < len; j++)
		// 	{
		// 		sum = nums.at(i) + nums.at(j);
		// 		if(sum == target)
		// 		{
		// 			result.push_back(i);
		// 			result.push_back(j);
		// 			return result;
		// 		}
		// 	}
		// }
	}
};

int main()
{
	
	system("pause");
	return 0;
}