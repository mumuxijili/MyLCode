#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int countNumbersWithUniqueDigits(int n)
	{
		int result = 9;
		if(n == 0) return 1;
		if(n == 1) return 10;
		for(int i = 0; i <= n - 2; i++)
		{
			result = result * (9 - i);
		}
		result += countNumbersWithUniqueDigits(n - 1);
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.countNumbersWithUniqueDigits(3) << endl;
	return 0;
}