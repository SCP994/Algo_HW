#include "EXP_05.h"

using namespace std;

namespace exp05
{
	vector<int> dist;  // 存储到各个顶点的最短路径距离
	const int inf = 0x3f3f3f3f;  // 代表无穷远的一个无穷大值

	void queue_array::insert(vector<int>& dist)
	{
		array = dist;  // 使用数组作为优先队列时，可直接将 dist 作为数组的初始化
		count = array.size();
	}

	void queue_array::decrease_key(int i, int key)
	{
		array[i] = key;
	}

	int queue_array::extract_min()
	{
		int ret = -1;
		int n = array.size();
		for (int i = 0; i < n; ++i)
		{
			if (array[i] == -1) continue;
			if (ret == -1 || array[i] < array[ret]) ret = i;
		}
		array[ret] = -1; // 将返回结点的最短距离置为 -1，相当于移出队列
		--count;
		return ret;
	}

	bool queue_array::empty()
	{
		return count == 0;
	}

	void queue_heap::insert(vector<int>& dist)
	{
		count = dist.size();
		heap = vector<pair<int, int> >(count + 1);
		idx = vector<int>(count);
		for (int i = 1; i <= count; ++i)  // 堆的下标从 1 开始
		{
			heap[i] = { i - 1, dist[i - 1] };  // 将结点下标及距离存入堆中
			idx[i - 1] = i;
		}
		for (int i = count >> 1; i; --i)
			min_heapify(i);
	}

	void queue_heap::decrease_key(int i, int key)
	{
		heap[idx[i]].second = key;
		while (i > 1 && heap[parent(i)].second > heap[i].second)
		{
			swap(heap[parent(i)], heap[i]);
			swap(idx[heap[parent(i)].first], idx[heap[i].first]);
			i = parent(i);
		}
	}

	int queue_heap::extract_min()
	{
		int ret = heap[1].first;
		swap(heap[1], heap[count]);
		swap(idx[heap[1].first], idx[heap[count].first]);
		--count;
		min_heapify(1);
		return ret;
	}

	bool queue_heap::empty()
	{
		return count == 0;
	}

	void queue_heap::min_heapify(int i)
	{
		int l = left(i), r = right(i), smallest = i;
		if (l <= count && heap[l].second < heap[smallest].second)
			smallest = l;
		if (r <= count && heap[r].second < heap[smallest].second)
			smallest = r;
		if (smallest != i)
		{
			swap(heap[smallest], heap[i]);
			swap(idx[heap[smallest].first], idx[heap[i].first]);
			min_heapify(smallest);
		}
	}

	inline int queue_heap::parent(int i)
	{
		return i >> 1;
	}

	inline int queue_heap::left(int i)
	{
		return i << 1;
	}

	inline int queue_heap::right(int i)
	{
		return (i << 1) + 1;
	}

	void initialize_single_source(vector<vector<pair<int, int> > >& graph, int source)
	{
		int n = graph.size();  // 结点数
		dist = vector<int>(n, inf);
		dist[source] = 0;  // 到自己的距离为 0
	}

	template <typename T>
	void relax(int u, int v, int w, T& Q)
	{
		if (dist[v] > dist[u] + w)
		{
			dist[v] = dist[u] + w;
			Q.decrease_key(v, dist[v]);
		}
	}

	template <typename T>
	void dijkstra(vector<vector<pair<int, int> > >& graph, int source)
	{
		initialize_single_source(graph, source);
		T Q;  // 优先队列
		Q.insert(dist);
		while (!Q.empty())
		{
			int u = Q.extract_min();
			for (auto it : graph[u])
			{
				auto& [v, w] = it;
				relax(u, v, w, Q);
			}
		}
	}

	void test()
	{
		vector<vector<pair<int, int> > > graph(5);
		graph[0].emplace_back(1, 3);
		graph[0].emplace_back(2, 5);
		graph[1].emplace_back(2, 2);
		graph[1].emplace_back(3, 6);
		graph[2].emplace_back(1, 1);
		graph[2].emplace_back(3, 4);
		graph[2].emplace_back(4, 6);
		graph[3].emplace_back(4, 2);
		graph[4].emplace_back(0, 3);
		graph[4].emplace_back(3, 7);

		dijkstra<queue_array>(graph, 0);

		for (auto it : dist)
			cout << it << " ";
		cout << endl;

		dijkstra<queue_array>(graph, 2);

		for (auto it : dist)
			cout << it << " ";
		cout << endl;

		dijkstra<queue_array>(graph, 4);

		for (auto it : dist)
			cout << it << " ";
		cout << endl;

		dijkstra<queue_heap>(graph, 0);

		for (auto it : dist)
			cout << it << " ";
		cout << endl;

		dijkstra<queue_heap>(graph, 2);

		for (auto it : dist)
			cout << it << " ";
		cout << endl;

		dijkstra<queue_heap>(graph, 4);

		for (auto it : dist)
			cout << it << " ";
		cout << endl;
	}

}

