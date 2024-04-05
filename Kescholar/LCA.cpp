include <bits/stdc++.h>
using namespace std;
 
struct LCA {
	int n;
	vector<int> dep;
	vector<vector<int>> e;
	vector<array<int, 21>> fa;
	LCA() {}
	LCA(int n) {
		dep.resize(n + 1);
		e.resize(n + 1);
		fa.resize(n + 1);
	}
 
	void add(int u, int v) {
		e[u].push_back(v);
		e[v].push_back(u);
	}
 
	//计算深度,处理各点祖先
	void dfs(int u, int father) {
		dep[u] = dep[father] + 1;
 
		fa[u][0] = father;
		for (int i = 1; i < 20; i ++)
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
 
		for (auto v : e[u])
			if (v != father)
				dfs(v, u);
	}
 
	//最近公共祖先
	//两点集并的最近公共祖先为两点几分别的最近公共祖先的最近公共祖先,
	//即LCA(A∪B) = LCA(LCA(A), LCA(B));
	int lca(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		for (int i = 19; i >= 0; i --)
			if (dep[fa[u][i]] >= dep[v])
				u = fa[u][i];
 
		if (u == v) return v;
 
		for (int i = 19; i >= 0; i --)
			if (fa[u][i] != fa[v][i])
				u = fa[u][i], v = fa[v][i];
		return fa[u][0];
	}
 
	//d(u,v) = h(u) + h(v) - 2h(LCA(u,v));
	//其中d是树上两点间的距离,h代表某点到树根的距离
	int get_dis(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}
};
 