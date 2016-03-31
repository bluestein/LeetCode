#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Strings
{
private:
	string preProcess(string s);
	string expandCenter(string s, int c1, int c2);
public:
	bool canPermutePalindrome(string s); // #266
	vector<string> generatePossibleNextMoves(string s); // #293
	bool isIsomorphic(string s, string t); // #205
	string getHint(string secret, string guess); // #299
	string countAndSay(int n); // #38
	string longestCommonPrefix(vector<string>& strs); // #14
	string addBinary(string a, string b); // #67
	int strStr(string haystack, string needle); // #28
	int lengthOfLongestSubstring(string s);  // #3
	string longestPalindrome_DP1(string s);  // #5
	string longestPalindrome_DP2(string s);  // #5
	string longestPalindrome_Manachers(string s);  // #5
	string convertZigZag(string s, int numRows);  // #6
	int myAtoi(string str);  // #8
};