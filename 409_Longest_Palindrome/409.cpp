#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int longestPalindrome(string s)
	{
		unordered_map<char, int> m;
		int count = 0;
		for(int i = 0; i < s.size(); i++)
		{
			++m[s[i]];
		}
		for(unordered_map<char, int>::iterator it = m.begin(); it != m.end(); )
		{
			count += (it->second / 2) * 2;
			if(it->second == 0)
				m.erase(it);
			else
				it++;
		}
		for(unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++)
		{
			if(it->second %2 == 1)
			{
				count++;
				break;
			}
		}
		return count;
	}
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("abccccdd") << endl;
	return 0;
}
