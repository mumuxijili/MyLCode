#include <iostream>
#include <string>

using namespace std;
/**
 * use Xor
 */
class Solution
{
public:
	char findTheDifference(string s, string t)
	{
		int i;
		int res = 0;
		for (i = 0; i < s.size(); i++)
		{
			res ^= s[i] ^ t[i];
		}
		return (res ^ t[i]);
	}
};

int main()
{
	Solution s;
	char c = s.findTheDifference("hello", "hellpo");
	cout << c << endl;
	return 0;
}