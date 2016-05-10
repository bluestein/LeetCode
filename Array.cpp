#include "stdafx.h"
#include "Array.h"
#include <unordered_map>
#include <algorithm>

// Given an array of meeting time intervals consisting of start and end times[[s1, e1], [s2, e2], ...](si < ei), 
// determine if a person could attend all meetings.
//	For example,
//	Given[[0, 30], [5, 10], [15, 20]],
//	return false.
/*static bool compare(Interval& interval1, Interval& interval2) {
	return interval1.start < interval2.start;
}
bool overlap(Interval& interval1, Interval& interval2) {
	return interval1.end > interval2.start;
}
bool Array::canAttendMeetings(vector<Interval>& intervals)
{
	sort(intervals.begin(), intervals.end(), compare); 
	int n = intervals.size();
	for (int i = 0; i < n - 1; i++)
		if (overlap(intervals[i], intervals[i + 1]))
			return false;
	return true;
}*/
// Follow up for "Unique Paths":
// Now consider if some obstacles are added to the grids.How many unique paths would there be ?
// An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//There is one obstacle in the middle of a 3x3 grid as illustrated below.
//[
//	[0, 0, 0],
//	[0, 1, 0],
//	[0, 0, 0]
//]
//The total number of unique paths is 2.
int Array::uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	if (!m || obstacleGrid[0][0]) return 0;
	int n = obstacleGrid[0].size();
	if  (obstacleGrid[m - 1][n - 1]) return 0;
	for (int i = 0; i < m; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			if (obstacleGrid[i][j]) obstacleGrid[i][j] = 0;
			else 
			{
				if (0 == i && 0 == j) obstacleGrid[i][j] = 1;
				else if (0 == i && j > 0) obstacleGrid[i][j] = obstacleGrid[i][j - 1];
				else if (i > 0 && 0 == j) obstacleGrid[i][j] = obstacleGrid[i - 1][j];
				else obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
			}
		}
	}
	return obstacleGrid[m - 1][n - 1];
}

// A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
// 1 1 1 1
// 1 2 3 4
// 1 3 6 10
// S: The state transition equation is: up[i][j] = up[i][j - 1] + up[i - 1][j]
int Array::uniquePaths(int m, int n)
{
	if (m <= 0 || n <= 0) return 0;
	vector< vector<int> > up(m, vector<int>(n, 1));
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
			up[i][j] = up[i][j - 1] + up[i - 1][j];
	}
	return up[m - 1][n - 1];

	// 到达终点需要 m+n-2步，向下m-1步，向右n-1步。故总共C(m-1)_(m+n-2)或C(n-1)_(m+n-2)种
	/*long result = 1;
	int min = m > n ? n - 1 : m - 1;
	for (int i = 0; i < min; i++) {
		result = result * (m + n - 2 - i) / (i + 1);
	}
	return (int)result;*/
}

// Given a list of words and two words word1 and word2, 
// return the shortest distance between these two words in the list.
// For example, Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
// Given word1 = “coding”, word2 = “practice”, return 3. Given word1 = "makes", word2 = "coding", return 1.
int Array::shortestDistance(vector<string>& words, string word1, string word2)
{
	int idx1(-1), idx2(-1), dist(INT_MAX);
	for (int i = 0; i < words.size(); ++i)
	{
		if (words[i] == word1) idx1 = i;
		if (words[i] == word2) idx2 = i;
		if (idx1 != -1 && idx2 != -1) dist = min(dist, abs(idx1 - idx2));
	}
	return dist;

	// another way
	/*int last(-1), dist(INT_MAX);
	for (int i = 0; i < words.size(); ++i) {
		if (words[i] == word1 || words[i] == word2) {
			if (last != -1 && words[i] != words[last]) dist = min(dist, i - last);
			last = i;
		}
	}
	return dist;*/
}

