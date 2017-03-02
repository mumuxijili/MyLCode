#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		int n1 = num1.size();
		int n2 = num2.size();
		string total(n1 + n2, '0');
		// num2 * num1
		for(int i = n1 - 1; i >= 0; i--)
		{
			int currentSum = 0;
			int carry = 0;
			for(int j = n2 - 1; j >= 0; j--)
			{
				currentSum = ((total[i + j + 1] - '0') + ((num2[j] - '0') * (num1[i] - '0')) + carry) % 10;
				carry = ((total[i + j + 1] - '0') + ((num2[j] - '0') * (num1[i] - '0')) + carry) / 10;
				total[i + j + 1] = currentSum + '0';
			}
			total[i] = carry + '0';
		}
		int k;
		for(k = 0; k < total.size()； k++)
			if(total[k] != '0') break;
		if(k == total.size()) return "0";
		else return total.substr(k, total.size() - k + 1);
	}
};
