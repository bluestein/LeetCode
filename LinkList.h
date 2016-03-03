#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class LinkList
{
public:
	LinkList();
	~LinkList();
	void printList(ListNode* head);
	ListNode* genList(int len);
	ListNode* oddEvenList(ListNode* head); // #328
	ListNode* reverseList(ListNode* head); // #206
	ListNode* reverseBetween1(ListNode* head, int m, int n); // #92
	ListNode* reverseBetween2(ListNode* head, int m, int n); // #92
	ListNode* removeNthFromEnd(ListNode* head, int n); // #19
	ListNode* removeElements(ListNode* head, int val); // #203
	ListNode* deleteDuplicates(ListNode* head); // #83
	ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2); // #21
	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2); // #21
	void deleteNode(ListNode* node); // #237
	bool isPalindrome(ListNode* head); // #234
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB); // #160
	ListNode* sortList1(ListNode* head); // #148
	ListNode* sortList2(ListNode* head); // #148
	TreeNode* sortedListToBST(ListNode* head); // #109
};

