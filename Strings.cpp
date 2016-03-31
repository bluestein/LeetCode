#include "stdafx.h"
#include "Strings.h"

// Given a string, determine if a permutation of the string could form a palindrome.
// For example,
// "code"->False, "aab"->True, "carerac"->True.
bool Strings::canPermutePalindrome(string s)
{
	for (int i = 0; i < s.length() / 2; ++i)
	{
		if (s[i] != s[s.length() - 1 - i]) return false;
	}
	return true;
}

// You are playing the following Flip Game with your friend: 
// Given a string that contains only these two characters : +and -, 
// you and your friend take turns to flip two consecutive "++" into "--".
// The game ends when a person can no longer make a move and therefore the other person will be the winner.
// Write a function to compute all possible states of the string after one valid move.
// For example, given s = "++++", after one move, it may become one of the following states :
//[
//	"--++",
//	"+--+",
//	"++--"
//]
vector<string> Strings::generatePossibleNextMoves(string s) 
{
	vector<string> result;
	if (s.length() < 2) return result;
	for (int i = 0; i < s.length() - 1; ++i)
	{
		if (s[i] == '+' && s[i + 1] == '+')
		{
			s[i] = s[i + 1] = '-';
			result.push_back(s); 
			s[i] = s[i + 1] = '+';
		}
	}
	return result;
}

//Given two strings s and t, determine if they are isomorphic.
//Two strings are isomorphic if the characters in s can be replaced to get t.
//All occurrences of a character must be replaced with another character while preserving the order of characters.
//No two characters may map to the same character but a character may map to itself.
//For example,
//Given "egg", "add", return true.
//Given "foo", "bar", return false.
//Given "paper", "title", return true.
bool Strings::isIsomorphic(string s, string t)
{
	int map1[256] = { 0 }, map2[256] = { 0 }; //256 is the maximum value ASCII can represent.
	for (int i = 0; i < s.size(); ++i)
	{
		if (map1[s[i]] != map2[t[i]]) return false;
		map1[s[i]] = i + 1;
		map2[t[i]] = i + 1;
	}
	return true;
}

/*
https://leetcode.com/problems/bulls-and-cows/
For example :
	Secret number : "1807"
	Friend's guess: "7810"
Hint : 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
Use A to indicate the bulls and B to indicate the cows.In the above example, your function should return "1A3B".
Please note that both secret number and friend's guess may contain duplicate digits, for example:
	Secret number : "1123"
	Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, 
and your function should return "1A1B".
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
*/
string Strings::getHint(string secret, string guess)
{
	int A = 0, B = 0;
	vector<int> sv(10, 0), gv(10, 0);
	for (int i = 0; i < secret.size(); ++i)
	{
		char c1 = secret[i], c2 = guess[i];
		if (c1 == c2) A++; // count A
		else sv[c1 - '0']++, gv[c2 - '0']++;
	}

	for (int i = 0; i < sv.size(); ++i) // count B
	{ 
		B += min(sv[i], gv[i]);
	}
	return to_string(A) + 'A' + to_string(B) + 'B';
}

