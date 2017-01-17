#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		if(needle.size() > haystack.size()) return -1;
	    if(needle.size() == haystack.size()) return haystack == needle ? 0 : -1;
	    if(needle.empty() && !haystack.empty()) return 0;
		vector<int> next;
		next = getNext(needle);
		int i = 0;
		int j = 0;
		int n = haystack.size();
		int m = needle.size();
		while((i < n) && (j < m))
		{
			if(j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next[j];
			}
		}
		if(j == needle.size())
			return i - j;
		else
			return -1;
	}
private:
	vector<int> getNext(string needle)
	{
		vector<int> next(needle.size(), 0);
		next[0] = -1;
		int k = -1;
		int j = 0;
		while(j < needle.size() - 1)
		{
			if(k == -1 || needle[k] == needle[j])
			{
				k++;
				j++;
				next[j] = k;
			}
			else
			{
				k = next[k];
			}
		}
		for(vector<int>::iterator it = next.begin(); it != next.end(); it++)
			cout << *it << " ";
		cout << endl;
		return next;
	}
};

int main()
{
	Solution s;
	cout << "result:" << s.strStr("mississippi", "issi") << endl;
	return 0;
}