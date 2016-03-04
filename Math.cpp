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

// ����һ���������ж����Ƿ�Ϊ3�ĳ˷��������������κ�ѭ���͵ݹ�
// �㷨��
// 1. 3^19 = 1162261467, 32ϵͳ�� 3^20 ���� int��
// 2. ��[3^0, 3^1, ..., 3^19]���ң�
// 3. �ж����Ƿ�Ϊ������
// 4. ������ O(log(n)) time
bool Math::isPowerOfThree(int n) {
	// ��1
	return (n > 0 && 1162261467 % n == 0);

	/*
	// ��2: O(1) time
	int range[] = { 1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467 };
	for (int i = 0; i < 20; i++) {
	if (n == range[i]) return true;
	}
	return false;

	// ��3
	return fmod(log10(n) / log10(3), 1) == 0; // fmod ������ȡģ

	// ��4
	if (n < 0) return false;
	while (n % 3 == 0)
	{
		n /= 3;
	}
	return n == 1;
	*/
}