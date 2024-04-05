struct DIJ {
    using i64 = long long;
    using PII = pair<i64, i64>;
    vector<i64> dis, path, node;
    vector<vector<array<int, 3>>> G;
    int n;
 
    DIJ() {}
    DIJ(int n): n(n) {
        node.resize(n + 1, 1);
        dis.assign(n + 1, 1e18);
        G.resize(n + 1);
        path.resize(n + 1, -1);
    }
	//val为权重值,要求最短路径结点数最小时即为1
    void add(int u, int v, int w, int val) {
        G[u].push_back({v, w, val});
    }
 
    void dijkstra(int s) {
        priority_queue<PII> que;
        dis[s] = 0;
        que.push({0, s});
        while (!que.empty()) {
            auto p = que.top();
            que.pop();
            int u = p.second;
            if (dis[u] < p.first) continue;
            for (auto [v, w, val] : G[u]) {
                if (dis[v] > dis[u] + w) {
                    node[v] = node[u] + val;
                    dis[v] = dis[u] + w;
                    que.push({ -dis[v], v});
                    path[v] = u;
                } else if (dis[v] == dis[u] + w) {
                    if (node[v] > node[u] + val) {
                        node[v] = node[u] + val;
                        path[v] = u;
                    }
                }
            }
        }
    }
};