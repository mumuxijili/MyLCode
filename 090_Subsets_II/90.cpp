#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i++)
		{
			result.push_back(vector<int>());
			vector<vector<int>> tmp = result;
			for(int j = 0; j < result.size(); j++)
			{
				result[j].push_back(nums[i]);
			}
			result.insert(result.end(), tmp.begin(), tmp.end());
		}
		result.push_back(vector<int>());
		sort(result.begin(), result.end());
		vector<vector<int>>::iterator pos = unique(result.begin(), result.end());
		result.erase(pos, result.end());
		return result;
	}
};
