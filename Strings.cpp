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
