#LeetCode

The following is classified according to its tag. For example,  [problem \#328][problem-328], its tag is "Linked List". **For detail, see .h  and .cpp file, or [Some Explanation][explanation]**.

### Tags:  ###

- [Linked List][tag-list]
- [Array][tag-array]
- [Math][tag-math]
- [Stack][tag-stack]
- [Divide&Conquer][tag-divideconquer]
- [Strings][tag-strings]
- [Trees][tag-trees]
- [DynamicProgramming][tag-dp]

##Linked List 

**Source File: LinkList.h & LinkList.cpp**

- \#328 ListNode\* oddEvenList(ListNode\* head) 
- \#206 ListNode\* reverseList(ListNode\* head)
- \#92 ListNode\* reverseBetween1(ListNode\* head, int m, int n)
- \#92 ListNode\* reverseBetween2(ListNode\* head, int m, int n)
- \#19 ListNode\* removeNthFromEnd(ListNode\* head, int n)
- \#203 ListNode\* removeElements(ListNode\* head, int val)
- \#234 bool isPalindrome(ListNode\* head)
- \#160 ListNode\* getIntersectionNode(ListNode\* headA, ListNode\* headB)
- \#148 ListNode\* sortList1(ListNode\* head)
- \#148 ListNode\* sortList2(ListNode\* head)
- \#109 TreeNode\* sortedListToBST(ListNode\* head)

##Array

**Source File: Array.h & Array.cpp**

- \#283 void moveZeroes(vector&lt;int&gt;& nums)
- \#27 int removeElement(arr& nums, int val)
- \#243 int shortestDistance(vector&lt;string&gt;& words, string word1, string word2)
- \#219 bool containsNearbyDuplicate2(vector&lt;int&gt;& nums, int k)
- \#219 bool containsNearbyDuplicate1(vector&lt;int&gt;& nums, int k)
- \#169 int majorityElement(vector&lt;int&gt;& nums) 
- \#119 vector&lt;int&gt; getPascalsRow(int rowIndex)
- \#118 vector&lt;vector&lt;int&gt;&gt; generatePascals(int numRows)
- \#189 void rotate4(vector&lt;int&gt;& nums, int k)
- \#189 void rotate3(vector&lt;int&gt;& nums, int k)
- \#189 void rotate2(vector&lt;int&gt;& nums, int k)
- \#189 void rotate1(vector&lt;int&gt;& nums, int k)
- \#217 bool containsDuplicate(&lt;int&gt;& nums)
- \#252 bool canAttendMeetings(vector&lt;Interval&gt;& intervals)
- \#62 int uniquePaths(int m, int n)
- \#63 int uniquePathsWithObstacles(vector&lt;vector&lt;int&gt;&gt;& obstacleGrid)


##Math

**Source File: Math.h & Math.cpp**

- \#326 bool isPowerOfThree(int n)
- \#191 int hammingWeight(uint32_t n)
- \#231 bool isPowerOfTwo(int n)
- \#13 int romanToInt(string s)
- \#168 string convertToTitle(int n)
- \#171 int titleToNumber(string s)
- \#292 bool canWinNim(int n)
- \#9 bool isPalindrome(int n)
- \#172 int trailingZeroes(int n)
- \#36 bool isValidSudoku(vector&lt;vector&lt;char&gt;&gt;& board)
- \#223 int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
- \#190 uint32_t reverseBits(uint32_t n)
- \#204 int countPrimes_sqrt(int n)
- \#204 int countPrimes_SoE(int n) // Sieve of Eratosthenes(埃氏筛)

##Stack

- \#232 class QueueByStack
	- Source File: QueueByStack.h & QueueByStack.cpp
- \#155 class MinStack
	- Source File: MinStack.h & MinStack.cpp

##DivideConquer

**Source File: DivideConquer.h & DivideConquer.cpp**

- \#240 bool searchMatrix(vector&lt;vector&lt;int&gt;&gt; matrix, int target)

##Strings

**Source File: Strings.h & Strings.cpp**

- \#266 bool canPermutePalindrome(string s)
- \#293 vector&lt;string&gt; generatePossibleNextMoves(string s)
- \#205 bool isIsomorphic(string s, string t)
- \#229 string getHint(string secret, string guess)
- \#38 string countAndSay(int n)
- \#14 string longestCommonPrefix(vector&lt;string&gt;& strs)
- \#67 string addBinary(string a, string b)
- \#28 int strStr(string haystack, string needle)

##Trees

**Source File: Trees.h & Trees.cpp**

- \#101 bool isSymmetric(TreeNode* root)
- \#102 vector&lt;vector&lt;int&gt;&gt; levelOrder(TreeNode* root)
- \#107 vector&lt;vector&lt;int&gt;&gt; levelOrderBottom(TreeNode* root)
- \#112 bool hasPathSum(TreeNode* root, int sum)
- \#111 int minDepth(TreeNode* root)

##DynamicProgramming

**Source File: DynamicProgramming.h & DynamicProgramming.cpp**

- \#198 int rob(vector&lt;int&gt;& nums)

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
[tag-divideconquer]: #divideconquer
[tag-strings]: #strings
[tag-trees]: #trees
[tag-dp]: #dynamicprogramming
[explanation]: #some-explanation
[problem-328]: https://leetcode.com/problems/odd-even-linked-list/
[rainbowSecret]: https://leetcode.com/discuss/77946/recommend-beginners-implementation-detailed-explaination