#pragma once
#include <vector>
using namespace std;

class Array
{
public:
	typedef vector<int> arr;
	Array();
	~Array(); 
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid); // #63
	int uniquePaths(int m, int n); // #62
	int shortestDistance(vector<string>& words, string word1, string word2); // #243
	bool containsNearbyDuplicate2(vector<int>& nums, int k); // #219
	bool containsNearbyDuplicate1(vector<int>& nums, int k); // #219
	int majorityElement(vector<int>& nums); // #169
	vector<int> getPascalsRow(int rowIndex); // #119
	vector<vector<int>> generatePascals(int numRows); // #118
	void rotate4(vector<int>& nums, int k); // #189
	void rotate3(vector<int>& nums, int k); // #189
	void rotate2(vector<int>& nums, int k); // #189
	void rotate1(vector<int>& nums, int k); // #189
	bool containsDuplicate(vector<int>& nums); // #217
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

