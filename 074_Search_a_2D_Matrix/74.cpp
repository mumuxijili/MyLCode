#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int m = matrix.size();
		if(m == 0) return false;
		int n = matrix[0].size();
		if(n == 0) return false;
		int left = 0;
		int right = n - 1;
		int mid;
		if(target < matrix[0][0] || target > matrix[m - 1][n - 1]) return false;
		if(target >= matrix[m - 1][0] && target <= matrix[m - 1][n - 1])
		{
			while(left + 1 < right)
			{
				mid = left + (right - left) / 2;
				if(matrix[m - 1][mid] == target) return true;
				if(matrix[m - 1][mid] < target) left = mid;
				else right = mid;
			}
			if(target == matrix[m - 1][left] || target == matrix[m - 1][right]) return true;
			else return false;
		}
		left = 0;
		right = m - 1;
		while(left + 1 < right)
		{
			mid = left + (right - left) / 2;
			if(matrix[mid][0] == target) return true;
			if(matrix[mid][0] < target) left = mid;
			else right = mid;
		}
		int row = left;
		// cout << row;
		left = 0;
		right = n - 1;
		while(left + 1 < right)
		{
			mid = left + (right - left) / 2;
			if(matrix[row][mid] == target) return true;
			if(matrix[row][mid] < target) left = mid;
			else right = mid;
		}
		if(target == matrix[row][left] || target == matrix[row][right]) return true;
		else return false;
		return false;
	}
};

int main()
{
	Solution s;
	int a1[4] = {1,   3,  5,  7};
	int a2[4] = {10, 11, 16, 20};
	int a3[4] = {23, 30, 34, 50};
	// int a4[4] = {1,2,1,3};
	// int a5[4] = {0,0,1,1};
	vector<int> v1(a1, a1+4);
	vector<int> v2(a2, a2+4);
	vector<int> v3(a3, a3+4);
	// vector<int> v4(a4, a4+4);
	// vector<int> v5(a5, a5+4);
	vector<vector<int>> m;
	m.push_back(v1);
	m.push_back(v2);
	m.push_back(v3);
	// m.push_back(v4);
	// m.push_back(v5);
	cout << s.searchMatrix(m, 11);
	return 0;
}