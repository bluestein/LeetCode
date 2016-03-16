#pragma once
#include <vector>
using namespace std;

// Definition for an interval.
class Interval {
	int start;
	int end;
	Interval() { start = 0; end = 0; }
	Interval(int s, int e) { start = s; end = e; }
};

class Array
{
public:
	typedef vector<int> arr;
	//bool canAttendMeetings(vector<Interval>& intervals); // #252
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid); // #63
	int uniquePaths(int m, int n); // #62
	int shortestDistance(vector<string>& words, string word1, string word2); // #243
	bool containsNearbyDuplicate_s2(vector<int>& nums, int k); // #219 solution 2
	bool containsNearbyDuplicate_s1(vector<int>& nums, int k); // #219 solution 1
	int majorityElement(vector<int>& nums); // #169
	vector<int> getPascalsRow(int rowIndex); // #119
	vector<vector<int>> generatePascals(int numRows); // #118
	void rotate_r(vector<int>& nums, int k); // #189 recursive
	void rotate_i3(vector<int>& nums, int k); // #189 iterative 3
	void rotate_i2(vector<int>& nums, int k); // #189 iterative 2
	void rotate_i1(vector<int>& nums, int k); // #189 iterative 1
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

