#算法说明#

详细说明请看源代码。

1. int removeDuplicates(int *nums, int len);

	> 给定一个有序数组，返回unique的个数len，并且前len个数为那些unique数。要求：使用O(1)空间。如 [2,2,5,6,6], 返回 3, 前3个为 [2,5,6]

2. bool isAnagram(string s, string t);

	> 判定是否为相同字母异序词，如"god", "dog"

3. ListNode\* reverseList(ListNode \*head);

	> 反转一个链表

4. bool isUgly(int num);

	> 判断数字是否为ugly。即它的所有质数因子只能包括2，3，5。例如，6和8.而14不是，它含7。1算ugly。

5. int addDigits(int num);

	> 给定一个数，把所有位的数相加，直到变成一个数。如，29：2 + 9 = 11，1 + 1 = 2.

6. vector<int> twoSum(vector<int> &nums, int target);

	> 在一串数字中找出两个数，使得它们之和等于某个目标数，返回这两数的下标。可以假设仅有一个解。如， [2, 7, 12] target = 9. 返回 [0, 1]

7. int firstBadVersion(int n);

	> 有一组数，前x个为good，其余为bad，找出这个x。

8. int sumRange(vector<int> &nums, int i, int j);

	> “区间和”：给定一个数组，求下标区间为 [i, j](i <= j) 内元素之和。假设：1. 数组不变；2. 同时有很多调用sumRange。

9. int sumRange2D(vector< vector<int> > &matrix, int row1, int col1, int row2, int col2);

	> 给定一个矩阵，计算矩形(row1, col1), (row2, col2) 内的和。
