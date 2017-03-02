#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int lengthOfLastWord(string s)
	{
		int length = 0;
		for(int i = s.size() - 1; i >= 0; i--)
		{
			if(s[i] == ' ')
				if(length == 0)
					continue;
				else
					break;
			else
				length++;
		}
		return length;
	}
};
