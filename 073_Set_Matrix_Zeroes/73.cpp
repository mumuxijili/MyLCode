#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
	void setZeros(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		set<int> row, col;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
			{
				if(matrix[i][j] == 0)
				{
					row.insert(i);
					col.insert(j);
				}
			}
		for(set<int>::iterator it = row.begin(); it != row.end(); it++)
		{
			for(int j = 0; j < n; j++)
				matrix[*it][j] = 0;
		}
		for(set<int>::iterator it = col.begin(); it != col.end(); it++)
		{
			for(int i = 0; i < m; i++)
				matrix[i][*it] = 0;
		}
		return;
	}
};

int main()
{
	Solution s;
	int a1[4] = {0,0,0,5};
	int a2[4] = {4,3,1,4};
	int a3[4] = {0,1,1,4};
	int a4[4] = {1,2,1,3};
	int a5[4] = {0,0,1,1};
	vector<int> v1(a1, a1+4);
	vector<int> v2(a2, a2+4);
	vector<int> v3(a3, a3+4);
	vector<int> v4(a4, a4+4);
	vector<int> v5(a5, a5+4);
	vector<vector<int>> m;
	m.push_back(v1);
	m.push_back(v2);
	m.push_back(v3);
	m.push_back(v4);
	m.push_back(v5);

	s.setZeros(m);
	return 0;
}