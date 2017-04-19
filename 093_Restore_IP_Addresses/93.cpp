#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
	void findIp(string s, int start, int step, vector<string>& result, string ip)
	{
	    if(step > 4) return;
		if(s.size() - start > (4 - step) * 3) return;
		if(s.size() - start < (4 - step)) return;
		if(step == 4 && start == s.size())
		{
			ip.erase(ip.end() - 1);
			result.push_back(ip);
			return;
		}
		int num = 0;
		for(int i = start; i < start + 3; i++)
		{
			num = num * 10 + (s[i] - '0');
			if(num <= 255)
			{
				ip += s[i];
				findIp(s, i + 1, step + 1, result, ip + '.');
			}
			if(num == 0) break;
		}

	}
public:
	vector<string> restoreIpAddresses(string s)
	{
		if(s.size() < 4) return vector<string>();
		vector<string> result;
		string ip;
		findIp(s, 0, 0, result, ip);
		return result;
	}
};
