#include "HW_06.h"

using namespace std;

void HW06::dijkstra(vector<vector<pair<int, int> > >& graph, int source)
{
	initialize_single_source(graph, source);

	int idx = 0;
	while (true)
	{
		while (bucket[idx].size() == 0 && idx < N * num) ++idx;
		if (idx == N * num) break;  // 遍历完所有桶即可退出

		int u = bucket[idx].front();  // 找到目前有最短距离的结点
		bucket[idx].pop_front();

		for (const auto& it : graph[u])
		{
			auto& [v, w] = it;
			relax(u, v, w);  // 松弛操作，比平常的松弛操作多了几个步骤
		}
	}
}

vector<int> HW06::return_dis() const
{
	vector<int> dis(num);
	for (int i = 0; i < num; ++i)
		dis[i] = dist[i].first;
	return dis;
}

vector<int> HW06::return_prefix() const
{
	return prefix;
}

void HW06::test()
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

	HW06 d;
	d.dijkstra(graph, 0);
	vector<int> dis = d.return_dis();
	for (const auto& item : dis)
		cout << item << " ";
	cout << endl;

	d.dijkstra(graph, 2);
	dis = d.return_dis();
	for (const auto& item : dis)
		cout << item << " ";
	cout << endl;

	d.dijkstra(graph, 4);
	dis = d.return_dis();
	for (const auto& item : dis)
		cout << item << " ";
	cout << endl;
}

void HW06::initialize_single_source(vector<vector<pair<int, int> > >& graph, int source)
{
	num = graph.size();  // 结点数量
	
	N = 0;
	for (int i = 0; i < num; ++i)
		for (const auto& item : graph[i])
			N = max(N, item.second);  // 找到最大的边权
	++N;  // 将 N 设为最大边权值加一

	dist = vector<pair<int, list<int>::iterator> >(num);
	for (auto& it : dist)
		it.first = inf;
	dist[source].first = 0;  // 将到源结点的距离设为 0

	prefix = vector<int>(num, -1);  // 用 -1 表示还没有前驱结点

	bucket = new list<int>[N * num + 1];  // 最大距离为 (N - 1) * (num - 1)，这里为了简便
	bucket[0].push_back(source);  // 第一个桶里装入源结点
}

void HW06::relax(int u, int v, int w)
{
	int du = dist[u].first;
	int dv = dist[v].first;
	if (dv > du + w)
	{
		if (dv != inf) bucket[dv].erase(dist[v].second);  // 更新 v 的最短距离，要先将其原来的最短距离抹除

		dv = du + w;
		dist[v].first = dv;
		prefix[v] = u;

		bucket[dv].push_front(v);  // 插入新的最短距离
		dist[v].second = bucket[dv].begin();  // 存入指针，方便后续抹除时可以做到 O(1) 时间复杂度
	}
}

