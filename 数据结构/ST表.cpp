template<typename T>
struct RMQ {
    int n;
    vector<T> arr;
    vector<vector<T>> f, g;
    vector<int> lg2;

    void init() {
        for (int i = 0; i < n; i++) {
            f[i][0] = arr[i];
            g[i][0] = arr[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
                g[i][j] = min(g[i][j - 1], g[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    RMQ(const vector<T>& arr) :
            n(a.size()), arr(a),
            f(n, vector<T>(log2(n) + 1)),
            g(n, vector<T>(log2(n) + 1)),
            lg2(n + 1) {
        lg2[0] = -1;
        for(int i = 1; i <= n; i ++)
            lg2[i] = lg2[i >> 1] + 1;
        init();
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
