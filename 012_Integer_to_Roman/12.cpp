#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	string intToRoman(int num)
	{
		string table[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           	{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           	{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           	{"", "M", "MM", "MMM"}
                          };
		string roman = "";
		int x;
		int count = 0;
		while(num)
		{
			x = num % 10;
			roman = table[count][x] + roman;
			num = num / 10;
			count++;
		}
		return roman;
	}
};

int main()
{
	Solution s;
	cout << s.intToRoman(24) << endl;
	return 0;
}