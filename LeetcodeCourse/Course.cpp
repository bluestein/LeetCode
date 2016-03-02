#include "stdafx.h"
#include "Course.h"

// 给定一个有序数组，返回unique的个数len，并且前len个数为那些unique数。要求：使用O(1)空间。
// 如 [2,2,5,6,6], 返回 3, 前3个为 [2,5,6]
// 算法：两个指针，一前一后
int Course::removeDuplicates(int *nums, int len) //传递数组第一个元素及长度(数组只能这么传递，除非是用引用)
{
	int i = 0, j = 0;
	for (; j < len; j++) {
		if (nums[j] != nums[i]) {
			nums[i + 1] = nums[j];
			i++;
		}
	}
	return i + 1;
}

// 判定是否为相同字母异序词，如"god", "dog"
// 算法：hash table O(n) time, O(1) space
// 统计单词中字母出现的次数，并且一个单词中最多只有 26 个不同字母。
// 统计第一个时+1，第二个时-1
bool Course::isAnagram(string s, string t) {
	if (s.length() != t.length()) return false;
	int cnt[26] = { 0 }, i = 0;
	for (; i < s.length(); i++) {
		cnt[s[i] - 'a']++;
		cnt[t[i] - 'a']--;
	}
	i = 0;
	for (; i < 26; i++) {
		if (cnt[i] != 0) return false;
	}
	return true;
}

// 反转一个链表
// 算法：1->2->3->null, null<-1<-2<-3
ListNode* Course::reverseList(ListNode *head) {
	// 循环
	ListNode *prev = NULL;
	ListNode *cur = head;
	while (cur != NULL)
	{
		ListNode *tmp = cur->next;
		cur->next = prev;
		prev = cur;
		cur = tmp;
	}
	return prev;

	// 递归
	//if (head == NULL || head->next == NULL) return head;
	//ListNode *p = reverseList(head->next); // 先递归后一节点
	// //再处理前一节点
	//head->next->next = head;
	//head->next = NULL;
	//return p;
}

// 判断数字是否为ugly。即它的所有质数因子只能包括2，3，5。例如，6和8.而14不是，它含7.1算ugly。
// 算法:辗转相除？
bool Course::isUgly(int num)
{
	if(num <= 0) return false;
	int dividers[] = { 2, 3, 5 };
	for each (int d in dividers)
	{
		while (num % d == 0)
		{
			num /= d;
		}
	}
	return (num == 1);
}

// 给定一个数，把所有位的数相加，直到变成一个数。如，29：2 + 9 = 11，1 + 1 = 2.
int Course::addDigits(int num) {
	if (0 == num) return 0;
	if (0 == num % 9) return 9;
	return num % 9;
	//公式
	//return num - 9 * ((num-1) / 9);
}

// 在一串数字中找出两个数，使得它们之和等于某个目标数，返回这两数的下标。可以假设仅有一个解。
// 如， [2, 7, 12] target = 9. 返回 [0, 1]
// 算法：1. hash table. 
vector<int> Course::twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> hash;
	vector<int> res(2, 0);
	for (int i = 0; i < nums.size(); i++) {
		if (hash.find(target - nums[i]) != hash.end()) {
			res[0] = hash[target - nums[i]], res[1] = i;
			return res;
		}
		hash[nums[i]] = i;
	}
}

// 假设 x = 5
bool isBadVersion(int n) {
	if (n >= 5) return true;
	return false;
}
// 有一组数，前x个为good，其余为bad，找出这个x。
// 算法：1. 二分查找；2. 穷尽
int Course::firstBadVersion(int n) {
	int i = 1, j = n;
	while (i < j)
	{
		// int mid = (i + j) / 2; // i + j 可能会溢出
		int mid = i + (j - i) / 2;
		if (isBadVersion(mid)) j = mid;
		else i = mid + 1;
	}
	return i;
	// 穷尽
	/*for (int i = 1; i < n; i++) {
		if (isBadVersion(i)) return i;
	}
	return n;*/
}

// “区间和”：给定一个数组，求下标区间为 [i, j](i <= j) 内元素之和。
// 假设：1. 数组不变；2. 同时有很多调用sumRange。
// 算法：
// 1. 查询O(n)time: 使用循环相加；
// 2. 查询O(1)time, O(n^2)space: 提前算好所有“区间和”，然后存放在 hash 表中。(java)
// 3. 查询O(1)time, O(n)space: 提前算好所有“前x和”，然后存放在一个与原表大小相同的表中。
int Course::sumRange(vector<int> &nums, int i, int j){
	if (nums.size() == 0 || i > j) return 0;
	
	// 循环查询
	/*int sum = 0;
	for (int k = i; k <= j; k++) {
		sum += nums[k];
	}
	return sum;*/

	// 先算好所有“前x和”，即把x前面所有的数加起来存放在x处。如 nums[1, 2, 3] => sums[1, 3, 6]
	// 则给定一个范围[i, j], result = i == 0 ? sums[j] : sums[j] - sums[i - 1].
	vector<int> sums(nums); // nums不变，所以使用sums
	for (int k = 1; k < nums.size(); k++) {
		sums[k] += sums[k - 1];
	}
	// 查询
	return i == 0 ? sums[j] : sums[j] - sums[i - 1];
}

// 给定一个矩阵，计算矩形(row1, col1), (row2, col2) 内的和。
// 假设：矩阵不可变；同时有多个操作调用sumRange2D；row1 <= row2 and col1 <= col2.
// 算法：
// 1. 利用 sumRange 思想;
// 2. 穷举
// 3. 计算从O点开始的矩形和，如图sum_oa.jpg。
int Course::sumRange2D(vector< vector<int> > &matrix, int row1, int col1, int row2, int col2) {
	int sum = 0;
	typedef vector< vector<int> > vector2D;

	// 1. sumRange思想
	// 计算行和
	/*vector2D sums(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			sums[i][j] += sums[i][j - 1];
		}
	}
	// 查询O(m)，按行相加
	for (int i = row1; i <= row2; i++) {
		sum += (col1 == 0) ? sums[i][col2] : (sums[i][col2] - sums[i][col1 - 1]);
	}*/

	// 2. 穷举查询
	/*for (int i = row1; i <= row2; i++) {
		for (int j = col1; j <= col2; j++)
			sum += matrix[i][j];
	}*/

	// 3. Origin O(0, 0). Sum(ABCD) = Sum(OD) - Sum(OB) - Sum(OB) + Sum(OA)
	// 计算所有这样的原点开始的矩形和 O(mn) space
	vector2D sums = vector2D(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			sums[i + 1][j + 1] = matrix[i][j] + sums[i][j + 1] + sums[i + 1][j] - sums[i][j];
		}
	}
	// 查询O(1)time
	sum = sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];

	return sum;
}