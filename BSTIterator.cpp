#include "stdafx.h"
#include "BSTIterator.h"


BSTIterator::BSTIterator(TreeNode *root)
{
	genQueue(root);
	genStack(root);
}

void BSTIterator::genQueue(TreeNode *root)
{
	if (root != NULL) {
		genQueue(root->left);
		que.push(root);
		genQueue(root->right);
	}
}


/** @return whether we have a next smallest number */
bool BSTIterator::hasNext()
{
	return !que.empty();
}

/** @return the next smallest number */
int BSTIterator::next() 
{
	int curMin = que.front()->val;
	que.pop();
	return curMin;
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNextByStack()
{
	return !stack.empty();
}

/** @return the next smallest number */
int BSTIterator::nextByStack()
{
	TreeNode* curMin = stack.top();
	stack.pop();
	genStack(curMin->right);
	return curMin->val;
}

void BSTIterator::genStack(TreeNode *root)
{
	while (root)
	{
		stack.push(root);
		root = root->left;
	}
}