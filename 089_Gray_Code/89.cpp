#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
	// G(i) = i ^ (i / 2)
// public:
// 	vector<int> grayCode(int n)
// 	{
// 		vector<int> result(1 << n);
// 		for(int i = 0; i < (1 << n); i++)
// 			result[i] = i ^ (i >> 1);
// 		return result;
// 	}
public:
	vector<int> grayCode(int n)
	{
		if(n == 0) return vector<int>(1, 0);
		vector<vector<int>> result(2);
		vector<int> res;
		for(int i = 1; i <= n; i++)
		{
			int total = 1 << i;
			int j;
			for(j = 0; j < total / 2; j++)
			{
				result[j].insert(result[j].begin(), 0);
			}
			for( ; j < total; j++)
			{
				result[j].insert(result[j].begin(), 1);
			}
			if(total == 1 << n) break;
			for(int k = total - 1; k >= 0; k--)
			{
				result.push_back(result[k]);
			}
		}
		for(int i = 0; i < result.size(); i++)
		{
			int tmp = 0;
			for(int j = 0; j < n; j++)
			{
				tmp = (result[i][j] == 0 ? 0 : 1 << (n - j - 1)) + tmp;
			}
			res.push_back(tmp);
		}
		return res;
	}
};
