#include "stdafx.h"
#include "Math.h"
#include <math.h>


Math::Math()
{
}


Math::~Math()
{
}

// Number of 1 Bits
int Math::hammingWeight(uint32_t n) {
	int count = 0;
	while (n) {
		n = n & (n - 1);
		count++;
	}
	return count;
}

bool Math::isPowerOfTwo(int n) {
	return n > 0 && !(n & (n - 1));
}

// 给定一个整数，判定它是否为3的乘方。提升：不用任何循环和递归
// 算法：
// 1. 3^19 = 1162261467, 32系统下 3^20 大于 int；
// 2. 在[3^0, 3^1, ..., 3^19]中找；
// 3. 判定幂是否为整数；
// 4. 暴力法 O(log(n)) time
bool Math::isPowerOfThree(int n) {
	// 法1
	return (n > 0 && 1162261467 % n == 0);

	/*
	// 法2: O(1) time
	int range[] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467 };
	for (int i = 0; i < 20; i++) {
	if (n == range[i]) return true;
	}
	return false;

	// 法3
	return fmod(log10(n) / log10(3), 1) == 0; // fmod 浮点数取模

	// 法4
	if (n < 0) return false;
	while (n % 3 == 0)
	{
		n /= 3;
	}
	return n == 1;
	*/
}