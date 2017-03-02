#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	double myPow(double x, int n)
	{
		// if(x == double(0)) return 0;
		// int sign = 1;
		// if(n < 0)
		// {
		// 	n = -n;
		// 	sign = -1;
		// }
		// if(n == 0) return 1;
		// if(n == 1) x = x;
		// else x = x * myPow(x, n - 1);
		// if(sign == -1)
		// {
		// 	x = 1 / x;
		// }
		// return x;
		double y = 1.0;
        if(n == INT_MIN)
        {
            n = INT_MAX;
            x = 1 / x;
            y = y * x;
        }
		if(n < 0)
		{
			n = -n;
			x = 1 / x;
		}
		if(n == 0) return 1;
		while(n > 0)
		{
			if((n % 2) == 1)
			{
				y = y * x;
			}
			n = n / 2;
			x = x * x;
		}
		return y;
	}
};
