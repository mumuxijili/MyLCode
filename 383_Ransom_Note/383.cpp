#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	bool canConstruct(string ransomNote, string magazine)
	{
		for (int i = 0; i < ransomNote.size(); i++)
		{
			string::size_type found = magazine.find(ransomNote[i]);
			if (found == string::npos) return false;
			else
				magazine.erase(magazine.begin() + found);
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.canConstruct("hello", "helloworld") << endl;
	return 0;
}