#include <iostream>
#include <string>
#include <hash_map>

using namespace std;
using namespace __gnu_cxx;

class Solution
{
public:
	int firstUniqChar(string s)
	{
		hash_map<char, int> hm;
		for(string::iterator it = s.begin(); it < s.end(); it++)
		{
			if (hm.find(*it) == hm.end())
			{
				hm[*it] = 1;
			}
			else
			{
				hm[*it]++;
			}
		}
		for(string::iterator it = s.begin(); it < s.end(); it++)
		{
			if(hm[*it] == 1)
			{
				return (it - s.begin());
			}
		}
		return -1;
	}
};


int main()
{
	Solution s;
	cout << s.firstUniqChar("loveleetcode") << endl;
	return 0;
}