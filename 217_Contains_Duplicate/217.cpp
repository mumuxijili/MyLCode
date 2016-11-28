#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
	bool containsDuplicate(vector<int>& nums)
	{
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			++m[nums[i]];
			if(m[nums[i]] > 1) return true;
		}
		return false;
	}
};

int main()
{
	Solution s;
	int n[2] = {3, 3};
	vector<int> v(n, n+2);
	cout << s.containsDuplicate(v) << endl;
	return 0;
}
