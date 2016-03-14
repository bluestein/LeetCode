#include "stdafx.h"
#include "DynamicProgramming.h"

/*
You are a professional robber planning to rob houses along a street.Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non - negative integers representing the amount of money of each house,
determine the maximum amount of money you can rob tonight without alerting the police.
*/
// rob[0] = 0
// rob[1] = nums[0]
// rob[i] = max(rob[i - 1], rob[i - 2] + num[i - 1])
int DynamicProgramming::rob(vector<int>& nums)
{
	int sum_even = 0, sum_odd = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (i % 2) sum_odd = max(sum_odd + nums[i], sum_even);
		else sum_even = max(sum_even + nums[i], sum_odd);
	}
	return max(sum_odd, sum_even);
}
