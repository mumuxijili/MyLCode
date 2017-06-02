#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		int n = s.size();
		vector<bool> f(n + 1, false);
		f[0] = true;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i; j >= 0; j--)
			{
				if(f[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[n];
	}
};
