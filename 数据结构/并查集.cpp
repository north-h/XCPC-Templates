struct DSU {
    vector<int> fa;
 
    DSU(int n) {
        fa.resize(n + 1);
        for (int i = 1; i <= n; i ++) fa[i] = i;
    }
 
    int find(int x) {
        if (fa[x] != x) fa[x] = find(fa[x]);
        return fa[x];
    }
 
    bool same(int x, int y) {
        int px = find(x);
        int py = find(y);
        return x == y;
    }
 
    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py) {
            fa[px] = py;
        }
    }
};