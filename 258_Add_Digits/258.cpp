#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution
{
public:
	int addDigits(int num)
	{
		string s = to_string(num);
		if (s.size() == 1) return num;
		
		int newnum = s.at(0) - '0';
		for (int i = 1; i < s.size(); i++)
			newnum += (s.at(i) - '0');
		return addDigits(newnum);
	}
};

int main()
{
	Solution s;
	int b = s.addDigits(38);
	cout << b << endl;
	return 0;
}