template<class T>
struct ST {
    T n;
    vector<vector<T>> f, g;
    vector<int> lg2;
    ST(const vector<T> &a) {
        n = (int)a.size();
        lg2.resize(n + 1);
        lg2[0] = -1;
        for(int i = 1; i <= n; i ++) {
            lg2[i] = lg2[i >> 1] + 1;
        }
        f.resize(n + 1, vector<T>(lg2[n] + 1));
        g.resize(n + 1, vector<T>(lg2[n] + 1));
        for (int i = 1; i <= n; i++) {
            f[i][0] = a[i];
            g[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query_max(int l, int r) {
        int k = lg2[r - l + 1];
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    }

    T query_min(int l, int r) {
        int k = lg2[r - l + 1];
        return min(g[l][k], g[r - (1 << k) + 1][k]);
    }
};