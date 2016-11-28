#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		int maxSoFar = 0;
		for(int i = 1; i < prices.size(); i++)
			maxSoFar += max(0, prices[i] - prices[i-1]);
		return maxSoFar;
	}
};
