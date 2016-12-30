#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		// time exceed...
		// vector<vector<int>> result;
		// for(int i = 0; i < nums.size(); i++)
		// {
		// 	for(int j = i+1; j < nums.size(); j++)
		// 	{
		// 		int gap = 0 - nums[i] - nums[j];
		// 		if(find(nums.begin()+j+1, nums.end(), gap) != nums.end())
		// 		{
		// 			vector<int> triple;
		// 			triple.push_back(nums[i]);
		// 			triple.push_back(nums[j]);
		// 			triple.push_back(gap);
		// 			sort(triple.begin(), triple.end());
		// 			result.push_back(triple);
		// 		}
		// 	}
		// }
		// sort(result.begin(), result.end());
		// result.erase(unique(result.begin(), result.end()), result.end());
		// return result;
		
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i++)
		{
			int gap = 0 - nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			while(front < back)
			{
				int sum = nums[front] + nums[back];
				if(sum < gap) front++;
				else if(sum > gap) back--;
				else
				{
					vector<int> triple;
					triple.push_back(nums[i]);
					triple.push_back(nums[front]);
					triple.push_back(nums[back]);
					result.push_back(triple);
					while(front < back && nums[front] == triple[1]) front++;
					while(front < back && nums[back] == triple[2]) back--;
				}
			}
			while(i < nums.size() && nums[i] == nums[i+1]) i++;
		}
		return result;
	}
};

int main()
{
	int n[6] = {-1, 0, 1, 2, -1, -4};
	vector<int> v(n, n+6);
	Solution s;
	vector<vector<int>> r = s.threeSum(v);
	for(int i = 0; i < r.size(); i++)
	{
		for(auto a : r[i])
		{
			cout << a;
		}
		cout << endl;
	}
	return 0;
}