#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
	int reverse(int x)
	{
		long long sum = 0;
		int sign = 1;
		if(x < 0)
		{
			sign = -1;
			x = -x;
		}
		string s = to_string(x);
		int len = s.length();
		for(int i = len-1; i >= 0; i--)
		{
			sum += pow(10, i) * (s[i]-'0');
		}
		sum = sum * sign;
		return (sum < INT_MIN || sum > INT_MAX) ? 0 : sum;
	}
};

int main()
{
	Solution s;
	cout << s.reverse(1534236469) << endl;
	return 0;
}