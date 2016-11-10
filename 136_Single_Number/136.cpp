#include <iostream>
#include <vector>

using namespace std;
/**
 * I will try to explain it here:
 * the principle of excusive or operation is: if two bits are same, then result is 0, if two bits are not same(0,1 or 1,0) the result is 1. when you have two same numbers, say 9 and 9, the bitwise exclusive or operation: 1001^1001 is 0000.
 * however, if you introduce another number say 3. we have 9,3,9. which in binary is 1001, 0011, 1001. if we do bitwise exclusive or operation starting from first number, we have:
 * step 1: 1001^0011 = 1010
 * step 2: 1010^1001 = 0011
 * which the result is 3.
 * the trick of using exclusive or here is that, when you encounter two same number, no matter how far they are apart from each other, excusive or will let them “counteract” each other.
 * Let me know if you still dont understand.
 * Chenxuan
 */
class Solution {
public:
	int singleNumber(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++)
        	nums[0] ^= nums[i];
        return nums[0];
    }
};

int main()
{
	Solution s;
	int n[11] = {1,1,2,2,3,3,4,4,5,5,6};
	vector<int> v(n, n+11);
	int a = s.singleNumber(v);
	cout << a << endl;
	return 0;
}