#pragma once
#include <climits>
#include <vector>
using namespace std;

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
class MinStack // #155
{
private:
	vector<int> mins, vec;
public:
	//Push element x onto stack.
	void push(int x);
	//Removes the element on top of the stack.
	void pop();
	//Get the top element.
	int top();
	//Retrieve the minimum element in the stack.
	int getMin();
};

