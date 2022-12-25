#include "HW_04.h"

using namespace std;

namespace hw04
{
	int question1()
	{
		int rows;
		cin >> rows; // 输入行数
		// triangle 用来保存三角形，ans 用来动态规划的填表
		vector<vector<int> > triangle(rows, vector<int>(rows)), ans(rows, vector<int>(rows));
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j <= i; ++j)
				cin >> triangle[i][j]; // 输入数字三角形状

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j <= i; ++j)
			{
				ans[i][j] += triangle[i][j];
				int x = i - 1, y1 = j - 1, y2 = j;
				if (x < 0)
					continue;
				if (y1 < 0)
					ans[i][j] = ans[x][y2] + triangle[i][j];
				else if (y2 == i)
					ans[i][j] = ans[x][y1] + triangle[i][j];
				else
					ans[i][j] = max(ans[x][y1], ans[x][y2]) + triangle[i][j];
			}
		int result = 0;
		for (int i = 0; i < rows; ++i) // 取最后一行中的最大值
			if (ans[rows - 1][i] > result)
				result = ans[rows - 1][i];
		return result;
	}

}

