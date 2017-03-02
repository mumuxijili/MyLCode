#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		unordered_map<string, multiset<string>> groups;
		for(auto s : strs)
		{
			string tmp = s;
			sort(tmp.begin(), tmp.end());
			groups[tmp].insert(s);
		}
		vector<vector<string>> result;
		for(unordered_map<string, multiset<string>>::iterator it = groups.begin(); it != groups.end(); it++)
		{
		    vector<string> v(it->second.begin(), it->second.end());
			result.push_back(v);
		}
		return result;
	}
};
