#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <queue>

// 课堂作业六

class HW06
{
public:
	void dijkstra(std::vector<std::vector<std::pair<int, int> > >& graph, int source);  // Dijkstra 算法

	std::vector<int> return_dis() const;  // 返回计算好的到各个结点的最短距离

	std::vector<int> return_prefix() const;  // 返回计算好的各个结点的前驱结点

	void test();

private:
	void initialize_single_source(std::vector<std::vector<std::pair<int, int> > >& graph, int source);  // 对最短路径估计和前驱结点进行初始化

	void relax(int u, int v, int w);  // 松弛操作

	const int inf = 0x3f3f3f3f;  // 代表无穷大的距离
	int num;  // 结点数量
	int N;  // 定义边权重的范围，权重最大为 N - 1
	std::vector<int> prefix;  // 保存前驱结点
	std::vector<std::pair<int, std::list<int>::iterator> > dist;  // 保存最短路径估计，pair 中第二个值用来保存指针
	std::list<int>* bucket;  // 类似于桶排序的思想，存储当前距离下的结点

};

