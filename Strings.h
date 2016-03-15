#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Strings
{
public:
	bool canPermutePalindrome(string s); // #266
	vector<string> generatePossibleNextMoves(string s); // #293
	bool isIsomorphic(string s, string t); // #205
	string getHint(string secret, string guess); // #299
	string countAndSay(int n); // #38
};