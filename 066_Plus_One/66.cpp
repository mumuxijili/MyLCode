#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> plusOne(vector<int>& digits)
	{
		int carry = 0;
		int digit = 0;
		for(int i = digits.size() - 1; i >= 0; i--)
		{
			int tmp;
			if(i == digits.size() - 1)
				tmp = digits[i] + carry + 1;
			else
				tmp = digits[i] + carry;
			digit = tmp % 10;
			carry = tmp / 10;
			digits[i] = digit;
		}
		if(carry != 0)
			digits.insert(digits.begin(), carry);
		return digits;
	}
};
