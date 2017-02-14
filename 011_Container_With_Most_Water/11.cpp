#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int> &height)
	{
		int start;
		int end;
		start = 0;
		end = height.size() - 1;
		int maxwater = 0;
		while(start < end)
		{
			int area = min(height[start], height[end]) * (end - start);
			maxwater = max(maxwater, area);
			if(height[start] <= height[end])
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		return maxwater;
	}
}