#pragma once
#include <queue>
#include <stack>
#include "Structs.h"
using namespace std;


// Implement an iterator over a binary search tree(BST).
// Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
// Tags: Tree Stack Design
class BSTIterator // #173
{
private:
	queue<TreeNode*> que;
	stack<TreeNode*> stack;
	void genQueue(TreeNode *root);
	void genStack(TreeNode *root);
public:
	BSTIterator(TreeNode *root);
	/** @return whether we have a next smallest number */
	bool hasNext();
	/** @return the next smallest number */
	int next();

	/** @return whether we have a next smallest number */
	bool hasNextByStack();
	/** @return the next smallest number */
	int nextByStack();
};

