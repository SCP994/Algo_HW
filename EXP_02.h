#pragma once
#include <iostream>
#include <vector>
#include <string>

// 实验二

class EXP02
{
public:
	int distance(std::string& strA, std::string& strB, int k);  // 求出字符串间的最短距离

	void printTable() const;  // 打印填好的表

	void getExtended() const;  // 求出扩展后的字符串 A 和字符串 B

	void test();  // 测试

private:
	std::string strA, strB;
	std::vector<std::vector<int> > table, memo;  // 用于动规的表格，table 记录最短距离，memo 记录方向

};

