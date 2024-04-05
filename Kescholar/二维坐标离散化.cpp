struct Two_D_Discrete {
	int n, tot1 = 1, tot2 = 1;
	vector<vector<int>> mp;
	vector<int> x, y, nx, ny;
	vector<pair<i64, i64>> a;
	vector<PII> New;

	Two_D_Discrete (int _n, vector<pair<i64, i64>>& _a): n(_n), a(_a) {
		x.resize(n), y.resize(n);
		nx.resize(n * 2 + 5), ny.resize(n * 2 + 5);
		vector<vector<int>>(n * 2 + 5, vector<int>(n * 2 + 5)).swap(mp);
		for (int i = 0; i < n; i ++) {
			x[i] = a[i].first;
			y[i] = a[i].second;
		}
	}

	void work() {
		//排序
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		// 去重 并得到有多少个点
		int len1 = unique(x.begin(), x.end()) - x.begin();
		int len2 = unique(y.begin(), y.end()) - y.begin();
		// 离散化 x 轴
		for (int i = 0; i < len1; i++) {
			if (i && x[i] != x[i - 1] + 1)
				nx[tot1++] = x[i] - 1, nx[tot1++] = x[i];
			else
				nx[tot1++] = x[i];
		}
		// 离散化 y 轴
		for (int i = 0; i < len2; i++) {
			if (i && y[i] != y[i - 1] + 1)
				ny[tot2++] = y[i] - 1, ny[tot2++] = y[i];
			else
				ny[tot2++] = y[i];
		}
		//映射关系将需离散的点放入离散图中
		for (int i = 0; i < n; i++) {
			int newx = lower_bound(nx.begin(), nx.begin() + tot1, a[i].first) - nx.begin();
			int newy = lower_bound(ny.begin(), ny.begin() + tot2, a[i].second) - ny.begin();
			mp[newx][newy] = 1;
			// cout << "(" << newx << ',' << newy << ")\n";
			New.emplace_back(newx, newy);
		}
	}
};