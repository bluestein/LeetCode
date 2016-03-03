#Linked List


1. ListNode\* oddEvenList(ListNode\* head); // #328

	> Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
	> O(1) space, O(n) time

2. ListNode\* reverseList(ListNode\* head); // #206

	> reverse a List

3. ListNode\* reverseBetween1(ListNode\* head, int m, int n); // #92
	
	> Reverse a linked list from position m to n. Do it in-place and in one-pass.

4. ListNode\* reverseBetween2(ListNode\* head, int m, int n); // #92
	
	> same as 3

5. ListNode\* removeNthFromEnd(ListNode\* head, int n); // #19

	> Given a linked list, remove the nth node from the end of list and return its head.
	> For example,
	>	Given linked list : 1->2->3->4->5, and n = 2.
	>	After removing the second node from the end, the linked list becomes 1->2->3->5.
	> Note:
	>	Given n will always be valid.
	>	Try to do this in one pass.

6. ListNode\* removeElements(ListNode\* head, int val); // #203

	> Remove all elements from a linked list of integers that have value val.
	> Example
	>	Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
	>	Return: 1 --> 2 --> 3 --> 4 --> 5

7. void printList(ListNode\* head);

	> print list

8. ListNode\* genList(int len);

	> generate a list in length of len


*Update 2016-3-3*

1. bool isPalindrome(ListNode \*head); // #234

	> Given a singly linked list, determine if it is a palindrome(回文).

2. ListNode \*getIntersectionNode(ListNode \*headA, ListNode \*headB); // # 160

	> We set 2 pointers "curA" and "curB" to point to linked-list headA and headB. Then set the
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
	Thanks to [RainbowSecret](https://leetcode.com/discuss/77946/recommend-beginners-implementation-detailed-explaination)

3. ListNode* sortList1(ListNode* head); ListNode* sortList2(ListNode* head) // #148

	> Sort a linked list in O(n log n) time using constant space complexity.

4. TreeNode* LinkList::sortedListToBST(ListNode* head) // #109

	> Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST(Binary Search Tree).

#Array


*Update 2016-3-3*

1. void moveZeroes(vector<int>& nums); // #283

	> Given an array nums, write a function to move all 0's to the end of it
	> while maintaining the relative order of the non-zero elements.

2. int removeElement(arr& nums, int val); // #27

	> Given an array and a value, remove all instances of that value in place and return the new length.
	> The order of elements can be changed.It doesn't matter what you leave beyond the new length(超出新长度的元素可以任意).


# Math

1. bool isPowerOfThree(int n); // #326

	> For the given integer n, is Power Of Three