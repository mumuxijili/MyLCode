#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		if(n == 1)
		{
			return "1";
		}
		string tmp;
		tmp = countAndSay(n - 1);
		string res = "";
		int count = 1;
		char c = tmp[0];
		for(int i = 1; i < tmp.size(); i++)
		{
			if(tmp[i] == c)
			{
				count++;
			}
			else
			{
				res += (char)(count + '0');
				res += (c);
				c = tmp[i];
				count = 1;
			}
		}
		res += (char)(count + '0');
		res += (c);
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.countAndSay(3) << endl;
	return 0;
}