#include "stdafx.h"
#include "DivideConquer.h"


// Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
// linear search: from up right corner || bottom left corner
bool DivideConquer::searchMatrix(vector<vector<int>> matrix, int target)
{
	if (!matrix.size() || !matrix[0].size()) return false;
	int row = 0, col = matrix[0].size() - 1;
	while (row < matrix.size() && col >= 0)
	{
		if (matrix[row][col] == target) return true;
		matrix[row][col] > target ? --col : ++row;
	}
	return false;
}
// divide and conquer
bool DivideConquer::searchMatrix2(vector<vector<int>> matrix, int target)
{
	if (!matrix.size() || !matrix[0].size()) return false;
	if (matrix.size() == 1 && matrix[0].size() == 1) return matrix[0][0] == target;
	return searchHelper(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
}

bool DivideConquer::searchHelper(vector<vector<int>> matrix, int target,  int u, int d, int l, int r)
{
	// Corner case
	if ( u < 0 || d >= matrix.size() || l < 0 || r >= matrix[0].size() || u > d || l > r) return false;
	int row = u + (d - u) / 2;
	int col = l + (r - l) / 2;
	// target == center
	if (matrix[row][col] == target) return true;
	else if (matrix[row][col] > target) // eliminate the bottom right quadrant
	{
		return searchHelper(matrix, target, u, row - 1, l, col - 1) || // up-left
			   searchHelper(matrix, target, u, row - 1, col, r) || // up-right
			   searchHelper(matrix, target, row, d, l, col - 1); // down-left
	} 
	else  // eliminate the up left quadrant
	{
		return searchHelper(matrix, target, row + 1, d, col + 1, r) || // down-right
			searchHelper(matrix, target, row + 1, d, l, col) || // down-left
			searchHelper(matrix, target, u, row, col + 1, r); // up-right
	}
}
