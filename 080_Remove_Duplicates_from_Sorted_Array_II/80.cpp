#include <iostream>
#include <string>
#include <vector>

/*
int removeDuplicates(int A[], int n, int k) {

            if (n <= k) return n;

            int i = 1, j = 1;
            int cnt = 1;
            while (j < n) {
                if (A[j] != A[j-1]) {
                    cnt = 1;
                    A[i++] = A[j];
                }
                else {
                    if (cnt < k) {
                        A[i++] = A[j];
                        cnt++;
                    }
                }
                ++j;
            }
            return i;
}
 */

using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums)
	{
		if(nums.size() <= 2) return nums.size();
		int prepre = nums[0];
		int pre = nums[1];
		int count = 2;
		for(vector<int>::iterator it = nums.begin() + 2; it != nums.end(); )
		{
			if(pre == *it)
			{
				if(prepre == pre)
				{
					it = nums.erase(it);
					continue;
				}
				else
				{
					prepre = pre;
					pre = *it;
					it++;
					count++;
				}
			}
			else
			{
				prepre = pre;
				pre = *it;
				it++;
				count++;
			}
		}
		return count;
	}
};
