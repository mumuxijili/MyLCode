#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{
		vector<int> count(128, 0), tmp(128, 0);
		int ns = s.size();
		int np = p.size();
		vector<int> result;
		for(int i = 0; i < np; i++)
		{
			count[p[i]]++;
			tmp[s[i]]++;
		}
		if(tmp == count) result.push_back(0);
		for(int j = np; j < ns; j++)
		{
			tmp[s[j]]++;
			tmp[s[j - np]]--;
			if(tmp == count) result.push_back(j - np + 1);
		}
		return result;
	}
};
