#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		int n = s.size();
		int i = 0;
		int j = n - 1;
		while(i <= j)
		{
			if(isalnum(s[i]))
			{
				if(isupper(s[i]))
					s[i] = s[i] + 32;
			}
			else
			{
				i++;
				continue;
			}
			if(isalnum(s[j]))
			{
				if(isupper(s[j]))
					s[j] = s[j] + 32;
			}
			else
			{
				j--;
				continue;
			}
			if(s[i] != s[j])
				return false;
			else
			{
				i++;
				j--;
			}
		}
		return true;
	}
};
