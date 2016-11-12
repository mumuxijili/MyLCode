#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
	int titleToNumber(string s)
	{
		int n = s.size();
		int sum = 0;
		for(string::iterator it = s.begin(); it < s.end(); it++)
		{
			sum = sum + (*it - 'A' + 1) * (int)pow(26, --n);
		}
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.titleToNumber("AA") << endl;
	return 0;
}