#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string addBinary(string a, string b)
	{
		int n1 = a.size();
		int n2 = b.size();
		string result = "";
		n1--;
		n2--;
		int digit;
		int carry = 0;
		while(n1 >= 0 || n2 >= 0 || carry == 1)
		{
			int d1, d2;
			d1 = n1 < 0 ? 0 : a[n1] - '0';
			d2 = n2 < 0 ? 0 : b[n2] - '0';
			n1--;n2--;
			digit = (d1 + d2 + carry) % 2;
			carry = (d1 + d2 + carry) / 2;
			result = (char)(digit + '0') + result;
		}
		return result;
	}
};
