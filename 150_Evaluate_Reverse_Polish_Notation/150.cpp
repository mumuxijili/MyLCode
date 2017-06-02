#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int evalRPN(vector<string>& tokens)
	{
		vector<int> nums;
		for(int i = 0; i < tokens.size(); i++)
		{
			if(isdigit(tokens[i][0]))
			{
				int d = stoi(tokens[i]);
				nums.push_back(d);
			}
			else if(tokens[i][0] == '-')
			{
				if(isdigit(tokens[i][1]))
				{
					int d = -1 * (stoi(tokens[i].substr(1, tokens[i].size())));
					nums.push_back(d);
				}
				else
				{
					int b = nums.back();
					nums.pop_back();
					int a = nums.back();
					nums.pop_back();
					int c = a - b;
					nums.push_back(c);
				}
			}
			else if(tokens[i][0] == '+')
			{
				int b = nums.back();
				nums.pop_back();
				int a = nums.back();
				nums.pop_back();
				int c = a + b;
				nums.push_back(c);
			}
			else if(tokens[i][0] == '*')
			{
				int b = nums.back();
				nums.pop_back();
				int a = nums.back();
				nums.pop_back();
				int c = a * b;
				nums.push_back(c);
			}
			else if(tokens[i][0] == '/')
			{
				int b = nums.back();
				nums.pop_back();
				int a = nums.back();
				nums.pop_back();
				int c = a / b;
				nums.push_back(c);
			}
			else
			{
				cout << "wrong" << endl;
			}
		}
		return nums[0];
	}
};
