#pragma once
#include <stack>
using namespace std;

class QueueByStack // #232
{
private:
	stack<int> stack_in, stack_out;
	stack<int> in, out;
public:
	// Push element x to the back of queue.
	void push(int x);
	// Removes the element from in front of queue.
	void pop(void);
	// Get the front element.
	int peek(void);
	// Return whether the queue is empty.
	bool empty(void);

	/*************solution2*************/
	// X means Upgrade
	// Push element x to the back of queue.
	void pushX(int x);
	// Removes the element from in front of queue.
	void popX(void);
	// Get the front element.
	int peekX(void);
	// Return whether the queue is empty.
	bool emptyX(void);
};

