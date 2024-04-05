template<typename T>
struct BIT {
#ifndef lowbit
#define lowbit(x) (x & (-x));
#endif
	// static const int maxn = 5e5 + 50;
	int n;
	vector<T> t;

	BIT () {}
	BIT (int _n): n(_n) { t.resize(_n + 1); }
	BIT (int _n, vector<T>& a): n(_n) {
		t.resize(_n + 1);
		for (int i = 1; i <= n; ++ i) {
			t[i] += a[i];
			int j = i + lowbit(i);
			if (j <= n) t[j] += t[i];
		}
	}
	//单点修改
	void update(int i, T x) {
		while (i <= n) {
			t[i] += x;
			i += lowbit(i);
		}
	}
	//区间查询
	T sum(int i) {
		T ans = 0;
		while (i > 0) {
			ans += t[i];
			i -= lowbit(i);
		}
		return ans;
	}

	T query(int i, int j) {
		return sum(j) - sum(i - 1);
	}
	//区间修改则存入差分数组,[l, r] + k则update(x,k),update(y+1,-k)
	//单点查询则直接求前缀和sum(x)
};