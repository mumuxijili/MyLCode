#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		if(s.size() == 0) return true;
		if(s.size() % 2 == 1) return false;
		vector<char> parentheses;
		for(auto c : s)
		{
			if(c == '(' || c == '[' || c == '{')
			{
				parentheses.push_back(c);
			}
			else
			{
				if(parentheses.size() == 0) return false;
				char tmp = parentheses.back();
				parentheses.pop_back();
				if(c == ')')
				{
					if(tmp != '(') return false;
				}
				else if(c == ']')
				{
					if(tmp != '[') return false;
				}
				else if(c == '}')
				{
					if(tmp != '{') return false;
				}
			}
		}
		return parentheses.size() == 0 ? true : false;
	}
};

int main()
{
	Solution s;
	cout << s.isValid("{[}]");
	return 0;
}