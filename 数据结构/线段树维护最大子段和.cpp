template <class T>
struct Seg {
    struct Node { int l, r; T lazy, mx, lmx, rmx, sum; };
    vector<Node> tr; vector<T> a; int n;
    Seg(int n) { n = N + 1; tr.resize(n * 4); a.resize(n); }
    void pushup(int u) {
        tr[u] = merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }
    Node merge(Node t, Node l, Node r) {
        t.lmx = max(l.lmx, l.sum + r.lmx);
        t.rmx = max(r.rmx, r.sum + l.rmx);
        t.sum = l.sum + r.sum;
        t.mx = max(max(l.mx, r.mx), l.rmx + r.lmx);
        return t;
    }
    void pushdown(int u) {
        if (tr[u].lazy) {
            tr[u << 1].lazy = tr[u].lazy;
            tr[u << 1 | 1].lazy = tr[u].lazy;
            tr[u].lazy = 0;
        }
    }
    void build(int u, int l, int r) {
        tr[u] = {l, r, 0, a[l], a[l], a[l], a[l]};
        if (l == r) return;
        int mid = l + r >> 1;
        pushdown(u);
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
    void modify(int u, int l, int r, T k) {
        if (tr[u].l >= l && tr[u].r <= r) {
            tr[u].lazy = k;
            tr[u].mx = tr[u].lmx = tr[u].rmx = tr[u].sum = k;
            return;
        }
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
    Node query(int u, int l, int r) {
        // debug1(u);
        if (tr[u].l >= l && tr[u].r <= r) return tr[u];
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        Node t = merge(t, query(u << 1, l, r), query(u << 1 | 1, l, r));
        return t;
    }
};