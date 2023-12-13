template<int P, int mod, int N>
struct Hash {
    typedef unsigned long long ULL;
    ULL p[N], h[N];
    string s;

    Hash(const string &str) : s(" " + str) {
        p[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            p[i] = p[i - 1] * P % mod;
            h[i] = h[i - 1] * P % mod + s[i];
            h[i] %= mod;
        }
    }

    ULL get(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};