#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
	bool found(vector<vector<char>>& board, string word, int idx, int row, int col)
	{
		char curchar = board[row][col];
		bool res = false;
		if(word[idx] != board[row][col]) return false;
		if(idx == word.size() - 1)
			return true;
		if(!res && row < board.size() - 1)
		{
			board[row][col] = '*';
			res = found(board, word, idx + 1, row + 1, col);
		}
		if(!res && row > 0)
		{
			board[row][col] = '*';
			res = found(board, word, idx + 1, row - 1, col);
		}
		if(!res && col < board[0].size() - 1)
		{
			board[row][col] = '*';
			res = found(board, word, idx + 1, row, col + 1);
		}
		if(!res && col > 0)
		{
			board[row][col] = '*';
			res = found(board, word, idx + 1, row, col - 1);
		}
		board[row][col] = curchar;
		return res;
	}
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		if(board.size() == 0 || word.size() == 0) return false;
		int M = board.size();
		int N = board[0].size();
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(found(board, word, 0, i, j))
					return true;
			}
		}
		return false;
	}
};
