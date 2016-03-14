#pragma once
#include <stdint.h>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Math
{
public:
	bool canWinNim(int n); // #292
	int hammingWeight(uint32_t n); // #191
	bool isPowerOfTwo(int n); // #231
	bool isPowerOfThree(int n); // #326
	string convertToTitle(int n); // #168
	int titleToNumber(string s); // #171
	int romanToInt(string s); // #13
	int trailingZeroes(int n); // #172
	bool isPalindrome(int n); // #9
	bool isValidSudoku(vector<vector<char>>& board);// #36
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H); // #223
};

