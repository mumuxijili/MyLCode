#include <iostream>

using namespace std;

/*
首先，我们通过对x和y进行&位运算，得出每一位上的进位。
然后对x和y进行^位运算，得出没有加进位的和。
最后将所得的和当做新的x，所得的进位往左移一位(第零位的进位输入为0)当做新的y，
继续做上面的步骤，直到进位为0，此时x中保存的就是我们要求的x和y的和了。
 */

class Solution {
public:
	int getSum(int a, int b) {
		int sum = a;
		int carry = b;
		while(carry)
		{
			int tmp = sum;
			sum = tmp ^ carry;
			carry = (tmp & carry) << 1;
		}
		return sum;
	}
};

int main()
{
	Solution s;
	int c = s.getSum(10, 20);
	cout << c << endl;
	return 0;
}