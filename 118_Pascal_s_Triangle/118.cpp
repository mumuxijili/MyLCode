#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> result;
		if(numRows == 0) return result;
		for(int i = 0; i < numRows; i++)
		{
			vector<int> cur;
			for(int j = 0; j < i + 1; j++)
			{
				if(j == 0 || j == i)
					cur.push_back(1);
				else
				{
					cur.push_back(result[i - 1][j - 1] + result[i - 1][j]);
				}
			}
			result.push_back(cur);
		}
		return result;
	}
};
