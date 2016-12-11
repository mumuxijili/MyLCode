#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		unordered_map<char, int> dict = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}};
		int len = s.length();
		int sum = dict[s[len-1]];
		int i = len-1;
		for(; i > 0; i--)
		{
			if(dict[s[i-1]] >= dict[s[i]])
				sum += dict[s[i-1]];
			else
				sum -= dict[s[i-1]];
		}
		return sum;
	}
};

int main()
{
	Solution s;
	cout << s.romanToInt("XIV") << endl;
	return 0;
}