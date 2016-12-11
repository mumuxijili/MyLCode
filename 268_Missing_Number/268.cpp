#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int missingNumber(vector<int>& nums)
	{
		int result = 0;
		int i = 0;
		for(i = 0; i < nums.size(); i++)
		{
			result ^= nums[i];
			result ^= i;
		}
		result ^= i;
		return result;
	}
};

int main()
{
	Solution s;
	int n[3] = {0, 1, 3};
	vector<int> v(n, n+3);
	cout << s.missingNumber(v) << endl;
	return 0;
}