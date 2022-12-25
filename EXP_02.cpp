#include "EXP_02.h"

using namespace std;

int EXP02::distance(string& strA, string& strB, int k)
{
	int lenA = strA.size(), lenB = strB.size();
	this->strA = strA;
	this->strB = strB;
	table = vector(lenA + 1, vector<int>(lenB + 1, 0));  // 记录子串的最短距离
	memo = vector(lenA + 1, vector<int>(lenB + 1, 0));  // 记录方向，后续可通过此表写出扩展后的字符串

	for (int i = 1; i <= lenA; ++i)  // 将字符串 B 为空的情况下字符串 A 的子串的最短距离填入表中
	{
		int t = ((strA[i - 1] == '\x20') ? 0 : k);  // 判断是否等于空格，等于空格则为 0
		table[i][0] = table[i - 1][0] + t;
		memo[i][0] = 1;  // memo 记录方向，1 为上，2 为左，3 为左上
	}
	for (int i = 1; i <= lenB; ++i)  // 将字符串 A 为空的情况下字符串 B 的子串的最短距离填入表中
	{
		int t = ((strB[i - 1] == '\x20') ? 0 : k);
		table[0][i] = table[0][i - 1] + t;
		memo[0][i] = 2;
	}

	for (int i = 1; i <= lenA; ++i)  // 填表
	{
		for (int j = 1; j <= lenB; ++j)
		{
			int a = table[i - 1][j] + k, b = table[i][j - 1] + k;  // 对应于递归表达式中 val(i - 1, j) + k 和 val(i, j - 1) + k 的情况

			int sub = abs(strA[i - 1] - strB[j - 1]);
			if (strA[i - 1] != strB[j - 1] && (strA[i - 1] == '\x20' || strB[j - 1] == '\x20'))
				sub = k;  // a[i] 和 b[j] 不相等时，有一个为空格，则距离为 k，注意 i，j 从 1 开始，故这里是 strA[i - 1]，strB[j - 1]
			int c = table[i - 1][j - 1] + sub;  // 对应于递归表达式中 val(i - 1, j - 1) + dist(a[i], b[j]) 的情况

			int smallest = a;
			int orientation = 1;  // 记录方向的变量
			if (b < smallest)
			{
				smallest = b;
				orientation = 2;
			}
			if (c < smallest)
			{
				smallest = c;
				orientation = 3;
			}

			table[i][j] = smallest;  // 填表
			memo[i][j] = orientation;
		}
	}

	return table[lenA][lenB];  // 表格中最后一个值即最短距离
}

void EXP02::printTable() const  // 打印表格
{
	cout << "table:" << endl;
	for (const auto& i : table)
	{
		for (const auto& j : i)
			cout << j << " ";
		cout << endl;
	}
	cout << "memo:" << endl;
	for (const auto& i : memo)
	{
		for (const auto& j : i)
			cout << j << " ";
		cout << endl;
	}
}

void EXP02::getExtended() const  // 打印扩展后的字符串
{
	int lenA = strA.size(), lenB = strB.size();
	string extendedA, extendedB;

	int i = lenA, j = lenB;
	while (i || j)
		switch (memo[i][j])
		{
		case 1:
			extendedA += strA[i - 1];
			extendedB += '\x5F';  // 为了方便，打印时将空格改为下划线
			--i;
			break;
		case 2:
			extendedA += '\x5F';
			extendedB += strB[j - 1];
			--j;
			break;
		case 3:
			extendedA += strA[i - 1];
			extendedB += strB[j - 1];
			--i;
			--j;
			break;
		default:
			break;
		}

	reverse(extendedA.begin(), extendedA.end());  // 还需要再逆转一下才是扩展之后的字符串
	reverse(extendedB.begin(), extendedB.end());
	cout << "Extended strA: " << extendedA << endl;
	cout << "Extended strB: " << extendedB << endl;
}

void EXP02::test()
{
	string strA = "cnc", strB = "snmn";  // 测试用例 1
	int k = 2;
	cout << distance(strA, strB, k) << endl;
	printTable();
	getExtended();
	cout << endl;

	strA = "abcdef";  // 测试用例 2
	strB = "bcdefg";
	k = 2;
	cout << distance(strA, strB, k) << endl;
	printTable();
	getExtended();
	cout << endl;

	k = 5;
	cout << distance(strA, strB, k) << endl;
	printTable();
	getExtended();
	cout << endl;

	strA = "njvsidjfsl";  // 测试用例 3
	strB = "mogudljfsvoiflj";
	k = 3;
	cout << distance(strA, strB, k) << endl;
	printTable();
	getExtended();
	cout << endl;
}

