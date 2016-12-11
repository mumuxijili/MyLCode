#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int myAtoi(string str)
	{
		long long sum = 0;
		int sign = 1;
		while(str[0] == ' ' || str[0] == '	') str.erase(0, 1);
		if(str[0] == '-')
		{
			sign = -1;
			str.erase(0, 1);
		}
		else if(str[0] == '+')
		{
			str.erase(0, 1);
		}
		int len = str.length();
		for(auto c : str)
		{
			if(c > '9' || c < '0') break;
			sum = sum * 10 + (c - '0');
			if(sum * sign > INT_MAX) return INT_MAX;
			if(sum * sign < INT_MIN) return INT_MIN;
		}
		sum *= sign;
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi("       010") << endl;
	return 0;
}