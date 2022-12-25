#pragma once
#include <iostream>
#include <vector>
#include <math.h>  // sqrt

// 实验一

class EXP01
{
public:
	void sort(std::vector<int>& nums, int start, int end);

	void test();

private:
	void merge(std::vector<int>& nums, int start, int end, int subs);
	
	const int inf = 0x3f3f3f3f;

};

