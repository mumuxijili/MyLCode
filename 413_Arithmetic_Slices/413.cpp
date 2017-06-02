#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int>& A)
	{
		vector<int> res;
		if(A.size() < 3) return 0;
		int last = A[1] - A[0];
		int num = 2;
		int N = 0;
		for(int i = 2; i < A.size(); i++)
		{
			if(A[i] - A[i - 1] == last)
			{
				num++;
				continue;
			}
			else
			{
				last = A[i] - A[i - 1];
				if(num >= 3)
					res.push_back(num);
				num = 2;
			}
		}
		if(num >= 3)
			res.push_back(num);
		for(int i = 0; i < res.size(); i++)
		{
			N += (1 + (res[i] - 2)) * (res[i] - 2) / 2;
		}
		return N;
	}
};
