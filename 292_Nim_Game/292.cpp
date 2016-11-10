#include <iostream>

using namespace std;

class Solution {
public:
	bool canWinNim(int n) {
		// int take;
		// bool result;
		// if(n <= 3) result = true;
		// else {
		// 	result = false;
		// 	for(take = 1; take <=3; take++){
		// 		result = (result | !canWinNim(n-take));
		// 	}
		// }
		// return result;
		 
		return (n & 3);
	}
};

int main()
{
	Solution s;
	cout << s.canWinNim(33) << endl;
	return 0;
}