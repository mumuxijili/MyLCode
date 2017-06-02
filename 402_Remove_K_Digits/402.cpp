#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		string res = "";
		int n = num.size();
		int keep = n - k;
		for(auto c : num)
		{
			while(k > 0 && res.size() > 0 && res.back() > c)
			{
				res.pop_back();
				k--;
			}
			res.push_back(c);
		}
		res.resize(keep);
		int i = 0;
		while(i < res.size() && res[i] == '0') i++;
		res.erase(0, i);
		return res == "" ? "0" : res;
	}
};
