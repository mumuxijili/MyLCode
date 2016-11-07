#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
    	vector<string> res;
    	for (int i = 1; i <= n; i++)
    	{
    		string b = "";
    		/* code */
    		if(mulof3(i)){
    			b = b + "Fizz";
    		}
    		if(mulof5(i)){
    			b = b + "Buzz";
    		}
    		if(b == ""){
    			b = to_string(i);
    			// char *c = itoa(i);
    			// b = string(c);
    		}
    		res.push_back(b);
    	}
    	return res;
    }
private:
	bool mulof3(int a){
		if(a % 3 == 0)
			return true;
		else
			return false;
	}
	bool mulof5(int a){
		if(a % 5 == 0)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	std::vector<string> a = s.fizzBuzz(15);
	for (int i = 0; i < a.size(); i++) {
		cout << a.at(i) << endl;
	}
	return 0;
}