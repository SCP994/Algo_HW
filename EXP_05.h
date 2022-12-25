#pragma once
#include <iostream>
#include <vector>

// ʵ����

namespace exp05
{
	class queue_array  // ʹ������ʵ����С���ȶ���
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

	class queue_heap  // ʹ����С��ʵ����С���ȶ���
	{
	public:
		void insert(std::vector<int>& dist);  // ����

		void decrease_key(int i, int key);

		int extract_min();

		bool empty();

		void min_heapify(int i);  // ά����С�ѵ�����

		inline int parent(int i);

		inline int left(int i);

		inline int right(int i);

	private:
		std::vector<std::pair<int, int> > heap;  // �洢��㼰����룬���ݾ��빹�������
		std::vector<int> idx;  // ���ڱ���ÿ�����Ŀǰ��Ӧ�Ķѵ��±�
		int count;

	};

	void initialize_single_source(std::vector<std::vector<std::pair<int, int> > >& graph, int source);  // �����·�����ƺ�ǰ���ڵ���г�ʼ��
	
	template <typename T>
	void relax(int u, int v, int w, T& Q);  // �ɳڲ���

	template <typename T>
	void dijkstra(std::vector<std::vector<std::pair<int, int> > >& graph, int source);  // Dijkstra �㷨

	void test();

}

