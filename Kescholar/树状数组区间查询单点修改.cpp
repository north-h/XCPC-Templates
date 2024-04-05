#include <bits/stdc++.h>
#define debug(a) cout<<#a<<"="<<a<<'\n';
 
using namespace std;
using i64 = long long;
 
typedef pair<i64, i64> PII;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int n, m;
	cin >> n >> m;
	vector<int> h1(n + 1), a(n + 1), h2(n + 1);
 
#ifndef lowbit
#define lowbit(x) (x & (-x))
#endif
 
	auto updata = [&](int x, int val) {
		while (x <= n) {
			h1[x] = h2[x] = val;
			int lx = lowbit(x);
			for (int i = 1; i < lx; i <<= 1) {
				h1[x] = max(h1[x], h1[x - i]);
				h2[x] = min(h2[x], h2[x - i]);
			}
			x += lowbit(x);
		}
	};
 
	auto RMQ = [&](int l, int r) {
		int x = 0, y = a[l];
		while (l <= r) {
			x = max(x, a[r]);
			y = min(y, a[r]);
			r --;
			for (; r - lowbit(r) >= l; r -= lowbit(r)) {
				x = max(x, h1[r]);
				y = min(y, h2[r]);
			}
		}
		return x - y;
	};
 
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		updata(i, a[i]);
	}
 
	while (m --) {
		int l, r, op;
		cin >> op;
		if (op) {
			cin >> l >> r;
			cout << RMQ(l, r) << '\n';
 
		} else {
			int y, x;
			cin >> y >> x;
			a[y] = x;
			updata(y, x);
		}
	}
 
 
	return 0;
}