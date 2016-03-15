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