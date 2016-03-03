#include "stdafx.h"
#include "LinkList.h"



LinkList::LinkList()
{
}


LinkList::~LinkList()
{
}

ListNode* LinkList::genList(int len) {
	if (len == 0) return NULL;
	ListNode *head = new ListNode(1);
	if (len == 1) return head;
	ListNode *cur = head;
	for (int i = 2; i <= len; i++) {
		ListNode *tmp = new ListNode(i);
		cur->next = tmp;
		cur = tmp;
	}
	return head;
}

void LinkList::printList(ListNode* head) {
	if (head == NULL) printf("NULL List!\n");
	while (head != NULL)
	{
		printf("%d\n", head->val);
		head = head->next;
	}
}

// 给定一个单向链表，将下标为奇数的节点放在一起，后面接偶数节点。试着在原链表上完成。
// 其中，奇偶节点的顺序跟原来一致，第一个是奇节点。
// 要求：O(1) space, O(n) time
// 算法：通过改变指针，生成两个链表，分别是odd，even，然后连接起来即可。
// 如， [1,2,3,4,5], odd: [1,3,5], even: [2,4], => result: odd->even
ListNode* LinkList::oddEvenList(ListNode* head) {
	if (head == NULL || head->next == NULL) return head;
	ListNode* odd = head;
	ListNode* even = head->next;
	ListNode* even_head = head->next;
	while (even != NULL && even->next != NULL)
	{
		odd->next = even->next;
		odd = even->next;
		even->next = odd->next;
		even = odd->next;
	}
	odd->next = even_head;
	return head;
}

