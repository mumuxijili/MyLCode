#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string result = "";
		if (strs.size() < 1) return result;
		int size = strs[0].size();
		int i = 0;

		string firstS = strs[0];
		strs.erase(strs.begin());
		while(i < size)
		{
			char c = firstS[i];
			// char c = strs[0][i];
			for(auto s : strs)
			{
				if(i >= s.size())
					return result;
				if(s[i] != c)
					return result;
			}
			// for(vector<string>::iterator it = strs.begin()+1; it != strs.end(); it++)
			// {
			// 	// cout << (*it)[i] << endl;
			// 	if(i >= it->size())
			// 		return result;
			// 	if((*it)[i] != c)
			// 		return result;
			// }
			i++;
			result = result + c;
		}
		return result;
	}
};

int main()
{
	Solution s;
	string n[2] = {"a", "b"};
	vector<string> v(n, n+2);
	cout << s.longestCommonPrefix(v) << endl;
	return 0;
}