const int N = 100010；

struct Node {
    int l, r, sum;
} tr[N * 4];

int a[N];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r) {
    tr[u] = {l, r, a[l], 0};
    if (l == r)return;
    int mid = l + r >> 1;
    pushdown(u);
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}
//单点修改
void modify(int u, int x, int k) {
    if (tr[u].l == tr[u].r) {
        tr[u].sum += k;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (x <= mid)modify(u << 1, x, k);
    else modify(u << 1 | 1, x, k);
}
//区间查询
int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int sum = 0;
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)sum += query(u << 1, l, r);
    if (r > mid) sum += query(u << 1 | 1, l, r);
    return sum;
}