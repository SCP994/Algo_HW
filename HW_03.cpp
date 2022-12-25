#include "HW_03.h"

using namespace std;

typedef pair<int, int> PII;

namespace hw03
{
	PII question1(vector<double>& nums, int p, int q) // 第一题 p、q 为数组下标，代表要计算最近点对的范围
	{
		if (q - p == 1) // 数组长度为 2 的情况
			return { p, q };
		if (q - p == 2) // 数组长度为 3 的情况
		{
			int right = nums[q] - nums[q - 1], left = nums[q - 1] - nums[p];
			if (right < left)
				return { q - 1, q };
			return { p, q - 1 };
		}

		int mid = p + q >> 1;
		PII left = question1(nums, p, mid), right = question1(nums, mid + 1, q); // 递归调用

		int leftValue = nums[left.second] - nums[left.first]; // 左边的最近点对距离
		int rightValue = nums[right.second] - nums[right.first]; // 右边的最近点对距离
		int midValue = nums[mid + 1] - nums[mid]; // 中间的情况

		if (leftValue < rightValue && leftValue < midValue)
			return left;
		if (rightValue < leftValue && rightValue < midValue)
			return right;
		return { mid, mid + 1 };
	}
	/* 时间复杂度分析
	* 递归方程为：T(n) = 2 T(n / 2) + C
	* 使用主定理，a = 2，b = 2，得出：T(n) = Θ(n)
	*/

	int question2(TreeNode* node) // 第二题
	{
		if (!node) // 空树
			return 0;
		if (!node->left && !node->right) // 单顶点树
			return 1;
		return max(question2(node->left), question2(node->right)) + 1; // 递归调用
	}
	/* 时间复杂度分析
	* 递归方程为：T(n) = 2 T(n / 2) + C，n 为树的节点数
	* 使用主定理，a = 2，b = 2，得出：T(n) = Θ(n)
	*/

	// 返回值为 pair，第一个值为众数，第二个值为重数
	PII question3(vector<int>& nums, int p, int q) // 第三题 假设数组 nums 是有重复元素的有序集合，p、q 为数组下标，代表判断众数的范围
	{
		if (p == q) // 只有一个元素的情况
			return { nums[p], 1 };

		int mid = p + q >> 1;
		PII left = question3(nums, p, mid), right = question3(nums, mid + 1, q); // 对左右两部分做递归调用
		int mid_mode = 0, mid_multi = 0; // 中间的众数和重数
		if (nums[mid] == nums[mid + 1]) // 只有左右相邻的值相等时才会考虑中间的情况
		{
			mid_mode = nums[mid];
			int left_multi = 0, right_multi = 0; // 中间的值在左右两边的重数
			int temp = mid;
			while (temp >= p && nums[temp] == mid_mode) // 计算中间的值在左边的重数
			{
				++left_multi;
				--temp;
			}
			temp = mid + 1;
			while (temp <= q && nums[temp] == mid_mode) // 计算中间的值在右边的重数
			{
				++right_multi;
				++temp;
			}
			mid_multi = left_multi + right_multi;
		}

		if (left.second > right.second && left.second > mid_multi)
			return left;
		if (right.second > left.second && right.second > mid_multi)
			return right;
		return { mid_mode, mid_multi };
	}

	void test3() // 第三题测试函数
	{
		vector<int> v = { 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 5, 6, 7, 7, 7, 7, 7, 8, 9 };
		PII p = question3(v, 0, v.size() - 1);
		cout << p.first << " " << p.second << endl;
	}

	vector<vector<int> > question4(vector<int>& nums, int p, int q) // 第四题 p、q 为数组下表，代表要排列的范围
	{
		vector<vector<int> > result;
		if (p == q) // 只有一个元素时，直接返回
		{
			result.push_back({ nums[p] });
			return result;
		}

		vector<vector<int> > result_before = question4(nums, p + 1, q); // 递归调用，返回的排列保存在二维数组中
		for (auto& i : result_before) // 遍历二维数组，得到每一个排列
			for (int j = 0; j < q - p + 1; ++j) // 将 nums[p] 元素分别插入每个排列的第 0 到第 q - p + 1 个位置
			{
				vector<int> temp(q - p + 1);
				temp[j] = nums[p];
				for (int k = 0, l = 0; k < q - p + 1 && l < q - p; ++k, ++l)
				{
					if (k == j)
					{
						--l;
						continue;
					}
					temp[k] = i[l];
				}
				result.push_back(temp); // 将新的排列保存起来
			}
		return result;
	}

	void test4() // 第四题测试函数
	{
		vector<int> v = { 1, 2, 3, 4 };
		vector<vector<int> > vv = question4(v, 0, v.size() - 1);
		for (auto& i : vv)
		{
			for (auto& j : i)
				cout << j << " ";
			cout << endl;
		}
	}

}

