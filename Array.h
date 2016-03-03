#pragma once
#include <vector>
using namespace std;

class Array
{
public:
	typedef vector<int> arr;
	Array();
	~Array();
	void moveZeroes(vector<int>& nums); // #283
	int removeElement(arr& nums, int val); // #27

	void printVector(arr nums) {
		arr::const_iterator cur = nums.begin();
		while (cur != nums.end())
		{
			printf("%d ", *cur++);
		}
		printf("\n");
	}
	arr genVector(int n) {
		arr vec;
		int i = 1;
		while (i <= n)
		{
			vec.push_back(i++%2);
		}
		return vec;
	}
};

