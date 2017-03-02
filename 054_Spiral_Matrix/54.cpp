#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		if(m == 0) return vector<int>(0);
		int n = matrix[0].size();
		int loop = min(m, n) / 2;

		vector<int> result;
		for(int k = 0; k < loop; k++)
		{
			for(int i = k; i < n - 1 - k; i++)
				result.push_back(matrix[k][i]);
			for(int i = k; i < m - 1 - k; i++)
				result.push_back(matrix[i][n - 1 - k]);
			for(int i = n - 1 - k; i >= k + 1; i--)
				result.push_back(matrix[m - 1 - k][i]);
			for(int i = m - 1 - k; i >= k + 1; i--)
				result.push_back(matrix[i][k]);
		}
		if(min(m, n) % 2 == 1)
		{
			for(int i = loop; i < m - loop; i++)
				for(int j = loop; j < n - loop; j++)
					result.push_back(matrix[i][j]);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> a1 = {1, 2, 3};
	vector<int> a2 = {4, 5, 6};
	vector<int> a3 = {7, 8, 9};
	vector<vector<int>> m;
	m.push_back(a1);
	m.push_back(a2);
	m.push_back(a3);
	vector<int> result;
	result = s.spiralOrder(m);
	for(auto r : result)
		cout << r << " ";
	return 0;
}
