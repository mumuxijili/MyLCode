#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<string>> partition(string s)
	{
		vector<vector<string>> result;
		vector<string> cur;
		if(s.empty()) return result;
		dfs(s, 0, result, cur);
		return result;
	}

	void dfs(string s, int index, vector<vector<string>>& result, vector<string>& cur)
	{
		if(index == s.size())
		{
			result.push_back(cur);
			return;
		}
		for(int i = index; i < s.size(); i++)
		{
			if(isPalindrome(s, index, i))
			{
				cur.push_back(s.substr(index, i - index + 1));
				dfs(s, i + 1, result, cur);
				cur.pop_back();
			}
		}
	}

	bool isPalindrome(string s, int start, int end)
	{
		while(start <= end)
		{
			if(s[start++] != s[end--])
				return false;
		}
		return true;
	}
};
