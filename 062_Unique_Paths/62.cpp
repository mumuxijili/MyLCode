#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		// time exceed
		// if(m == 1 | n == 1) return 1;
		// return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		
		vector<vector<int>> paths(m, vector<int>(n));
		for(int i = 0; i < m; i++) paths[i][0] = 1;
		for(int i = 0; i < n; i++) paths[0][i] = 1;

		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
			}
		}
		return paths[m - 1][n - 1];
	}
};
