#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

// 实验四

namespace exp04
{
	std::pair<int, int> findMaximums(std::vector<int> v, int start, int end);  // 求数组中最大的两个数，返回的 pair 中第一个数为最大数，第二个数为次大数

	void test();  // 测试函数

}

