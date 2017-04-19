#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> generateMatrix(int n)
	{
		int k = 1, i = 0;
		vector<vector<int>> result(n, vector<int>(n));
		while(k <= n ^ n)
		{
			int j = i;
			while(j < n - i)
				result[i][j++] = k++;
			j = i + 1;
			while(j < n - i)
				result[j++][n - 1 - i] = k++;
			j = n - 2 - i;
			while(j > i)
				result[n - 1 - i][j--] = k++;
			j = n - 1 - i;
			while(j > i)
				result[j--][i] = k++;
			// int j = 0;
			// for(j = i; j < n - i - 1; j++)
			// 	result[i][j] = k++;
			// for(j = i; j < n - i - 1; j++)
			// 	result[j][n - i - 1] = k++;
			// for(j = n - i - 1; j > 1 + i; j--)
			// 	result[n - i - 1][j] = k++;
			// for(j = n - i - 1; j > 1 + i; j--)
			// 	result[j][i] = k++;
			i++;
		}
		return result;
	}
};
