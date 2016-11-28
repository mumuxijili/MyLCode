#include <string>
#include <iostream>
#include <windows.h>

using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int longest = 0;
		int len = s.length();
		int ascii[256];
		int curLen = 0;
		for(int i = 0; i < len; i++)
		{
			curLen = 0;
			for(int j = 0; j < 256; j++)
				ascii[j] = 0;
			for(int k = i; k < len; k++)
			{
				if(ascii[s[k]] != 0)
				{
					longest = curLen > longest ? curLen : longest;
					break;
				}
				else
				{
					ascii[s[k]]++;
					curLen++;
				}
			}
			longest = curLen > longest ? curLen : longest;
		}
		return longest = curLen > longest ? curLen : longest;
	}
};

int main()
{
	system("pause");
	return 0;
}