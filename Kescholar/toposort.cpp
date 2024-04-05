#include <bits/stdc++.h>
using namespace std;

struct toposort {
	vector<vector<int>> e;
	vector<int> tp , din;
	int n ;

	toposort() {}
	toposort(int n) {
		this->n = n;
		din.resize(n + 1);
		e.resize(n + 1);
	}

	void add(int u, int v) {
		e[u].push_back(v);
		din[v] ++;
	}

	// Kahn(卡恩算法)判环
	bool topo() {
		queue<int> Q;
		for (int i = 1; i <= n; i ++)
			if (!din[i]) Q.push(i);
		while (Q.size()) {
			auto u = Q.front();
			Q.pop();
			tp.push_back(u);
			for (auto v : e[u])
				if (!--din[v])
					Q.push(v);
		}
		return tp.size() == n;
	}

};