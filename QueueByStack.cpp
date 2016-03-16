#include "stdafx.h"
#include "QueueByStack.h"

// Push element x to the back of queue.
void QueueByStack::push(int x) 
{
	int sz_out = stack_out.size();
	for (int i = 0; i < sz_out; ++i) 
	{
		stack_in.push(stack_out.top());
		stack_out.pop();
	}
	stack_in.push(x);
	int sz_in = stack_in.size();
	for (int i = 0; i < sz_in; ++i) 
	{
		stack_out.push(stack_in.top());
		stack_in.pop();
	}
}

// Removes the element from in front of queue.
void QueueByStack::pop(void) 
{
	stack_out.pop();
}

// Get the front element.
int QueueByStack::peek(void) 
{
	return stack_out.top();
}

// Return whether the queue is empty.
bool QueueByStack::empty(void) 
{
	return stack_out.empty();
}

/*************solution2*************/

// Push element x to the back of queue.
void QueueByStack::pushX(int x) 
{
	in.push(x);
}

// Removes the element from in front of queue.
void QueueByStack::popX(void) 
{
	peekX();
	out.pop();
}

// Get the front element.
int QueueByStack::peekX(void) 
{
	if (!out.empty()) return out.top();
	while (!in.empty())
	{
		out.push(in.top());
		in.pop();
	}
	return out.top();
}

// Return whether the queue is empty.
bool QueueByStack::emptyX(void) 
{
	return out.empty() && in.empty();
}
