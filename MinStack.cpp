#include "stdafx.h"
#include "MinStack.h"

void MinStack::push(int x) 
{
	vec.push_back(x);
	if (mins.empty())
	{
		mins.push_back(x);
	}
	else if (x <= mins.back())
	{
		mins.push_back(x);
	}
}

void MinStack::pop() 
{
	if (vec.empty())
	{
		return;
	}
	if (vec.back() == mins.back())
	{
		mins.pop_back();
	}
	vec.pop_back();
}

int MinStack::top() 
{
	if (!vec.empty())
	{
		return vec.back();
	}
	return NULL;
}

int MinStack::getMin() 
{
	if (mins.empty())
	{
		return NULL;
	}
	return mins.back();
}
