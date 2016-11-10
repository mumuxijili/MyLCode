#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
    	string t = "";
    	int strlen = s.length();
    	for(int i = 0; i < strlen; i++){
    		t.push_back(s.at(strlen - i - 1));
    	}
        return t;
    }
};

int main()
{
	Solution s;
	string t = s.reverseString("hello");
	cout << t << endl;
	return 0;
}