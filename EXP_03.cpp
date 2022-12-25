#include "EXP_03.h"

using namespace std;

EXP03::~EXP03()
{
	if (head) deleteRecursively(head);
}

void EXP03::merge(int* lens, int n)
{
	TreeNode** ret = (TreeNode**)malloc(sizeof(TreeNode*) * n);  // 指针数组
	for (int i = 0; i < n; ++i)
	{
		ret[i] = (TreeNode*)malloc(sizeof(TreeNode));
		ret[i]->val = lens[i];
		ret[i]->left = nullptr;
		ret[i]->right = nullptr;
	}

	while (true)
	{
		int idx1 = -1, idx2 = -1;  // idx1 代表最小的，idx2代表次小的
		for (int i = 0; i < n; ++i)
			if (ret[i] != nullptr)
			{
				if (idx1 == -1)
					idx1 = i;
				else if (ret[i]->val <= ret[idx1]->val)
				{
					idx2 = idx1;
					idx1 = i;
				}
				else if (idx2 == -1 || ret[i]->val <= ret[idx2]->val)
					idx2 = i;
			}
		if (idx2 == -1)
		{
			head = ret[idx1];
			break;
		}
		int left = ret[idx1]->val, right = ret[idx2]->val;
		TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
		temp->val = left + right;
		temp->left = ret[idx1];
		temp->right = ret[idx2];
		ret[idx1] = temp;
		ret[idx2] = nullptr;
	}
}

void EXP03::printResult()
{
	if (!head) throw;
	deque<TreeNode*> q;
	q.emplace_back(head);
	q.emplace_back(nullptr);

	while (true)
	{
		TreeNode* temp = q.front();
		cout << temp->val << " ";
		q.pop_front();
		if (temp->left) q.emplace_back(temp->left);
		if (temp->right) q.emplace_back(temp->right);
		if (q.front() == nullptr)
		{
			q.pop_front();
			cout << endl;
			if (q.empty()) break;
			q.emplace_back(nullptr);
		}
	}
}

void EXP03::deleteRecursively(TreeNode* node)
{
	if (node->left) deleteRecursively(node->left);
	if (node->right) deleteRecursively(node->right);
	free(node);
	node = nullptr;
}

