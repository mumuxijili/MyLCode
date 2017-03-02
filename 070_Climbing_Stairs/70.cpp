#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int climbStairs(int n)
	{
		//// time exceed
		// if(n == 1)
		// 	return 1;
		// if(n == 2)
		// 	return 2;
		// return climbStairs(n - 1) + climbStairs(n - 2);
		int a = 1, b = 0;
		int result = 0;
		for(int i = 0; i < n; i++)
		{
			result = a + b;
			b = a;
			a = result;
		}
		return result;
	}
};
