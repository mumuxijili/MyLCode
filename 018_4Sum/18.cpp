#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				int front = j + 1;
				int back = nums.size() - 1;
				int gap = target - nums[i] - nums[j];
				while(front < back)
				{
					int sum = nums[front] + nums[back];
					if(sum > gap) back--;
					else if(sum < gap) front++;
					else
					{
						vector<int> tmp;
						tmp.push_back(nums[i]);
						tmp.push_back(nums[j]);
						tmp.push_back(nums[front]);
						tmp.push_back(nums[back]);
						result.push_back(tmp);
						for(auto t : tmp) cout << t << " ";
						cout << endl;
						while(front < back && nums[front] == tmp[2]) front++;
						while(front < back && nums[back] == tmp[3]) back--;
					}
				}
				while(j < nums.size() && nums[j] == nums[j+1]) j++;
			}
			while(i < nums.size() && nums[i] == nums[i+1]) i++;
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = {1,0,-1,0,-2,2};
	s.fourSum(v, 0);
	return 0;
}