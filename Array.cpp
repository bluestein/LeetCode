#include "stdafx.h"
#include "Array.h"


Array::Array()
{
}


Array::~Array()
{
}

// Given an array nums, write a function to move all 0's to the end of it
// while maintaining the relative order of the non-zero elements.
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].
//Note:
//You must do this in - place without making a copy of the array.
//Minimize the total number of operations.
void Array::moveZeroes(vector<int>& nums) {
	for(int i =0,j = 0; i < nums.size(); i++) {
		if (nums[j])
			j++;
		else if (nums[i] != 0) {
			nums[j++] = nums[i];
			nums[i] = 0;
		}
	}
}

//Given an array and a value, remove all instances of that value in place and return the new length.
//The order of elements can be changed.It doesn't matter what you leave beyond the new length(超出新长度的元素可以任意).
int Array::removeElement(arr& nums, int val) {
	int i, j;
	for (i = j = nums.size() - 1; i >= 0; i--) {
		if (nums[i] == val && i != j--)
			nums[i] = nums[j + 1];
	}
	return j + 1;
}