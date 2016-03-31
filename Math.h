#pragma once
#include <stdint.h>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <bitset>
using namespace std;

class Math
{
private:
	bool isPrime(int n);
public:
	vector<vector<int>> threeSum(vector<int> &num); // #15
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
	uint32_t reverseBits(uint32_t n); // #190
	int countPrimes_sqrt(int n); // #204
	int countPrimes_SoE(int n); // #204 Sieve of Eratosthenes(∞£ œ…∏)
	int reverse(int x);  // #7
};

