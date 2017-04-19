#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}	
};

class Solution
{
public:
	vector<Interval> merge(vector<Interval>& intervals)
	{
		if(intervals.empty()) return vector<Interval> {};
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
		result.push_back(intervals[0]);
		for(int i = 1; i < intervals.size(); i++)
		{
			if(result.back().end < intervals[i].start) result.push_back(intervals[i]);
			else
				result.back().end = max(result.back().end, intervals[i].end);
		}
		return result;
	}
};
