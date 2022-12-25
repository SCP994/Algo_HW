#pragma once
#include <iostream>
#include <deque>

// 实验三

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

class EXP03
{
public:
	~EXP03();

	void merge(int* lens, int n);

	void printResult();

private:
	TreeNode* head = nullptr;

	void deleteRecursively(TreeNode* node);  // 递归释放内存空间

};

