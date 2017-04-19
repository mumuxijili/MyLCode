#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		vector<vector<int>> paths(m, vector<int>(n));
		paths[0][0] = abs(obstacleGrid[0][0] - 1);
		for(int i = 1; i < m; i++)
		{
			if(obstacleGrid[i][0] == 0)
				paths[i][0] = paths[i - 1][0];
			else
				paths[i][0] = 0;
		}
		for(int i = 1; i < n; i++)
		{
			if(obstacleGrid[0][i] == 0)
				paths[0][i] = paths[0][i - 1];
			else
				paths[0][i] = 0;
		}

		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				if(obstacleGrid[i][j] == 0)
					paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
				else
					paths[i][j] = 0;
			}
		}
		return paths[m - 1][n - 1];
	}
};
