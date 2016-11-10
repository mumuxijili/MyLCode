#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // void moveZeroes(vector<int>& nums) {
    //     int j = 0;
    //     // move all the nonzero elements advance
    //     for (int i = 0; i < nums.size(); i++) {
    //         if (nums[i] != 0) {
    //             nums[j++] = nums[i];
    //         }
    //     }
    //     for (;j < nums.size(); j++) {
    //         nums[j] = 0;
    //     }
    // }
	void moveZeroes(vector<int>& nums)
	{
		// the first position of end zeros
		int zero = nums.size();
		// // number of continuous nonzero integer
		// int nonzero = 0;
		for (int i = nums.size() - 1; i >=0; i--)
		{
			if (nums[i] == 0)
			{
				for(int j = i + 1; j < zero; j++)
				{
					int tmp = nums[j-1];
					nums[j-1] = nums[j];
					nums[j] = tmp;
				}
				zero--;
			}
		}
	}
};

int main()
{
	Solution s;
	int n[10] = {4,2,4,0,0,3,0,5,1,0};
	vector<int> v(n, n+10);
	s.moveZeroes(v);
	for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << endl;
	return 0;
}