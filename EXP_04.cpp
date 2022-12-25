#include "EXP_04.h"

using namespace std;

typedef pair<int, int> PII;

namespace exp04
{
	PII findMaximums(vector<int> v, int start, int end)
	{
		if (start == end) throw; // 长度为 1 则报错
		if (start == end - 1)  // 长度为 2 的情况
		{
			if (v[start] > v[end])
				return { v[start], v[end] };
			return { v[end], v[start] };
		}

		int mid = (start + end) >> 1;  // 取中值
		PII left = findMaximums(v, start, mid);  // 对左边递归调用
		if (mid + 1 == end)  // 长度为 3 的情况
		{
			if (v[end] > left.first)
				return { v[end], left.first };
			if (v[end] > left.second)
				return { left.first, v[end] };
			return left;
		}

		PII right = findMaximums(v, mid + 1, end);  // 对右边递归调用
		if (left.first < right.first)
		{
			if (right.second > left.first)
				return right;
			return { right.first, left.first };
		}
		if (left.second > right.first)
			return left;
		return { left.first, right.first };
	}

	void test()
	{
		srand((int)time(0));  // 产生随机种子  把0换成NULL也行
		vector<int> nums(10000);
		for (int i = 0; i < nums.size(); ++i)
		{
			nums[i] = rand() % 10000;
			if (rand() % 2 == 0)
				nums[i] = -nums[i];
		}

		PII ret = findMaximums(nums, 0, nums.size() - 1);

		cout << ret.first << " " << ret.second << endl << endl;

		sort(nums.begin(), nums.end(), greater<int>());
		for (const auto& i : nums)
			cout << i << " ";
	}

}