// Given an array of integers and an integer k, 
// find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j]
// and the difference between i and j is at most k.
// S2: hash
bool Array::containsNearbyDuplicate_s2(vector<int>& nums, int k)
{
	unordered_map<int, int> hash;
	int cur = 0;
	for (int num : nums)
	{
		if (hash.count(num) && hash[num] >= cur - k) return true;
		hash[num] = cur++;
	}
	return false;
}
// S1: Time consuming solution
bool Array::containsNearbyDuplicate_s1(vector<int>& nums, int k)
{
	k = k > nums.size() ? nums.size() : k;
	if (0 == k) return false;
	while (k > 0)
	{
		for (int i = 0; i < nums.size() - k; ++i)
		{
			if (nums[i] == nums[i + k])
				return true;
		}
		k--;
	}
	return false;
}

// Given an array of size n, find the majority element.
// The majority element is the element that appears more than [n/2] (下界) times
// Moore’s voting algorithm: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
int Array::majorityElement(vector<int>& nums) {
	int res = nums[0];
	int count = 1;
	for (int num : nums) 
	{
		res == num ? ++count : --count;
		if (count == 0) 
		{
			res = num;
			count = 1;
		}
	}
	return res;
}
// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return[1, 3, 3, 1].
// Could you optimize your algorithm to use only O(k) extra space?
vector<int> Array::getPascalsRow(int rowIndex)
{
	rowIndex = rowIndex >= 0 ? rowIndex : 0;
	vector<int> result(rowIndex + 1, 0);
	result[0] = 1;
	for (int i = 1; i <= rowIndex; i++)
	{
		for (int j = i; j >= 1; j--)
			result[j] = result[j] + result[j - 1];
	}
	return result;
}

// Given numRows, generate the first numRows of Pascal's triangle.
// For example, given numRows = 5,
// Return
// [
//	[1],
//	[1, 1],
//	[1, 2, 1],
//	[1, 3, 3, 1],
//	[1, 4, 6, 4, 1]
// ]
vector< vector<int> > Array::generatePascals(int numRows) 
{
	vector< vector<int> > pascals;
	if (numRows <= 0) return {};
	pascals.push_back({1});
	for (int i = 1; i < numRows; ++i)
	{
		vector<int> temp;
		temp.push_back(1); // the first 1
		for (int j = 1; j < i; ++j)
		{
			if (j < pascals[i - 1].size())
				temp.push_back(pascals[i - 1][j] + pascals[i - 1][j - 1]); // inner nums
		}
		temp.push_back(1); // the last 1
		pascals.push_back(temp);
	}
	return pascals;

	// another
	/*if (numRows < 0) return {};
	vector<vector<int>> result(numRows);
	for (int i = 0; i<numRows; i++) {
		result[i].resize(i + 1);
		result[i][0] = result[i][i] = 1;
		for (int j = 1; j<i; j++)
			result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
	}
	return result;*/
}

//Rotate an array of n elements to the right by k steps.
//For example, with n = 7 and k = 3, the array[1, 2, 3, 4, 5, 6, 7] is rotated to[5, 6, 7, 1, 2, 3, 4].
// S4: Swap the last k elements with the first k elements.
void Array::rotate_i3(vector<int>& nums, int k)
{
	int n = nums.size();
	if (!n || k % n == 0) return;
	int first = 0, middle = n - k % n, last = n;
	int next = middle;
	while (first != next) 
	{
		swap(nums[first++], nums[next++]);
		if (next == last) next = middle;
		else if (first == middle) middle = next;
	}
}
// S3: Start from one element and keep rotating until we have rotated n different elements.
void Array::rotate_i2(vector<int>& nums, int k) 
{
	int sz, n;
	sz = n = nums.size();
	if (sz == 0 || k <= 0) return;
	k %= n;
	if (n<2 || k<1) return;
	for (int i = k; n>0; ++i) 
	{
		int j = i, prev = nums[(i - k) % k];
		while (n-->0) 
		{
			swap(prev, nums[j]);
			j = (j + k) % sz;
			if (j == i) break;
		}
	}
}
// S2: Reverse the first n - k elements, the last k elements, and then all the n elements.
void reverse(vector<int>& nums, int l, int r) 
{
	while (l<r) 
	{
		int temp = nums[l];
		nums[l++] = nums[--r];
		nums[r] = temp;
	}
}
void Array::rotate_r(vector<int>& nums, int k)
{
	int n = nums.size();
	if (!n) return;
	k = k % n;
	reverse(nums, 0, n - k);
	reverse(nums, n - k, n);
	reverse(nums, 0, n);
}
// S1: Use a copy
void Array::rotate_i1(vector<int>& nums, int k)
{
	int len = nums.size();
	if (k <= 0) return;
	vector<int> copy(nums);
	for (int i = 0; i < len; ++i)
	{
		nums[(i + k) % len] = copy[i];
	}
}

// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice in the array, 
// and it should return false if every element is distinct.
// S1: hash table
// S2: sort
bool Array::containsDuplicate(vector<int>& nums) 
{
	// S1
	unordered_map<int, int> hash;
	int i = 0;
	while (i < nums.size())
	{
		if (hash.find(nums[i]) != hash.end())
			return true;
		hash[nums[i]] = i++;
	}
	return false;

	// S2
    /*if (!nums.size() || nums.size() == 1) return false;
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == nums[i + 1]) return true;
	}
	return false;*/
}


// Given an array nums, write a function to move all 0's to the end of it
// while maintaining the relative order of the non-zero elements.
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].
// Note:
// You must do this in - place without making a copy of the array.
// Minimize the total number of operations.
void Array::moveZeroes(vector<int>& nums) 
{
	for(int i =0,j = 0; i < nums.size(); i++) 
	{
		if (nums[j])
			j++;
		else if (nums[i] != 0) 
		{
			nums[j++] = nums[i];
			nums[i] = 0;
		}
	}
}

//Given an array and a value, remove all instances of that value in place and return the new length.
//The order of elements can be changed.It doesn't matter what you leave beyond the new length(超出新长度的元素可以任意).
int Array::removeElement(arr& nums, int val) 
{
	int i, j;
	for (i = j = nums.size() - 1; i >= 0; i--) 
	{
		if (nums[i] == val && i != j--)
			nums[i] = nums[j + 1];
	}
	return j + 1;
}

// There are two sorted arrays nums1 and nums2 of size m and n respectively. 
// Find the median of the two sorted arrays. 
// The overall run time complexity should be O(log (m+n)).
// The median: https://en.wikipedia.org/wiki/Median
double Array::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	const int m = nums1.size(), n = nums2.size();
	const int total = m + n;
	if (total & 1)
		return find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
	else
		return (find_kth(nums1.begin(), m, nums2.begin(), n, total / 2)
		+ find_kth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
}

int Array::find_kth(vector<int>::const_iterator a, int m, vector<int>::const_iterator b, int n, int k)
{
	if (m > n) return find_kth(b, n, a, m, k);
	if (m == 0) return *(b + k - 1);
	if (k == 1) return min(*a, *b);

	// divide k into two parts
	int ia = min(k / 2, m), ib = k - ia;
	if (*(a + ia - 1) < *(b + ib - 1))
		return find_kth(a + ia, m - ia, b, n, k - ia);
	else if (*(a + ia - 1) > *(b + ib - 1))
		return find_kth(a, m, b + ib, n - ib, k - ib);
	else
		return a[ia - 1];
}

// #16: Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
//      Return the sum of the three integers. You may assume that each input would have exactly one solution.
// Use three pointers: i, j, k
// like this:
//   a1, ..., an
//   |    |   |
//   i    k   j
int Array::threeSumClosest(vector<int>& nums, int target)
{
	int len = nums.size(), res = 0;
	if (len < 3) return res;
	sort(nums.begin(), nums.end());
	int gap = INT_MAX;
	for (int i = 0; i < len - 2; i++)
	{
		int k = i + 1, j = len - 1;
		while (k < j)
		{
			int sum = nums[i] + nums[j] + nums[k];
			int cur_gap = abs(sum - target);
			if (0 == cur_gap)
			{
				return sum;
			}
			else if (cur_gap < gap)
			{
				gap = cur_gap;
				res = sum;
			}
			if (sum > target) j--;
			else k++;
		}
	}
	return res;
}