#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> getRow(int rowIndex)
	{
		vector<int> result(rowIndex + 1, 1);
		
		long cur = 1;
		int j = 1;
		for(int i = rowIndex; i > rowIndex / 2; i--)
		{
			cur *= i;
			cur /= j;
			j++;
			result[i - 1] = cur;
			result[j - 1] = cur;
		}

		return result;
	}
};
