#include "EXP_01.h"

using namespace std;

void EXP01::sort(vector<int>& nums, int start, int end)
{
	int len = end - start + 1, subs = sqrt(len);
	if (subs == 1)
	{
		if (len == 2 && nums[start] > nums[end]) swap(nums[start], nums[end]);
		if (len == 3)
		{
			if (nums[start] > nums[start + 1]) swap(nums[start], nums[start + 1]);
			if (nums[start + 1] > nums[end]) swap(nums[start + 1], nums[end]);
			if (nums[start] > nums[start + 1]) swap(nums[start], nums[start + 1]);
		}
	}
	else
	{
		for (int i = 0; i < subs; ++i)
		{
			int s = start + i * subs, e = (i == subs - 1) ? end : s + subs - 1;
			sort(nums, s, e);
		}
		merge(nums, start, end, subs);
	}
}

void EXP01::test()
{
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	vector<int> nums1(100);
	for (int i = 0; i < 100; ++i)
	{
		nums1[i] = rand() % 1000;
		if (rand() % 2 == 0)
			nums1[i] = -nums1[i];
	}

	sort(nums1, 0, nums1.size() - 1);
	for (auto& i : nums1)
		cout << i << " ";
	cout << endl;
}

void EXP01::merge(vector<int>& nums, int start, int end, int subs)  // subs 为长度的开平方
{
	vector<int> temp(end - start + 1);  // 先将合并后的数存入这个数组中
	vector<int> idx(subs);  // 每个子区间对应一个索引
	for (int i = 0; i < subs; ++i)
		idx[i] = start + i * subs;
	for (int i = start; i <= end; ++i)
	{
		int min = inf, temp_idx = 0;  // inf 为 0x3f3f3f3f，即一个无穷大的数
		for (int j = 0; j < subs; ++j)
		{  // 当每个区间对应的索引到达相应区间的末尾时 continue 跳过，注意最后一个区间的长度很有可能大于其他区间的长度
			if ((idx[j] - start - j * subs) == subs && j != subs - 1 || idx[j] == end + 1) continue;
			if (min > nums[idx[j]])
			{
				min = nums[idx[j]];
				temp_idx = j;
			}
		}
		++idx[temp_idx];
		temp[i - start] = min;
	}
	for (int i = start; i <= end; ++i)
		nums[i] = temp[i - start];  // 将合并好的数存回原数组
}

