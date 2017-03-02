#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<int> path;
		vector<vector<int>> result;
		dfs(candidates, path, result, target, 0);
		return result;
	}
private:
	void dfs(vector<int>& candidates, vector<int>& path, vector<vector<int>>& result, int gap, int start)
	{
		if(gap == 0)
		{
			result.push_back(path);
			return;
		}
		for(int i = start; i < candidates.size(); i++)
		{
			if(gap < candidates[i]) return;		//剪枝
			path.push_back(candidates[i]);
			dfs(candidates, path, result, gap - candidates[i], i);
			path.pop_back();
		}
	}
};
