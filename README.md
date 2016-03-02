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

# Math

1. bool isPowerOfThree(int n); // #326

	> For the given integer n, is Power Of Three