#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		wordList.push_back(endWord);
		queue<string> toVisit;
		addWord(beginWord, wordList, toVisit);
		int dist = 2;
		while(!toVisit.empty())
		{
			int num = toVisit.size();
			for(int i = 0; i < num; i++)
			{
				string word = toVisit.front();
				toVisit.pop();
				if(word == endWord) return dist;
				addWord(word, wordList, toVisit);
			}
			dist++;
		}
		return dist;
	}

	void addWord(string word, vector<string>& wordList, queue<string>& toVisit)
	{
		vector<string>::iterator it0 = find(wordList.begin(), wordList.end(), word);
		if(it0 != wordList.end())
			wordList.erase(it0);
		for(vector<string>::iterator it = wordList.begin(); it != wordList.end(); )
		{
			if(difference(word, *it) == 1)
			{
				toVisit.push(*it);
				it = wordList.erase(it);
			}
			it++;
		}
	}

	int difference(string a, string b)
	{
		int num = a.size();
		int diff = 0;
		for(int i = 0; i < num; i++)
		{
			if(a[i] != b[i]) diff++;
		}
		return diff;
	}
};

int main()
{
	Solution s;
	string a[6] = {"hot","dot","dog","lot","log","cog"};
	vector<string> str(a, a + 6);
	cout << s.ladderLength("hit", "cog", str);
	return 0;
}
