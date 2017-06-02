#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minele = INT_MAX;
    }
    
    void push(int x) {
        stack.push_back(x);
        if(x < minele)
        	minele = x;
    }
    
    void pop() {
    	if(stack.back() == minele)
    	{
    		stack.pop_back();
    		int tmpmin = INT_MAX;
    		for(vector<int>::iterator it = stack.begin(); it != stack.end(); it++)
    			if(*it < tmpmin)
    				tmpmin = *it;
    		minele = tmpmin;
    	}
    	else
    	{
    		stack.pop_back();
    	}
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
    	if(stack.size() > 0)
        	return minele;
        else
        	return INT_MAX;
    }
private:
	vector<int> stack;
	int minele;
};
