#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		if(s.size() != t.size()) return false;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		int res = 0;
		for(int i = 0; i < s.size(); i++)
			if(s[i] ^ t[i]) return false;
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.isAnagram("anagram", "nagaram") << endl;
	return 0;
}