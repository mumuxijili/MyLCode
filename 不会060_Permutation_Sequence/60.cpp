#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string getPermutation(int n, int k)
	{
		if(n == 0) return "0";
		int total = 1;
		vector<int> num;
		string result = "";
		for(int i = 1; i <= n; i++)
		{
			total *= i;
			num.push_back(i);
		}
		for(int i = n; i > 0; i--)
		{
			int a = k / (total / i);
			// if(total == 1)
			// 	a = 0;
			total = total / i;
			cout << a << endl;
			k = k % i;
			result += (num[a] + '0');
			num.erase(num.begin() + a);
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.getPermutation(3, 2) << endl;
	return 0;
}