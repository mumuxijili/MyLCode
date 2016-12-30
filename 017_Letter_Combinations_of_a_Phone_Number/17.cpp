#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<string> letterCombinations(string digits)
	{
		if(digits.empty()) return vector<string>();
		vector<vector<char>> table = {	{' '},
										{' '},
										{'a', 'b', 'c'},
										{'d', 'e', 'f'},
										{'g', 'h', 'i'},
										{'j', 'k', 'l'},
										{'m', 'n', 'o'},
										{'p', 'q', 'r', 's'},
										{'t', 'u', 'v'},
										{'w', 'x', 'y', 'z'} };
		// int slen = digits.size();
		// int n = 1;
		// for(int i = 0; i < slen; i++)
		// 	n *= table[digits[i]-'0'].size();
		
		vector<string> result(1, "");
		// for(int i = 0; i < slen; i++)
		// {
		// 	int dlen = table[digits[i]-'0'].size();
		// 	for(int j = 0; j < dlen; j++)
		// 	{

		// 	}
		// }
		for(auto d : digits)
		{
			int rlen = result.size();
			int dlen = table[d-'0'].size();

			result.resize(rlen * dlen);
			for(int i = 0; i < dlen; i++)
			{
				copy(result.begin(), result.begin()+rlen, result.begin()+rlen*i);
			}
			for(int i = 0; i < dlen; i++)
			{
				for(int j = 0; j < rlen; j++)
				{
					result[j+rlen*i] += table[d-'0'][i];
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	// cout << s.letterCombinations("29") << endl;
	return 0;
}