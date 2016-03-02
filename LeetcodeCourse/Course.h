#pragma once
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Course
{
public:
	Course() {}
	int removeDuplicates(int *nums, int len);
	bool isAnagram(string s, string t);
	ListNode* reverseList(ListNode *head);
	bool isUgly(int num);
	int addDigits(int num);
	vector<int> twoSum(vector<int> &nums, int target);
	int firstBadVersion(int n);
	int sumRange(vector<int> &nums, int i, int j);
	int sumRange2D(vector< vector<int> > &matrix, int row1, int col1, int row2, int col2);
};

