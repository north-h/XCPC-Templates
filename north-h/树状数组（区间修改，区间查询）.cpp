<<<<<<< HEAD
template <class T>
struct BIT {
    vector<T> sum1, sum2;
    int n;
    BIT(int n) : n(n), sum1(n + 1), sum2(n + 1) {}
    void add(int x, T k) {
        for(int i = x; i <= n; i += (i & -i))
            sum1[i] += k, sum2[i] += x * k;
    }
    void range_add(int l, int r, T x) {
        add(l, x), add(r + 1, -x);
    }
    T query(int x) {
        T res = 0;
        for(int i = x; i > 0; i -= (i & -i))
            res += (x + 1) * sum1[i] - sum2[i];
        return res;
    }
    T range_query(int l, int r) {
        return query(r) - query(l - 1);

    }
};
=======
const int N = 100010;

int lowbit(int x) {
    return x & (-x);
}

int sum1[N], sum2[N];

void add(int x, int k) {
    for(int i = x; i < N; i += lowbit(i))
        sum1[i] += k, sum2[i] += x * k;
}

void range_add(int l, int r, int x) {
    add(l, x), add(r + 1, -x);
}

int query(int x) {
    int res = 0;
    for(int i = x; i; i -= i & -i)
        res += (x + 1) * sum1[i] - sum2[i];
    return res;
}

int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

// 建树，使用差分数组
for(int i = 1; i <= n; i++)cin >> a[i];
for(int i = 1; i <= n; i++) {
    b[i] = a[i] - a[i - 1];
    add(i, b[i]);
}
>>>>>>> 9ca82162df6414bd2ad8fc3505eb4543917b1398
