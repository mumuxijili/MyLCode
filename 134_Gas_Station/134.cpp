#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		/*int tank = 0;
		int n = gas.size();
		bool flag = false;
		for(int i = 0; i < n; i++)
		{
			tank = 0;
			for(int j = 0; j < n; j++)
			{
				flag = false;
				tank += gas[(i + j) % n];
				if(tank >= cost[(i + j) % n])
				{
					flag = true;
				}
				tank -= cost[(i + j) % n];
				if(!flag) break;
			}
			if(flag) return i;
		}
		return -1;*/

		int total = 0;
		int subsum = INT_MAX;
		int start = 0;
		int n = gas.size();
		for(int i = 0; i < n; i++)
		{
			total += (gas[i] - cost[i]);
			if(total < subsum)
			{
				subsum = total;
				start = i + 1;
			}
		}
		return (total < 0) ? -1 : (start % n);
	}
};
