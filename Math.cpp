#include "stdafx.h"
#include "Math.h"
#include <math.h>

// You are playing the following Nim Game with your friend: 
// There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones.
// The one who removes the last stone will be the winner.
// You will take the first turn to remove the stones.
bool Math::canWinNim(int n) {
	return n > 0 && n % 4;
}

// Number of 1 Bits
int Math::hammingWeight(uint32_t n) 
{
	int count = 0;
	while (n) 
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}

bool Math::isPowerOfTwo(int n) 
{
	return n > 0 && !(n & (n - 1));
}

// Given an integer, write a function to determine if it is a power of three.
// solutions:
// 1. 3^19 = 1162261467, on x32 system, 3^20 bigger than int;
// 2. find in [3^0, 3^1, ..., 3^19];
// 4. brute force, O(log(n)) time
bool Math::isPowerOfThree(int n) 
{
	// s1
	return (n > 0 && 1162261467 % n == 0);

	/*
	// s2: O(1) time
	int range[] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467 };
	for (int num : range) 
	{
		if (n == num) return true;
	}
	return false;

	// s3
	return fmod(log10(n) / log10(3), 1) == 0; // fmod - float mod

	// s4
	if (n < 0) return false;
	while (n % 3 == 0)
	{
		n /= 3;
	}
	return n == 1;
	*/
}
/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example :
1->A
2->B
3->C
...
26->Z
27->AA
28->AB
*/
string Math::convertToTitle(int n)
{
	// number in base 26
	string result = "";
	while (n > 0)
	{
		result = (char)('A' + (n - 1) % 26) + result;
		n = (n-1) / 26;
	}
	return result;
}

/*
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example :
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/
int Math::titleToNumber(string s)
{
	int len = s.length(), result = 0;
	for (char ch : s)
	{
		result += pow(26, --len) * (ch - 'A' + 1);
	}
	return result;
}
/*
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/
int Math::romanToInt(string s)
{
	//Processing the roman number from right to left
	if (s.empty()) return 0;
	unordered_map<char, int> map{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int sum = map[s.back()];
	for (int i = s.size() - 2; i >= 0; --i)
	{
		sum += map[s[i]] >= map[s[i + 1]] ? map[s[i]] : -map[s[i]];
	}
	return sum;
}
