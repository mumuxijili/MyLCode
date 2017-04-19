#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
	//recursion time exceed
// private:
// 	int minPathSum(vector<vector<int>>& grid, int row, int col)
// 	{
// 		int up = INT_MAX;
// 		int left = INT_MAX;
// 		if(row == 0 && col == 0) return grid[row][col];
// 		if(row > 0)
// 			up = minPathSum(grid, row - 1, col);
// 		if(col > 0)
// 			left = minPathSum(grid, row, col - 1);
// 		return grid[row][col] + min(up, left);
// 	}
// public:
// 	int minPathSum(vector<vector<int>>& grid)
// 	{
// 		int m = grid.size();
// 		if(m == 0) return 0;
// 		int n = grid[0].size();
// 		return minPathSum(grid, m - 1, n - 1);
// 	}
public:
	int minPathSum(vector<vector<int>>& grid)
	{
		int m = grid.size();
		if(m == 0) return 0;
		int n = grid[0].size();
		vector<vector<int>> dis(m, vector<int>(n, INT_MAX));
		dis[0][0] = grid[0][0];
		for(int i = 1; i < m; i++) dis[i][0] = grid[i][0] + dis[i - 1][0];
		for(int j = 1; j < n; j++) dis[0][j] = grid[0][j] + dis[0][j - 1];
		for(int i = 1; i < m; i++)
		{
			for(int j = 1; j < n; j++)
			{
				dis[i][j] = grid[i][j] + min(dis[i - 1][j], dis[i][j - 1]);
			}
		}
		return dis[m - 1][n - 1];
	}
};
