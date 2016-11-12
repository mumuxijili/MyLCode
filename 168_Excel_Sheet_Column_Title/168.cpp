#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	string convertToTitle(int n)
	{
		string s = "";
		int result, remainder;
		result = n;
		do{
			remainder = result % 26;
			result = result / 26;
			char c;
			if(remainder == 0)
			{
				c = 'Z';
				result -= 1;
			}
			else
				c = 64 + remainder;
			s += c;
		}while(result != 0);
		std::reverse(s.begin(), s.end());
		return s;
	}
};

int main()
{
	Solution s;
	cout << s.convertToTitle(26) << endl;
	return 0;
}
