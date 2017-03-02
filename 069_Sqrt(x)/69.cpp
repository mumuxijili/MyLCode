#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int mySqrt(int x)
	{
		if(x == 0) return 0;
		if(x == 1) return 1;
		int left = 1;
		int right = x;
		int mid;
		while(left < right)
		{
			mid = (left + right) / 2;
			if(mid > x / mid)
			{
				if(mid - 1 <= x / (mid - 1))
				{
					return mid - 1;
				}
				right = mid - 1;
			}
			else if(mid < x / mid)
			{
				if(mid + 1 > x / (mid + 1))
				{
					return mid;
				}
				left = mid + 1;
			}
			else
				return mid;
		}
	}
};
