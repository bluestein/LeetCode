#pragma once
#include "Nodes.h"

class LinkList
{
public:
	LinkList();
	~LinkList();
	void printList(ListNode* head);
	ListNode* genList(int len);
	ListNode* oddEvenList(ListNode* head); // #328
	ListNode* reverseList(ListNode* head); // #206
	ListNode* reverseBetween_1(ListNode* head, int m, int n); // #92 one-lop
	ListNode* reverseBetween_2(ListNode* head, int m, int n); // #92 two-lop
	ListNode* removeNthFromEnd(ListNode* head, int n); // #19
	ListNode* removeElements(ListNode* head, int val); // #203
	ListNode* deleteDuplicates(ListNode* head); // #83
	ListNode* mergeTwoLists_i(ListNode* l1, ListNode* l2); // #21 iterative
	ListNode* mergeTwoLists_r(ListNode* l1, ListNode* l2); // #21 recursive
	void deleteNode(ListNode* node); // #237
	bool isPalindrome(ListNode* head); // #234
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB); // #160
	ListNode* sortList_i(ListNode* head); // #148 iterative
	ListNode* sortList_r(ListNode* head); // #148 recursive
	TreeNode* sortedListToBST(ListNode* head); // #109
};

