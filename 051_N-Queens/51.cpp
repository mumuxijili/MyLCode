#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

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
	void rowQueen(vector<int>& queen, int row, int n, vector<vector<string>>& result)
	{
		if(row == n)
		{
			vector<string> tmp;
			for(int i = 0; i < n; i++)
			{
				string s(n, '.');
				s[queen[i]] = 'Q';
				tmp.push_back(s);
				//queen[i] = -1;
			}
			// cout << "hh" << endl;
			result.push_back(tmp);
		}
		else
		{
			for(int col = 0; col < n; col++)
			{
				// for(auto q : queen) cout << q << " ";
				if(can_place(queen, row, col, n))
				{
					// cout << row << " " << col << endl;
					queen[row] = col;
					rowQueen(queen, row + 1, n, result);
				}
			}
		}
	}
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<int>  queen(n, -1);
		vector<vector<string>> result;
		rowQueen(queen, 0, n, result);
		return result;
	}
};

int main()
{
	Solution s;
	vector<vector<string>> r = s.solveNQueens(4);
	for(vector<vector<string>>::iterator it1 = r.begin(); it1 != r.end(); it1++)
	{
		for(vector<string>::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
			cout << *it2 << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
