#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string simplifyPath(string path)
	{
		int len = path.size();
		vector<string> dir;
		vector<string> result;
		string res = "";
		string tmp = "";
		if(len <= 1) return path;
		for(int i = 0; i < len; i++)
		{
			while(path[i] == '/')
			{
				if(tmp != "")
					dir.push_back(tmp);
				tmp = "";
				i++;
			}
			if(i == len) break;
			tmp += path[i];
		}
		if(tmp.compare("") != 0) dir.push_back(tmp);
		for(int i = 0; i < dir.size(); i++)
		{
			if(dir[i].compare(".") == 0)
				continue;
			if(dir[i].compare("..") != 0)
				result.push_back(dir[i]);
			else
				if(!result.empty())
					result.pop_back();
			cout << dir[i] << endl;
		}
		for(int i = 0; i < result.size(); i++)
		{
			res += "/";
			res += result[i];
			// cout << result[i] << endl;
		}
		if(res.size() == 0) return "/";
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.simplifyPath("/.../");
	return 0;
}