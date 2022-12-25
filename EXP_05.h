#pragma once
#include <iostream>
#include <vector>

// 实验五

namespace exp05
{
	class queue_array  // 使用数组实现最小优先队列
	{
	public:
		void insert(std::vector<int>& dist);

		void decrease_key(int i, int key);

		int extract_min();

		bool empty();

	private:
		std::vector<int> array;
		int count;

	};

	class queue_heap  // 使用最小堆实现最小优先队列
	{
	public:
		void insert(std::vector<int>& dist);  // 建堆

		void decrease_key(int i, int key);

		int extract_min();

		bool empty();

		void min_heapify(int i);  // 维护最小堆的性质

		inline int parent(int i);

		inline int left(int i);

		inline int right(int i);

	private:
		std::vector<std::pair<int, int> > heap;  // 存储结点及其距离，根据距离构建二叉堆
		std::vector<int> idx;  // 用于保存每个结点目前对应的堆的下标
		int count;

	};

	void initialize_single_source(std::vector<std::vector<std::pair<int, int> > >& graph, int source);  // 对最短路径估计和前驱节点进行初始化
	
	template <typename T>
	void relax(int u, int v, int w, T& Q);  // 松弛操作

	template <typename T>
	void dijkstra(std::vector<std::vector<std::pair<int, int> > >& graph, int source);  // Dijkstra 算法

	void test();

}

