#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string addStrings(string num1, string num2)
	{
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		int carry = 0;
		string result = "";
		for( ; i >=0 && j >= 0; i--, j--)
		{
			int sum = (num1[i]-'0') + (num2[j]-'0');
			result = (char)((((sum + carry) % 10)) + '0') + result;
			carry = (sum + carry) / 10;
		}
		for( ; i >= 0; i--)
		{
			int sum = (num1[i]-'0');
			result = (char)((((sum + carry) % 10)) + '0') + result;
			carry = (sum + carry) / 10;
		}
		for( ; j >=0; j--)
		{
			int sum = (num2[j]-'0');
			result = (char)((((sum + carry) % 10)) + '0') + result;
			carry = (sum + carry) / 10;
		}
		if(carry)
		{
			result = (char)(carry + '0') + result;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.addStrings("1024", "233") << endl;
	return 0;
}