/*
The count - and-say sequence is the sequence of integers beginning as follows :
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/
string Strings::countAndSay(int n)
{
	if (n <= 1) return "1";
	string ans = "11";
	for (int i = 2; i < n; ++i)
	{
		char cur = ans[0];
		int cnt = 1;
		string tmp("");
		for (int j = 1; j < ans.size(); ++j)
		{
			if (ans[j] == cur)
			{
				cnt++;
			}
			else
			{
				tmp += to_string(cnt) + cur;
				cur = ans[j];
				cnt = 1;
			}
		}
		tmp += to_string(cnt) + cur;
		ans = tmp;
	}
	return ans;
}

//Write a function to find the longest common prefix string amongst an array of strings.
string Strings::longestCommonPrefix(vector<string>& strs)
{
	if (!strs.size() || !strs[0].size()) return string();
	string prefix = strs[0];
	for (int i = 1; i < strs.size(); ++i)
	{
		string::iterator it = prefix.begin();
		int j = 0;
		string cur = strs[i];
		while (j < prefix.size() && j < strs[i].size())
		{
			if (cur[j] != prefix[j]) break;
			j++;
		}
		string::iterator erase_start = it + j;
		prefix.erase(erase_start, prefix.end());
		if (!prefix.size()) return string();
	}
	return prefix;
}

//Given two binary strings, return their sum(also a binary string).
//For example,
//a = "11"
//b = "1"
//Return "100".
string Strings::addBinary(string a, string b)
{
	string::reverse_iterator it_a = a.rbegin(), it_b = b.rbegin();
	int carry = 0;
	string ans;
	while (it_a != a.rend() || it_b != b.rend())
	{
		int val_a = 0, val_b = 0;
		if (it_a != a.rend())
		{
			val_a = *it_a - '0';
			it_a++;
		}
		if (it_b != b.rend())
		{
			val_b = *it_b - '0';
			it_b++;
		}
		int sum = val_a + val_b + carry;
		carry = sum / 2;
		ans = to_string(sum % 2) + ans;
	}
	if (carry) ans = to_string(carry) + ans;
	return ans;
}

//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
int Strings::strStr(string haystack, string needle)
{
	int lenN = needle.size(), lenH = haystack.size();
	if (!lenN) return 0;
	if (lenN > lenH) return -1;
	for (int i = 0; i <= lenH - lenN; ++i)
	{
		if (haystack.substr(i, lenN) == needle) return i;
	}
	return -1;
}

//Given a string, find the length of the longest substring without repeating characters.
//For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
//For "bbbbb" the longest substring is "b", with the length of 1.
//S: scan left to right, record the location of the last occurrence
int Strings::lengthOfLongestSubstring(string s)
{
	const int ASCII_MAX = 256;
	vector<int> last(ASCII_MAX, -1);  // record the last occurrence
	int start = 0, max_len = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (last[s[i]] >= start)
		{
			max_len = max(i - start, max_len);
			start = last[s[i]] + 1;
		}
		last[s[i]] = i;
	}
	return max((int)s.size() - start, max_len);  // case "abc"
}

//Given a string S, find the longest palindromic substring in S.
//You may assume that the maximum length of S is 1000,
//and there exists one unique longest palindromic substring.
// S1-1: DP, O(n^2) time, O(n^2) space
//            true                             ,i = j
//f[i][j] = { s[i] = s[j]                      ,j = i + 1
//            s[i] = s[j] and f(i + 1, j - 1)  ,j > i + 1
string Strings::longestPalindrome_DP1(string s)
{
	const int n = s.size();
	bool *f = new bool[n * n];
	for (int i = 0; i < n * n; i++)
	{
		f[i] = false;
	}
	// vector<vector<bool>> f(n, vector<bool>(n, false)); // time exceeded
	int max_len = 1, start = 0;
	for (int i = 0; i < s.size(); i++)
	{
		f[i * n + i] = true; // f[i][i]
		for (int j = 0; j < i; j++)
		{
			// f[j][i] = (s[j] == s[i] && (i - j < 2 || f[j + 1][i - 1]));
			f[j * n + i] = (s[j] == s[i] && (i - j < 2 || f[(j + 1) * n + i - 1]));
			if (f[j * n + i] && max_len < (i - j + 1))
			{
				max_len = i - j + 1;
				start = j;
			}
		}
	}
	delete[] f;
	f = 0;
	return s.substr(start, max_len);
}
// S1-2: DP, O(n^2) time, O(1) space
string Strings::longestPalindrome_DP2(string s)
{
	const int n = s.size();
	if (n == 0) return string();
	string longest = s.substr(0, 1);  // single char itself is a palindrome
	for (int i = 0; i < n - 1; i++)
	{
		string s1 = expandCenter(s, i, i);
		string s2 = expandCenter(s, i, i + 1);
		if (s1.size() > longest.size()) longest = s1;
		if (s2.size() > longest.size()) longest = s2;
	}
	return longest;
}
string Strings::expandCenter(string s, int l, int r)
{
	const int n = s.size();
	while (l >= 0 && r <= n - 1 && s[l] == s[r])
	{
		l--;
		r++;
	}
	return s.substr(l + 1, r - l - 1);
}

// S2: Manacher's Algorithm, O(n) time, O(n) space
string Strings::longestPalindrome_Manachers(string s)
{
	string T = preProcess(s);
	const int n = T.size();
	int *P = new int[n];
	int C = 0, R = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int i_mirror = 2 * C - i;  // equals to i' = C - (i - C)
		P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;

		// Attempt to expand palindrome centered at i
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
		{
			P[i]++;
		}

		// If palindrome centered at i expand past R,
		// adjust center based on expanded palindrome
		if (i + P[i] > R)
		{
			C = i;
			R = i + P[i];
		}
	}

	// find the maximun element in P
	int max_len = 0, center_index = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (P[i] > max_len)
		{
			max_len = P[i];
			center_index = i;
		}
	}
	delete[] P;
	P = 0;
	return s.substr((center_index - 1 - max_len) / 2, max_len);
}
// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string Strings::preProcess(string s)
{
	int n = s.size();
	if (n == 0) return "^$";
	string ans = "^";
	for (int i = 0; i < n; i++) ans += "#" + s.substr(i, 1);
	ans += "#$";
	return ans;
}

//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//(you may want to display this pattern in a fixed font for better legibility)
//P   A   H   N
//A P L S I I G
//Y   I   R
//And then read line by line : "PAHNAPLSIIGYIR"
string Strings::convertZigZag(string s, int numRows)
{
	if (numRows == 1) return s;
	int d = 2 * (numRows - 1);  // distance between pipes |/|/|
	int len = s.size();
	string ans;
	for (int i = 0; i < numRows; i++)
	{
		for (int j = i; j < len; j += d)
		{
			ans.push_back(s[j]);
			if (i > 0 && i < numRows - 1 && j + d - 2 * i < len)
			{
				ans.push_back(s[j + d - 2 * i]);  // character between pipes
			}
		}
	}
	return ans;
}

//Implement atoi to convert a string to an integer.
// 2^31 - 1 = 2147483647
int Strings::myAtoi(string str)
{
	if (str.empty()) return 0;
	// skip space
	int len = str.size(), cur = 0;
	while (cur < len && str[cur] == ' ') cur++;
	// negative or positive
	bool is_negative = false;
	if (str[cur] == '-') 
	{
		is_negative = true;
		cur++;
	}
	else if (str[cur] == '+')
	{
		cur++;
	}
	// start converting
	long long ans = 0;
	for (; cur < len; cur++)
	{
		if (str[cur] > '9' || str[cur] < '0') break;
		int num = str[cur] - '0';
		ans = ans * 10 + (is_negative ? -num : num);
		// check overflow
		if (ans < INT32_MIN) return INT32_MIN;
		if (ans > INT32_MAX) return INT32_MAX;
	}
	return ans;
}