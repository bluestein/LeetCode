// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkList.h"
#include "Math.h"
#include "Test.h"
#include "Array.h"
#include "QueueByStack.h"
#include "MinStack.h"
#include <iostream>
using namespace std;

void minStack_test();
void queueByStack_test();
void list_test();
void array_test();
void math_test();
void test();


int main()
{
	minStack_test();
    return 0;
}

void minStack_test() 
{
	MinStack stack;
	stack.push(1);
	stack.push(2);
	stack.pop(); stack.pop(); stack.pop();
	cout << stack.top() << endl;
	cout << stack.getMin() << endl;
}

void queueByStack_test() 
{
	QueueByStack que, que1;
	que.push(1);
	que.push(2);
	que.pop();
	cout << que.peek() << endl;

	que1.push1(1);
	que1.push1(2);
	que1.pop1();
	cout << que1.peek1() << endl;
}

void array_test() 
{
	Array array;
	Array::arr vec = array.genVector(11);
	array.printVector(vec);
	cout << array.removeElement(vec, 1) << endl;
	array.printVector(vec);
	array.moveZeroes(vec);
	array.printVector(vec);

	int nums_arr[] = { 1,2,2,2,1 };
	Array::arr nums(nums_arr, nums_arr + 5);
	cout << array.majorityElement(nums) << endl;

	string words_arr[] = { "practice", "makes", "perfect", "coding", "makes" };
	vector<string> words(words_arr, words_arr + 5);
	cout << array.shortestDistance(words, "coding", "makes") << endl;
}

void math_test() 
{
	Math math;
	cout << "Power of three" << endl;
	cout << math.isPowerOfThree(243) << endl;

	cout << math.isPowerOfTwo(8) << endl;

	cout << math.hammingWeight(3) << endl;
}

void test() 
{
	Test test;
}

void list_test() 
{

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

	cout << "Remove Nth node from end" << endl;
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

	cout << "Delete node" << endl;
	head = list.genList(5); // re-generate
	list.printList(head); // before
	ListNode *node3 = head->next->next;
	list.deleteNode(node3);
	cout << endl;
	list.printList(head); // after

	cout << "Is palindrome" << endl;
	cout << list.isPalindrome(head) << endl;

	cout << "Get Intersection Node" << endl;
	ListNode *headA = list.genList(10);
	ListNode *headB = headA;
	list.printList(list.getIntersectionNode(headA, headB));

	cout << "Sort List" << endl;
	ListNode *reversed_list = list.reverseList(head);
	//list.printList(list.sortList1(reversed_list));
	list.printList(list.sortList2(reversed_list));
}

