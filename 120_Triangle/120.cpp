#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int minimumTotal(vector<vector<int>>& triangle)
	{
		int n = triangle.size();
		vector<int> minsum(triangle.back());
		for(int layer = n - 2; layer >= 0; layer--)
		{
			for(int i = 0; i <= layer; i++)
			{
				minsum[i] = min(minsum[i], minsum[i + 1]) + triangle[layer][i];
			}
		}
		return minsum[0];
	}
};
