#include <bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<'\n';
 
using namespace std;
using i64 = long long;
 
typedef pair<i64, i64> PII;

//prim适合稠密图，Kruskal适合稀疏图
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, m;
	cin >> n >> m;
	vector g(n + 1, vector<PII>());
	vector<int> dis(n + 1);
	vector<bool> vis(n + 1);
	i64 ans = 0, cnt = 0;
	for (int i = 0; i < m; i ++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
 
	priority_queue<PII, vector<PII>, greater<PII>> Q;
	Q.push({0, 1});
	while (Q.size()) {
		auto [w, u] = Q.top();
		Q.pop();
 
		if (vis[u]) continue;
		vis[u] = true;
		ans += w;
		cnt ++;
		dis[u] = w;
		for (auto [v, d] : g[u]) {
			if (!vis[v]) {
				Q.push({d, v});
			}
		}
	}
 
	if (cnt != n) {
		cout << "orz\n";
	} else
		cout << ans << '\n';
    
	return 0;
}