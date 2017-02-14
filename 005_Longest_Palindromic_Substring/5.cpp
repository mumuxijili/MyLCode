#include <iostream>
#include <string>
#include <vector>

using namespace std;
// time exceed
class Solution
{
public:
	string longestPalindrome(string s)
	{
// 		int len = s.length();
// 		if(isPalindrome(s)) return s;
// 		for(int i = len-1; i >= 0; i--)
// 		{
// 			for(int j = 0; j < len - i + 1; j++)
// 			{
// 				// cout << s.substr(i, j) << endl;
// 				if(isPalindrome(s.substr(j, i)))
// 					return s.substr(j, i);
// 			}
// 		}
// 		return s;
// 	}
// private:
// 	bool isPalindrome(string s)
// 	{
// 		int l = s.length();
// 		for (int i = 0, j = l-1; i < j; i++, j--)
// 		{
// 			if(s[i] != s[j])
// 				return false;
// 		}
// 		return true;
		int n = s.size();
		int max_len = 1;
		int start = 0;
		bool f[n][n];
		fill_n(&f[0][0], n*n, false);
		for(int i = 0; i < n; i++)
		{
			f[i][i] = true;
			for(int j = 0; j < i; j++)
			{
				if(i == j+1)
				{
					f[j][i] = (s[i] == s[j]);
				}
				else
				{
					f[j][i] = ((s[i] == s[j]) && (f[j+1][i-1]));
				}
				if(f[j][i] && max_len < i - j + 1)
				{
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("baa") << endl;
	return 0;
}