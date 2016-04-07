#include "stdafx.h"
#include "Math.h"

//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0 ?
//Find all unique triplets in the array which gives the sum of zero.
//Note :
//	Elements in a triplet(a, b, c) must be in non - descending order. (ie, a ≤ b ≤ c)
//	The solution set must not contain duplicate triplets.
// 先排序，然后左右夹逼，注意跳过重复的数，时间复杂度 O(n^2)，空间复杂度 O(1)
vector<vector<int>> Math::threeSum(vector<int> &nums)
{
	vector<vector<int>> ans;
	if (nums.size() < 3) return ans;
	sort(nums.begin(), nums.end());
	const int target = 0;
	auto last = nums.end();
	for (auto i = nums.begin(); i <= last - 2; ++i)
	{
		auto j = i + 1;
		if (i > nums.begin() && *i == *(i - 1)) continue;
		auto k = last - 1;
		while (j < k)
		{
			if (*i + *j + *k < target)
			{
				++j;
				while (*j == *(j - 1) && j < k) ++j;
			}
			else if (*i + *j + *k > target)
			{
				--k;
				while (*k == *(k + 1) && j < k) --k;
			}
			else 
			{
				ans.push_back({ *i, *j, *k });
				++j;
				--k;
				while (*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
			}
		}
	}
	return ans;
}

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
wiki: https://en.wikipedia.org/wiki/Roman_numerals
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

//Given an integer n, return the number of trailing zeroes in n!.
//Note: Your solution should be in logarithmic time complexity.
// the 0 come from 2*5, so we just need count the number of 5.
int Math::trailingZeroes(int n)
{
	int numZeros(0);
	while (n)
	{
		n /= 5;
		numZeros += n;
	}
	return numZeros;
}

//Determine whether an integer is a palindrome. Do this in constant space.
bool Math::isPalindrome(int n)
{
	// reverse the integer
	int result = 0, tmp = n;
	while (n > 0)
	{
		result = result * 10 + n % 10;
		if (result > tmp) return false;
		n /= 10;
	}
	return result == tmp;
}

// Determine if a Sudoku is valid, according to : 
// [Sudoku Puzzles - The Rules](http ://sudoku.com.au/TheRules.aspx).
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
bool Math::isValidSudoku(vector<vector<char>>& board)
{
	// check row, col, and block at the same time
	bool row[9][9] = { false }, col[9][9] = { false }, block[9][9] = { false };
	for (int i = 0; i < 9; i ++)
	{
		for (int j = 0; j < 9; j ++)
		{
			if (board[i][j] != '.')
			{
				//num should be in the range of [0, 8] instead of [1, 9] to be mapped in to row[9][9];
				int num = board[i][j] - '1'; 
				//mapping num into sub - blocks
				int k = i / 3 * 3 + j / 3;
				if (row[i][num] || col[j][num] || block[k][num]) return false;
				row[i][num] = col[j][num] = block[k][num] = true;
			}
		}
	}
	return true;
}

// Find the total area covered by two rectilinear rectangles in a 2D plane.
// Each rectangle is defined by its bottom left corner and top right corner
// Assume that the total area is never beyond the maximum possible value of int.
int Math::computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
	int total = (C - A) * (D - B) + (G - E) * (H - F);
	if (E >= C || F >= D || A >= G || B >= H) return total; // no overlap
	int I = max(A, E), J = max(B, F); // bottom left
	int K = min(C, G), L = min(D, H); // top right
	return total - (K - I) * (L - J);
}

//Reverse bits of a given 32 bits unsigned integer.
//For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
//Follow up :
//If this function is called many times, how would you optimize it ?
uint32_t Math::reverseBits(uint32_t n)
{
	/*uint32_t ans = 0, range = 32;
	while (range--)
	{
		ans <<= 1;
		ans |= n & 1;
		n >>= 1;
	}
	return ans;*/

	// solution2: bitset
	bitset<32> bSet(n);
	int l = 0, r = 31;
	while (r > l)
	{
		if ((!bSet[l] && bSet[r]) || (bSet[l] && !bSet[r]))
		{
			bSet.flip(l);
			bSet.flip(r);
		}
		l++, r--;
	}
	return bSet.to_ulong();
}

//Count the number of prime numbers less than a non - negative number, n.
int Math::countPrimes_sqrt(int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (isPrime(i)) count++;
	}
	return count;
}
/*
Let's write down all of 12's factors :
	2 × 6 = 12
	3 × 4 = 12
	4 × 3 = 12
	6 × 2 = 12
As you can see, calculations of 4 × 3 and 6 × 2 are not necessary.
Therefore, we only need to consider factors up to √n because, 
if n is divisible by some number p, then n = p × q and since p ≤ q, 
we could derive that p ≤ √n.
O(n^1.5)
*/
bool Math::isPrime(int n)
{
	if (n <= 1) return false;
	// Loop's ending condition is i * i <= num instead of i <= sqrt(num)
	// to avoid repeatedly calling an expensive function sqrt().
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}
//Sieve_of_Eratosthenes
//https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
int Math::countPrimes_SoE(int n)
{
	/*vector<bool> isPrime(n);
	for (int i = 2; i < n; ++i)
	{
		isPrime[i] = true;
	}
	for (int i = 2; i * i < n; ++i)
	{
		if (!isPrime[i]) continue;
		for (int j = i * i; j < n; j += i)
		{
			isPrime[j] = false;
		}
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (isPrime[i]) count++;
	}
	return count;*/

	if (n <= 2) return 0;
	// cnt = 1 for number 2, because we do not count it next
	int cnt = 1;
	bool* isprimes = new bool[n];
	for (int i = 0; i < n; i++)
		isprimes[i] = true;

	// skip all even number
	for (int i = 3; i*i <= n; i += 2) {
		if (isprimes[i])
			// i is a odd number so, i*i + i, i*i + 3i... are even number, so we skip these number by doing j += 2*i
			for (int j = i*i; j < n; j += 2 * i)
				isprimes[j] = false;
	}

	// skip all even number
	for (int i = 3; i < n; i += 2) {
		if (isprimes[i] == true)
			cnt++;
	}
	return cnt;
}

//Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2 : x = -123, return -321
// consider cases: 1, negative; 2, overflow
// 2^31 - 1 = 2147483647
int Math::reverse(int x)
{
	long long r = 0;
	long long t = x;
	t = t > 0 ? t : -t;
	for (; t; t /= 10)
	{
		r = r * 10 + t % 10;
	}
	bool is_negative = x > 0 ? false : true;
	r = is_negative ? -r : r;
	if (r < INT32_MIN || r > INT32_MAX) r = 0;
	return r;
}

//Given n non - negative integers a1, a2, ..., an, where each represents a point at coordinate(i, ai).
//n vertical lines are drawn such that the two endpoints of line i is at(i, ai) and (i, 0).
//Find two lines, which together with x - axis forms a container, such that the container contains the most water.
int Math::maxArea(vector<int> &height)
{
	int start = 0;
	int end = height.size() - 1;
	int ans = INT_MIN;
	while (start < end)
	{
		int area = min(height[end], height[start]) * (end - start);
		ans = max(ans, area);
		if (height[end] >= height[start])  // height[start] is shorter
		{
			start++;
		}
		else
		{
			end--;
		}
	}
	return ans;
}