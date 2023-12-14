template <class T, int P, int mod>
struct Palin {
    vector<T> pre, suf, p;
    string str = "$#";
    T n;
    Palin(const string &s) {
        for(auto i : s) {
            str += i;
            str += '#';
        }
        n = (int)str.size() - 1;
        // pre((s.size() + 1) * 2),
        // suf((s.size() + 1) * 2),
        // p((s.size() + 1) * 2)
        pre(n + 1), suf(n + 1), p(n + 1);
        p[0] = 1;
        for(int i = 1, j = n; i <= n; i++, j--) {
            pre[i] = (pre[i - 1] * P % mod  + str[i]) % mod;
            suf[i] = (suf[i - 1] * P % mod + str[j]) % mod;
            p[i] = p[i - 1] * P % mod;
        }

    }

    T get(T h[], int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }

    bool query(int l, int r) {
        T x = get(pre, l, r);
        T y = get(suf, n + 1 - r, n + 1 - l);
        if(x == y)return true;
        return false;
    }
};