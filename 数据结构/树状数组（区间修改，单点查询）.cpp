template <class T>
struct BIT {
    vector<T> tr;
    int n;
    BIT(int N) { 
        n = N;
        tr.resize(n + 1); 
    }
    void add(int x, T k) {
        for(int i = x; i < n; i += (i & -i))
            tr[i] += k;
    }
    void range_add(int l, int r) {
        add(l, k);
        add(r + 1, -k);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i; i -= (i & -i))
            res += tr[i];
        return res;
    }
};