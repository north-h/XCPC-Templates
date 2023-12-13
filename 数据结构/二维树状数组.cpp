template <class T>
struct BIT_2D {
    vector<vector<T>> tr;
    int n, m;
    
    BIT_2D(int n, int m) : n(n), m(m), tr(n + 1, vector<T>(m + 1)) {}
    
    int lowbit(int x) { return x & (-x); }
    
    void add(int x, int y, T k) {
        for (int i = x; i <= n; i += lowbit(i))
            for (int j = y; j <= m; j += lowbit(j))
                tr[i][j] += k;
    }
    
    T query(int x, int y) {
        T res = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                res += tr[i][j];
        return res;
    }
    
    T query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
    }
};
