#include <iostream>
#include <string>

using namespace std;
// time exceed
class Solution
{
public:
	string longestPalindrome(string s)
	{
		int len = s.length();
		if(isPalindrome(s)) return s;
		for(int i = len-1; i >= 0; i--)
		{
			for(int j = 0; j < len - i + 1; j++)
			{
				// cout << s.substr(i, j) << endl;
				if(isPalindrome(s.substr(j, i)))
					return s.substr(j, i);
			}
		}
		return s;
	}
private:
	bool isPalindrome(string s)
	{
		int l = s.length();
		for (int i = 0, j = l-1; i < j; i++, j--)
		{
			if(s[i] != s[j])
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("baa") << endl;
	return 0;
}