// LeetCode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkList.h"
#include "Math.h"
#include "Test.h"
#include "Array.h"
#include "QueueByStack.h"
#include "MinStack.h"
#include "DivideConquer.h"
#include "BSTIterator.h"
#include "Strings.h"
#include "Trees.h"
#include <iostream>
using namespace std;

void BSTIterator_test();
void strings_test();
void divedeConquer_test();
void minStack_test();
void queueByStack_test();
void list_test();
void array_test();
void math_test();
void test();

int main()
{
	//divedeConquer_test(); 
	strings_test();
	//math_test();
	//BSTIterator_test();
    return 0;
}

void BSTIterator_test()
{
	vector<int> nums = { 5,2,7,0,3,6,9,0,0,0,0,0,10 }; 
	TreeNode* root = Trees::BuildHeap(nums);
	/*int len = nums.size() - 1;
	TreeNode* root = Trees::BuildHeap(nums, 0, len);*/

	BSTIterator i = BSTIterator(root);
	while (i.hasNext())
	{
		cout << i.next() << endl;
	}
	cout << endl;
	while (i.hasNextByStack())
	{
		cout << i.nextByStack() << endl;
	}
}
void strings_test()
{
	Strings s;
	vector<string> v = s.generatePossibleNextMoves("++++");
	for (string str : v)
	{
		cout << str << endl;
	}
	cout << s.canPermutePalindrome("code") << endl;
	cout << s.isIsomorphic("abbc", "accb") << endl;
	cout << s.getHint("9999", "9993") << endl;
	cout << s.countAndSay(5) << endl;
}
void divedeConquer_test()
{
	DivideConquer divide;
	vector<vector<int>> matrix;
	int arr1[] = {1, 4, 7, 11, 15};
	int arr2[] = {2, 5, 8, 12, 19};
	int arr3[] = {3, 6, 9, 16, 22};
	matrix.push_back(vector<int>(arr1, arr1 + 5));
	matrix.push_back(vector<int>(arr2, arr2 + 5));
	matrix.push_back(vector<int>(arr3, arr3 + 5));
	cout << divide.searchMatrix(matrix, 22) << endl;
	cout << divide.searchMatrix2(matrix, 1) << endl;
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
	cout << math.convertToTitle(52) << endl;
	cout << math.titleToNumber("AZ") << endl;
	cout << math.romanToInt("MMMCCCXXXIII") << endl;
	cout << math.trailingZeroes(5) << endl;
	cout << math.isPalindrome(77) << endl;
	cout << math.reverseBits(43261596) << endl;
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

