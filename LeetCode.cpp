// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkList.h"
#include "Math.h"
#include <iostream>
using namespace std;


int main()
{
	Math math;
	cout << "Power of three" << endl;
	cout << math.isPowerOfThree(243) << endl;

	LinkList list;
	ListNode *head = list.genList(10);
	
	cout << "Odd even List" << endl;
	list.printList(list.oddEvenList(head));

	cout << "Reverse List" << endl;
	list.printList(list.reverseList(head));

	cout << "Reverse between " << endl;
	head = list.genList(10); // re-generate
	list.printList(list.reverseBetween1(head, 1, 9));
	cout << endl;
	head = list.genList(10);
	list.printList(list.reverseBetween2(head, 1, 9));

	cout << "Reverse Nth node from end" << endl;
	head = list.genList(4); // re-generate
	list.printList(list.removeNthFromEnd(head, 2));

	cout << "Remove elements" << endl;
	head = list.genList(5); // re-generate
	list.printList(list.removeElements(head, 1));

	cout << "Remove duplicates" << endl;
	head = list.genList(5); // re-generate
	list.printList(list.deleteDuplicates(head));

	cout << "Merge two list" << endl;
	ListNode *l1 = list.genList(5), *l2 = list.genList(5);
	list.printList(list.mergeTwoLists2(l1, l2));

	cout << "delete node" << endl;
	head = list.genList(5); // re-generate
	list.printList(head); // before
	ListNode *node3 = head->next->next;
	list.deleteNode(node3);
	cout << endl;
	list.printList(head); // after

    return 0;
}

