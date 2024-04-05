#include <bits/stdc++.h>
using namespace std;

struct DIJ {
	using i64 = long long;
	using PII = pair<i64, i64>;
	vector<i64> dis;
	vector<vector<PII>> G;

	DIJ() {}
	DIJ(int n) {
		dis.assign(n + 1, 1e18);
		G.resize(n + 1);
	}

	void add(int u, int v, int w) {
		G[u].emplace_back(v, w);
	}

	void dijkstra(int s) {
		priority_queue<PII, vector<PII>, greater<PII>> que;
		// priority_queue<PII> que;
		dis[s] = 0;
		que.push({0, s});
		while (!que.empty()) {
			auto p = que.top();
			que.pop();
			int u = p.second;
			if (dis[u] < p.first) continue;
			for (auto [v, w] : G[u]) {
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
					que.push({dis[v], v});
				}
			}
		}
	}
};