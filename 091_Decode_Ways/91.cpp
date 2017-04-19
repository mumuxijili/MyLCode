#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
	void decoding(string s, int start, int& count)
	{
		if(start == s.size())
		{
			count++;
			return;
		}
		int num = 0;
		for(int i = start; i < start + 2 && i < s.size() + 1; i++)
		{
			num = num * 10 + (s[i] - '0');
			if(num >= 1 && num <= 26)
			{
				decoding(s, start + 1, count);
			}
		}
		return;
	}
public:
	int numDecodings(string s)
	{
		if(s.size() == 0) return 0;
		int count = 0;
		decoding(s, 0, count);
		return count;
	}
};
