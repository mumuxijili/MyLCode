#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int numTrees(int n)
	{
		if(n == 0 || n == 1) return 1;
		vector<int> result(n+1, 0);
		result[0] = 1;
		result[1] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int k = 1; k <= i; k++)
			{
				result[i] = result[i] + result[k - 1] * result[i - k];
			}
		}
		return result[n];
	}
};
