#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		int row[9][9] = {false};
		int col[9][9] = {false};
		int square[9][9] = {false};

		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				if(board[i][j] != '.')
				{
					int num = board[i][j] - '0' - 1;
					int k = i / 3 * 3 + j / 3;
					if(row[i][num] || col[j][num] || square[k][num]) return false;
					row[i][num] = col[j][num] = square[k][num] = true;
				}
			}
		return true;
	}
};
