#pragma once
#include <stdint.h>
class Math
{
public:
	Math();
	~Math();
	int hammingWeight(uint32_t n); // #191
	bool isPowerOfTwo(int n); // #231
	bool isPowerOfThree(int n); // #326
};

