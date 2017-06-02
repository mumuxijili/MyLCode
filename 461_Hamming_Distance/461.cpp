#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int hammingDistance(int x, int y)
	{
		int n = x ^ y;
		int c = 0;
		for(c; n; c++)
			n &= (n - 1);
		return c;
	}
};