// 反转一个链表
ListNode* LinkList::reverseList(ListNode* head) {
	if (head == NULL) return head;
	ListNode* pre = NULL;
	ListNode* cur = head;
	while (cur != NULL)
	{
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	head = pre;
	return head;
}

// 反转一个链表在区间 [m, n] (1 <= m <= n <= List.length) 部分。
// 要求：in-place， one-pass
// 算法1：one-loop
//	分两种情况：下面 "->" 表示连接。
//	case1: m = 1 从第一个开始反转，然后 head = Node(n), Node(m)->Node(n + 1);
//	case2: m > 1 从m个开始反转，然后 Node(m - 1)->Node(n)， Node(m)->Node(n + 1);
// 算法2：two-loop
//	先定位到 m - 1，然后开始反转。考虑到 m = 1的情况，创建一个head节点。
ListNode* LinkList::reverseBetween1(ListNode* head, int m, int n) {
	if (m == n) return head;
	// 1： one-loop
	int cnt = 1;
	ListNode *cur = head, *left = NULL, *tail = NULL, *pre = NULL;
	while (cnt <= n) {
		if (m == 1 && cnt == 1) { // case1: m = 1
			tail = cur;
			pre = tail;
			cur = cur->next;
			cnt++;
		}
		else if (cnt == m - 1 ) {// case2: m > 1
			left = cur;
			tail = cur->next;
			pre = tail;
			cur = cur->next;
			cnt ++;
		}
		// 反转
		if (cnt > m) { // 开始反转
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
			cnt++;
		}
		else { // 跳过不需反转元素
			cnt++;
			cur = cur->next;
		}
	}
	if (m == 1) {
		head = pre; // head = Node(n)
	}
	else {
		left->next = pre; // Node(m - 1)->Node(n)
	}
	tail->next = cur; // Node(m)->Node(n + 1)
	return head;
}

// 2: two-loop
ListNode* LinkList::reverseBetween2(ListNode* head, int m, int n) {
	if (m == n) return head;
	ListNode* head_new = new ListNode(0);
	head_new->next = head;
	ListNode *left = head_new, *pre, *cur;
	for (int i = 0; i < m - 1; i++)
		left = left->next; //skip
	pre = left->next;
	cur = pre->next;
	for (int i = 0; i < n - m; i++) { //reverse
		ListNode* tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}
	left->next->next = cur; // left link to right
	left->next = pre;
	head = head_new->next;
	delete head_new;
	return head;
}

// Given a linked list, remove the nth node from the end of list and return its head.
// For example,
//	Given linked list : 1->2->3->4->5, and n = 2.
//	After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:
//	Given n will always be valid.
//	Try to do this in one pass.
ListNode* LinkList::removeNthFromEnd(ListNode* head, int n) {
	if (head->next == NULL || head == NULL) return NULL;
	ListNode *pre = NULL, *target = head, *cur = head;
	while (n-- > 0)
	{
		cur = cur->next;
	}
	if (cur == NULL) { // delete head
		ListNode *tmp = head;
		head = head->next;
		delete tmp;
		return head;
	}
	while (cur != NULL) {
		pre = target;
		target = target->next;
		cur = cur->next;
	}
	pre->next = target->next;
	delete target;
	return head;
}

// Remove all elements from a linked list of integers that have value val.
// Example
//	Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//	Return: 1 --> 2 --> 3 --> 4 --> 5
// S1：
//	new a node，so all case can be treated as "inner delete"
// S2:
//	two pointers, pre and cur. use a while loop to deal with "head delete".
ListNode* LinkList::removeElements(ListNode* head, int val) {
	//S1
	/*ListNode* head_new = new ListNode(0);
	head_new->next = head;
	ListNode *pre = head_new, *cur = head;
	while (cur != NULL) {
		if (cur->val == val) {
			ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			delete tmp; // free space
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head_new->next;*/

	//S2
	while (head != NULL && head->val == val)
		head = head->next;
	if (head == NULL) return NULL; // case: [1,1,1] and 1
	ListNode *pre = head, *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val == val) {
			ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			delete tmp; // free space
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}

// Given a sorted linked list, delete all duplicates such that each element appear only once.
ListNode* LinkList::deleteDuplicates(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *pre = head, *cur = head->next;
	while (cur != NULL) {
		if (cur->val == pre->val) {
			ListNode* tmp = cur;
			pre->next = cur->next;
			cur = cur->next;
			delete tmp; // free space
		}
		else {
			pre = cur;
			cur = cur->next;
		}
	}
	return head;
}
// Merge two sorted linked lists and return it as a new list. 
// The new list should be made by splicing together the nodes of the first two lists.
ListNode* LinkList::mergeTwoLists1(ListNode* l1, ListNode* l2) {
	ListNode *head = new ListNode(0);
	ListNode *cur = head;
	while (l1 && l2)
	{
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
		}
		else {
			cur->next = l2;
			l2 = l2->next;
		}
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	if (l2) cur->next = l2;
	ListNode *temp = head;
	head = head->next;
	delete temp;
	return head;

	// no fake head
	/*if (!l1) return l2;
	if (!l2) return l1;
	if(l1->val > l2->val){
	    ListNode *temp = l1;
	    l1 = l2, l2 = temp;
	}
	ListNode *head = l1;
	ListNode *cur = head;
	l1 = l1->next;
	while (l1 && l2)
	{
		if (l1->val <= l2->val) {
			cur->next = l1;
			l1 = l1->next;
	    }
		else {
		    cur->next = l2;
		l2 = l2->next;
	    }
		cur = cur->next;
	}
	if (l1) cur->next = l1;
	if (l2) cur->next = l2;
	return head;*/
}

//recursive
ListNode* LinkList::mergeTwoLists2(ListNode* l1, ListNode* l2) {
	if (!l1) return l2;
	if (!l2) return l1;
	if (l1->val <= l2->val) {
		l1->next = mergeTwoLists2(l1->next, l2);
		return l1;
	}
	else {
		l2->next = mergeTwoLists2(l1, l2->next);
		return l2;
	}
}

// Write a function to delete a node (except the tail) in a singly linked list,
// given only access to that node.
// S: delete the node->next!
void LinkList::deleteNode(ListNode* node) {
	ListNode *next = node->next;
	node->val = next->val;
	node->next = next->next;
	delete next;
}

// Given a singly linked list, determine if it is a palindrome(回文).
// Follow up: Could you do it in O(n) time and O(1) space ?
// S: reverse halve of list, then campare
//	two pointers, one fast, the other slow. two cases, odd and even.
//	the fast pointer faster than slow pointer two steps
bool LinkList::isPalindrome(ListNode* head) {
	if (head == NULL || head->next == NULL) return true;
	ListNode *slow = head, *fast = head, *pre = NULL;
	while (fast && fast->next) { // reverse half
		fast = fast->next->next;
		ListNode *next = slow->next;
		slow->next = pre;
		pre = slow;
		slow = next;
	}
	if (fast) slow = slow->next; // odd case
	while (pre && slow) { // compare
		if (pre->val != slow->val) return false;
		pre = pre->next;
		slow = slow->next;
	}
	return true;
}

// Write a program to find the node at which the intersection(交集) of two singly linked lists begins.（交集的开始节点）
// Example: for given A[a1,a2,c1,c2], B [b1,b2,b3,c1,c2] you should return c1.
// Notes:
// - If the two linked lists have no intersection at all, return null.
// - The linked lists must retain their original structure after the function returns.
// - You may assume there are no cycles anywhere in the entire linked structure.
// - Your code should preferably run in O(n) time and use only O(1) memory.
ListNode* LinkList::getIntersectionNode(ListNode *headA, ListNode *headB) {
	if (headA == NULL || headB == NULL) return NULL;
	ListNode *curA = headA, *curB = headB;
	while (curA && curB)
	{
		if (curA == curB) return curA; // deal with [1] and [1]
		curA = curA->next;
		curB = curB->next;
		/*when the 2 linked-list do not meet, all the 2 pointers will be NULL at the same time.
          the 2 pointers can be NULL at the same time, if we continue processing, the loop will never end*/
		if (curA == curB) return curA; // case: no intersection or found
		if (curA == NULL) curA = headB;
		if (curB == NULL) curB = headA;
	}
	return curA;
}


// Sort a linked list in O(n log n) time using constant space complexity.
// S1: not O(n log n) time
ListNode* LinkList::sortList1(ListNode* head) {
	if (head == NULL) return NULL;
	ListNode *head_fake = new ListNode(0);
	head_fake->next = head;
	ListNode *front = head->next, *mid = head, *back = head_fake;
	while (front != NULL)
	{
		if (front->val < mid->val) {
			while (back != mid) {
				if (front->val <= back->next->val) {
					ListNode *back_next = back->next, *front_next = front->next;
					back->next = front;
					mid->next = front->next;
					front->next = back_next;
					front = front_next;
					// remain
					back = head_fake; 
					break;
				}
				else {
					back = back->next;
				}
			}
		}
		else {
			front = front->next;
			mid = mid->next;
		}
	}
	head = head_fake->next;
	delete head_fake;
	return head;
}

// merge
ListNode* merge(ListNode *head1, ListNode* head2) {
	ListNode *fake = new ListNode(0);
	ListNode *cur = fake;
	while (head1 || head2)
	{
		if (head1 && (!head2 || head1->val <= head2->val)) {
			cur = cur->next = head1;
			head1 = head1->next;
		}
		if (head2 && (!head1 || head2->val < head1->val)) {
			cur = cur->next = head2;
			head2 = head2->next;
		}
	}
	//cur->next = NULL;
	ListNode *head = fake->next;
	delete fake;
	return head;
}
// merge sort, O(1) space?
ListNode* LinkList::sortList2(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode *slow = head, *fast = head->next;
	while (fast && fast->next) { // to find middle node
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *head2 = slow->next; // head2 is the start of 2nd half of the list
	slow->next = NULL; // split! now head is the start of 1st half of the list
	return merge(sortList2(head), sortList2(head2));
}


// Given a singly linked list where elements are sorted in ascending(升序) order, convert it to a height balanced BST.
TreeNode* LinkList::sortedListToBST(ListNode* head) {
	if (!head) return NULL;
	if (!head->next) {
		return new TreeNode(head->val);
	}
	ListNode *fast = head->next->next, *slow = head;
	while (fast && fast->next) { // find middle node
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode *mid = slow->next; // mid is the middle point
	ListNode *head2 = slow->next->next; // head2 is the start of 2nd half of the list
	slow->next = NULL;// split! now head is the start of 1st half of the list
	TreeNode *root = new TreeNode(mid->val);
	root->left = sortedListToBST(head);
	root->right = sortedListToBST(head2);
	return root;
}