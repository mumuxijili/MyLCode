#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		if(numRows == 1) return s;
		string result = "";
		int len = s.length();
		int gap = numRows * 2 - 2;
		int interval = gap;
		int i, j;
		for(i = 0; i < numRows; i++)
		{
			interval = gap - (2 * i);
			// cout << interval << endl;
			for(j = i; j < len; )
			{
				// cout << j << endl;
				result += s[j];
				if(interval == 0) interval = gap;
				j += interval;
				interval = (interval == gap ? gap : gap - interval);
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3) << endl;
	return 0;
}