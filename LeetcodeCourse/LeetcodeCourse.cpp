// LeetcodeCourse.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Course.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	Course course;

	cout << "Remove Duplicates" << endl;
	int nums[] = {1,1,1,2,2,5,5,5,6};
	int len = sizeof(nums) / sizeof(nums[0]);
	cout << course.removeDuplicates(nums, len) << endl;

	cout << "Anagram" << endl;
	string s("nl"), t("cx");
	cout << course.isAnagram(s, t) << endl;

	cout << "Reverse List" << endl;
	ListNode *head = new ListNode(1);
	ListNode *cur = head;
	for (int i = 2; i < 10; i++) {
		ListNode *tmp = new ListNode(i);
		cur->next = tmp;
		cur = cur->next;
	}
	cur->next = NULL;
	ListNode *res = course.reverseList(head);
	while (res != NULL)
	{
		cout << res->val << endl;
		res = res->next;
	}
	
	cout << "Is ugly" << endl;
	int ints[] = { 12, 13, 25, 346, 214, 98 };
	for each (int i in ints)
	{
		cout << course.isUgly(i) << endl;
	}

	cout << "Add digits" << endl;
	for each (int i in ints)
	{
		cout << course.addDigits(i) << endl;
	}

	cout << "Two sum" << endl;
	vector<int> vec(4, 0);
	vec[0] = 3, vec[1] = 2, vec[2] = 4, vec[3] = 1;
	vector<int> index = course.twoSum(vec, 6);
	cout << index[0] << ", " << index[1] << endl;

	cout << "Binary search" << endl;
	cout << course.firstBadVersion(10) << endl;

	cout << "Sum range" << endl;
	cout << course.sumRange(vec, 0, 3) << endl;

	cout << "Sum range 2D" << endl;
	vector< vector<int> > matrix;
	int cnt = 0;
	while (cnt < 4)
	{
		matrix.push_back(vec);
		cnt++;
	}
	cout << course.sumRange2D(matrix, 2, 1, 3, 2) << endl;
    return 0;
}

