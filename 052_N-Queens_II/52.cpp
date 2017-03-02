#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
private:
	bool can_place(vector<int>& queen, int row, int col, int n)
	{
		for(int i = 0; i < row; i++)
			if(queen[i] == col || (abs(i - row) == abs(queen[i] - col)))
				return false;
		return true;
	}
public:
	int totalNQueens(int n)
	{
		vector<int> queen(10, -1);
		int result = 0;
		int row = 0, col = 0;
		while(row < n)
		{
			while(col < n)
			{
				if(can_place(queen, row, col, n))
				{
					queen[row] = col;
					col = 0;
					break;
				}
				else
					col++;
			}
			if(queen[row] == -1)
			{
				if(row == 0)
					break;
				else
				{
					row--;
					col = queen[row] + 1;
					queen[row] = -1;
					continue;
				}
			}
			if(row == n - 1)
			{
				result++;
				col = queen[row] + 1;
				queen[row] = -1;
				continue;
			}
			row++;
		}
		return result;
	}
};
