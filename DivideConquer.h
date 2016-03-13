#pragma once
#include "DivideConquer.h"
#include <vector>
using namespace std;

class DivideConquer
{
public:
	bool searchMatrix(vector<vector<int>> matrix, int target); //#240
	bool searchMatrix2(vector<vector<int>> matrix, int target); //#240
private:
	bool searchHelper(vector<vector<int>> matrix, int target, int u, int d, int l, int r);
};

