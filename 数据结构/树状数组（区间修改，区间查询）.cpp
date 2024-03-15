template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT() {}
    void init(int N) {
        n = N;
        sum1.resize(n);
        sum2.resize(n);
    }
    void add(int x, T k) {
        for(int i = x; i < n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);

    }
};