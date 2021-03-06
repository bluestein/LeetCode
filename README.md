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
- \#2 ListNode\* addTwoNumbers(ListNode\* l1, ListNode\* l2)

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
- \#4 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
- \#16 int threeSumClosest(vector<int>& nums, int target)


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
- \#36 bool isValidSudoku(vector&lt;vector&lt;char&gt;&gt; &board)
- \#223 int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
- \#190 uint32_t reverseBits(uint32_t n)
- \#204 int countPrimes_sqrt(int n)
- \#204 int countPrimes_SoE(int n) // Sieve of Eratosthenes(埃氏筛)
- \#7 int reverse(int x)
- \#15 vector&lt;vector&lt;int&gt;&gt; threeSum(vector&lt;int&gt; &num)
- \#11 int maxArea(vector<int> &height)

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
- \#3 int lengthOfLongestSubstring(string s)
- \#5 string longestPalindrome_DP1(string s)
- \#5 string longestPalindrome_DP2(string s)
- \#5 string longestPalindrome_Manachers(string s)
- \#6 string convertZigZag(string s, int numRows)
- \#8 int myAtoi(string str)
- \#10 bool isMatch(string s, string p)
- \#12 string intToRoman(int num)

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


##LibraryFunctions

**Source File: LibraryFunctions.h & LibraryFunctions.cpp**

- Copying
	- char\*       strcpy(char\* dest, const char\* src);
	- char\*       strncpy(char\* dest, const char\* src, size_t count);
	- void\*       memcpy(void\* dest, const void\* src, size_t count);
	- void\*       memmove(void\* dest, const void\* src, size_t count);

- Comparison
	- int         strcmp(const char\* lhs, const char\* rhs);
	- int         strncmp(const char\* lhs, const char\* rhs, size_t count);
	- int         memcmp(const void\* lhs, const void\* rhs, size_t count);

- Searching
	- const char\* strchr(const char\* str, int ch);
	- const char\* strrchr(const char\* str, int ch);
	- const char\* strstr_(const char\* str, const char\* target);
	- const char\* strstr(const char\* str, const char\* target);
	- const char\* strpbrk(const char\* dest, const char\* breakset); 
	- size_t      strspn(const char\* dest, const char\* accept);
	- size_t      strcspn(const char\* dest, const char\* reject);

- Concatenation
	- char\*       strcat(char\* dest, const char\* src); 
	- char\*       strncat(char\* dest, const char\* src, size_t count);

- Other
	- int         strlen(const char\* str);
	- void\*       memset(void\* dest, int ch, size_t count);

##Some Explanation

###\#160 Get Intersection Node (array)

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


### \#5 Longest Palindromic Substring (string) ###

LeetCode: [longest palindromic substring](https://leetcode.com/problems/longest-palindromic-substring)

There are about five different solutions. Details see

in Chinese:

[Longest palindromic substring][LPS]. 

Or in English:

1. [Longest palindromic substring part I][LPS-i]
2. [Longest palindromic substring part II][LPS-ii]

### \#11 Container With Most Water ###

1. The widest container (using first and last line) is a good candidate, because of its width. Its water level is the height of the smaller one of first and last line.
2. All other containers are less wide and thus would need a higher water level in order to hold more water.
3. The smaller one of first and last line doesn't support a higher water level and can thus be safely removed from further consideration.

For example, given height = [1, 2, 1, 2]

```
index: 0 1 2 3
value: 1 3 1 2
       ^     ^
       i     j
```

area = min(1, 2) * (3 - 0) = 3

curMax = 3

(i) < (j), so i = i + 1 = 1


```
index: 0 1 2 3
value: 1 3 1 2
         ^   ^
         i   j
```

area = min(3, 2) * (3 - 1) = 4

curMax = 4

(i) > (j), so j = j - 1 = 2


```
index: 0 1 2 3
value: 1 3 1 2
         ^ ^
         i j
```

area = min(3, 2) * (2 - 1) = 2

curMax = 4

(i) < (j), so j = j - 1 = 1


```
index: 0 1 2 3
value: 1 3 1 2
         ^
        i,j
```

i == j, then done.

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
[LPS]: http://bluestein.github.io/2016/03/algorithm-LPS/
[LPS-i]: http://articles.leetcode.com/longest-palindromic-substring-part-i/
[LPS-ii]: http://articles.leetcode.com/longest-palindromic-substring-part-ii/