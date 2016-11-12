#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		set<int> s1;
		set<int> res;
		for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
		{
			s1.insert(*it);
		}
		for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++)
		{
			if (s1.find(*it) != s1.end())
			{
				res.insert(*(it));
			}
		}
		vector<int> r(res.begin(), res.end());
		return r;
	}
};

int main()
{
	Solution s;
	int n1[11] = {1,1,2,2,3,3,4,4,5,5,6};
	vector<int> a(n1, n1+11);
	int n2[5] = {2, 4, 6, 8, 1};
	vector<int> b(n2, n2+5);
	vector<int> v = s.intersection(a, b);
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
		cout << *it << endl;
	return 0;
}