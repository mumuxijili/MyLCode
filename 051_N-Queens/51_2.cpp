#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
	bool can_place(vector<int> &queen, int row, int col, int n)
	{
		//if(queen[row] != -1) return false;
		//if(find(queen.begin(), queen.end(), col) != queen.end()) return false;
		for(int i = 0; i < row; i++)
		{
			if(queen[i] == col) return false;
			if(abs(i - row) == abs(queen[i] - col)) return false;
		}
		return true;
	}
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> result;
		vector<int> queen(10, -1);
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
				if(row == 0) break;
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
				vector<string> tmp;
				for(int i = 0; i < n; i++)
				{
					string s(n, '.');
					s[queen[i]] = 'Q';
					tmp.push_back(s);
				}
				result.push_back(tmp);
				col = queen[row] + 1;
				queen[row] = -1;
				continue;
			}
			row++;
		}
		return result;
	}
};
