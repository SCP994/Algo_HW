#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <stack>

// 课堂作业三

namespace hw03
{
	std::pair<int, int> question1(std::vector<double>& nums, int p, int q); // 第一题 p、q 为数组下标，代表要计算最近点对的范围

	typedef struct TreeNode
	{
		TreeNode* left, * right;
		int value;
	} TreeNode;

	int question2(TreeNode* node); // 第二题

	std::pair<int, int> question3(std::vector<int>& nums, int p, int q); // 第三题 假设数组 nums 是有重复元素的有序集合，p、q 为数组下标，代表判断众数的范围

	void test3(); // 第三题测试函数

	std::vector<std::vector<int> > question4(std::vector<int>& nums, int p, int q); // 第四题 p、q 为数组下表，代表要排列的范围

	void test4(); // 第四题测试函数

}

