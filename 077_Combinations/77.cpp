#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
	void combine2(int start, int num, int n, int k, vector<int>& tmp, vector<vector<int>>& res)
	{
		if(k == num)
		{
			res.push_back(tmp);
			return;
		}
		for(int i = start; i <= n; i++)
		{
			tmp.push_back(i);
			combine2(i + 1, num + 1, n, k, tmp, res);
			tmp.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<vector<int>> result;
		if(n < k) return result;
		vector<int> tmp(0, k);
		combine2(1, 0, n, k, tmp, result);
		return result;
	}
};
