#include "stdafx.h"
#include "Course.h"

// ����һ���������飬����unique�ĸ���len������ǰlen����Ϊ��Щunique����Ҫ��ʹ��O(1)�ռ䡣
// �� [2,2,5,6,6], ���� 3, ǰ3��Ϊ [2,5,6]
// �㷨������ָ�룬һǰһ��
int Course::removeDuplicates(int *nums, int len) //���������һ��Ԫ�ؼ�����(����ֻ����ô���ݣ�������������)
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

// �ж��Ƿ�Ϊ��ͬ��ĸ����ʣ���"god", "dog"
// �㷨��hash table O(n) time, O(1) space
// ͳ�Ƶ�������ĸ���ֵĴ���������һ�����������ֻ�� 26 ����ͬ��ĸ��
// ͳ�Ƶ�һ��ʱ+1���ڶ���ʱ-1
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

// ��תһ������
// �㷨��1->2->3->null, null<-1<-2<-3
ListNode* Course::reverseList(ListNode *head) {
	// ѭ��
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

	// �ݹ�
	//if (head == NULL || head->next == NULL) return head;
	//ListNode *p = reverseList(head->next); // �ȵݹ��һ�ڵ�
	// //�ٴ���ǰһ�ڵ�
	//head->next->next = head;
	//head->next = NULL;
	//return p;
}

// �ж������Ƿ�Ϊugly��������������������ֻ�ܰ���2��3��5�����磬6��8.��14���ǣ�����7.1��ugly��
// �㷨:շת�����
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

// ����һ������������λ������ӣ�ֱ�����һ�������磬29��2 + 9 = 11��1 + 1 = 2.
int Course::addDigits(int num) {
	if (0 == num) return 0;
	if (0 == num % 9) return 9;
	return num % 9;
	//��ʽ
	//return num - 9 * ((num-1) / 9);
}

// ��һ���������ҳ���������ʹ������֮�͵���ĳ��Ŀ�������������������±ꡣ���Լ������һ���⡣
// �磬 [2, 7, 12] target = 9. ���� [0, 1]
// �㷨��1. hash table. 
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

// ���� x = 5
bool isBadVersion(int n) {
	if (n >= 5) return true;
	return false;
}
// ��һ������ǰx��Ϊgood������Ϊbad���ҳ����x��
// �㷨��1. ���ֲ��ң�2. �
int Course::firstBadVersion(int n) {
	int i = 1, j = n;
	while (i < j)
	{
		// int mid = (i + j) / 2; // i + j ���ܻ����
		int mid = i + (j - i) / 2;
		if (isBadVersion(mid)) j = mid;
		else i = mid + 1;
	}
	return i;
	// �
	/*for (int i = 1; i < n; i++) {
		if (isBadVersion(i)) return i;
	}
	return n;*/
}

// ������͡�������һ�����飬���±�����Ϊ [i, j](i <= j) ��Ԫ��֮�͡�
// ���裺1. ���鲻�䣻2. ͬʱ�кܶ����sumRange��
// �㷨��
// 1. ��ѯO(n)time: ʹ��ѭ����ӣ�
// 2. ��ѯO(1)time, O(n^2)space: ��ǰ������С�����͡���Ȼ������ hash ���С�(java)
// 3. ��ѯO(1)time, O(n)space: ��ǰ������С�ǰx�͡���Ȼ������һ����ԭ���С��ͬ�ı��С�
int Course::sumRange(vector<int> &nums, int i, int j){
	if (nums.size() == 0 || i > j) return 0;
	
	// ѭ����ѯ
	/*int sum = 0;
	for (int k = i; k <= j; k++) {
		sum += nums[k];
	}
	return sum;*/

	// ��������С�ǰx�͡�������xǰ�����е��������������x������ nums[1, 2, 3] => sums[1, 3, 6]
	// �����һ����Χ[i, j], result = i == 0 ? sums[j] : sums[j] - sums[i - 1].
	vector<int> sums(nums); // nums���䣬����ʹ��sums
	for (int k = 1; k < nums.size(); k++) {
		sums[k] += sums[k - 1];
	}
	// ��ѯ
	return i == 0 ? sums[j] : sums[j] - sums[i - 1];
}

// ����һ�����󣬼������(row1, col1), (row2, col2) �ڵĺ͡�
// ���裺���󲻿ɱ䣻ͬʱ�ж����������sumRange2D��row1 <= row2 and col1 <= col2.
// �㷨��
// 1. ���� sumRange ˼��;
// 2. ���
// 3. �����O�㿪ʼ�ľ��κͣ���ͼsum_oa.jpg��
int Course::sumRange2D(vector< vector<int> > &matrix, int row1, int col1, int row2, int col2) {
	int sum = 0;
	typedef vector< vector<int> > vector2D;

	// 1. sumRange˼��
	// �����к�
	/*vector2D sums(matrix);
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			sums[i][j] += sums[i][j - 1];
		}
	}
	// ��ѯO(m)���������
	for (int i = row1; i <= row2; i++) {
		sum += (col1 == 0) ? sums[i][col2] : (sums[i][col2] - sums[i][col1 - 1]);
	}*/

	// 2. ��ٲ�ѯ
	/*for (int i = row1; i <= row2; i++) {
		for (int j = col1; j <= col2; j++)
			sum += matrix[i][j];
	}*/

	// 3. Origin O(0, 0). Sum(ABCD) = Sum(OD) - Sum(OB) - Sum(OB) + Sum(OA)
	// ��������������ԭ�㿪ʼ�ľ��κ� O(mn) space
	vector2D sums = vector2D(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 1; j < matrix[0].size(); j++) {
			sums[i + 1][j + 1] = matrix[i][j] + sums[i][j + 1] + sums[i + 1][j] - sums[i][j];
		}
	}
	// ��ѯO(1)time
	sum = sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];

	return sum;
}