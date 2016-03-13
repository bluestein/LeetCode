#LeetCode

The following is classified according to its tag, namely, [Linked List][tag-list], [Array][tag-array], and [Math][tag-math], etc. For example,  [problem \#328][problem-328], its tag is "Linked List". **For detail, see .h  and .cpp file, or [Some Explanation][explanation]**.

[Stack][tag-stack]

##Linked List 

**Source File: LinkList.h & LinkList.cpp**

- \#328 ListNode\* oddEvenList(ListNode\* head) 
- \#206 ListNode\* reverseList(ListNode\* head)
- \#92 ListNode\* reverseBetween1(ListNode\* head, int m, int n)
- \#92 ListNode\* reverseBetween2(ListNode\* head, int m, int n)
- \#19 ListNode\* removeNthFromEnd(ListNode\* head, int n)
- \#203 ListNode\* removeElements(ListNode\* head, int val)

*Update 2016-3-3*

- \#234 bool isPalindrome(ListNode\* head)
- \#160 ListNode\* getIntersectionNode(ListNode\* headA, ListNode\* headB)
- \#148 ListNode\* sortList1(ListNode\* head)
- \#148 ListNode\* sortList2(ListNode\* head)
- \#109 TreeNode\* LinkList::sortedListToBST(ListNode\* head)

##Array

**Source File: Array.h & Array.cpp**

*Update 2016-3-5*

- \#283 void moveZeroes(vector<int>& nums)
- \#27 int removeElement(arr& nums, int val)
- \#243 int shortestDistance(vector<string>& words, string word1, string word2)
- \#219 bool containsNearbyDuplicate2(vector<int>& nums, int k)
- \#219 bool containsNearbyDuplicate1(vector<int>& nums, int k)
- \#169 int majorityElement(vector<int>& nums) 
- \#119 vector<int> getPascalsRow(int rowIndex)
- \#118 vector<vector<int>> generatePascals(int numRows)
- \#189 void rotate4(vector<int>& nums, int k)
- \#189 void rotate3(vector<int>& nums, int k)
- \#189 void rotate2(vector<int>& nums, int k)
- \#189 void rotate1(vector<int>& nums, int k)
- \#217 bool containsDuplicate(vector<int>& nums)

*Update 2016-3-6*

- \#62 int uniquePaths(int m, int n) // #62
- \#63 int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) // #63


##Math

**Source File: Math.h & Math.cpp**

- \#326 bool isPowerOfThree(int n)

*Update 2016-3-4*

- \#191 int hammingWeight(uint32_t n)
- \#231 bool isPowerOfTwo(int n)

##Stack

- \#232 class QueueByStack
- \#155 class MinStack;

##Some Explanation

###\#160 Get Intersection Node (*Tag: Array*)

We set 2 pointers "curA" and "curB" to point to linked-list headA and headB. Then set the
	
```
[#length of linked-list headA]=L1
[#length of linked-list headB]=L2
assuming that L1<L2
```
so, the curA will first move the tail of the headA, we have moved step T=L1
by setting the curA to headB we move the curA and the curB at the same time

```
[#distance-from-curB-to-tail]=L2-L1
```
when we move the curB to the tail of the headB then we set the curB to the headA, at the same time,

```
[#distance-from-headB-to-curA]=L2-L1
```

So we have the

```
[#distance-from-curB-to-meet-point] ==  [#distance-from-curA-to-meet-point]
```

We just move the curA and curB at the same time, then we get the meeting point .
Thanks to [RainbowSecret][rainbowSecret].

[tag-list]: #linked-list
[tag-array]: #array
[tag-math]: #math
[tag-stack]: #stack
[explanation]: #some-explanation
[problem-328]: https://leetcode.com/problems/odd-even-linked-list/
[rainbowSecret]: https://leetcode.com/discuss/77946/recommend-beginners-implementation-detailed-explaination