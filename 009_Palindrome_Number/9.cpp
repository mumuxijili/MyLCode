#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if(x < 0) return false;
		int sum = 0;
		int origin = x;
		while(x)
		{
			sum = sum * 10 + x % 10;
			x = x / 10;
		}
		cout << sum << endl;
		return sum == origin ? true : false;
	}
};

int main()
{
	Solution s;
	cout << s.isPalindrome(1);
	return 0;
}