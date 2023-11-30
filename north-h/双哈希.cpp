template<int P1, int mod1, int P2, int mod2, int N>
struct Hash {
    long long p1[N], p2[N], h1[N], h2[N];
    string s;

    Hash(const string &str) : s(" " + str) {
        p1[0] = p2[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            p1[i] = (p1[i - 1] * P1) % mod1;
            h1[i] = (h1[i - 1] * P1 % mod1 + s[i]) % mod1;
            p2[i] = (p2[i - 1] * P2) % mod2;
            h2[i] = (h2[i - 1] * P2 % mod2 + s[i]) % mod2;
        }
    }

    long long get1(int l, int r) {
        return (h1[r] - (h1[l - 1] * p1[r - l + 1] % mod1) + mod1) % mod1;
    }

    long long get2(int l, int r) {
        return (h2[r] - (h2[l - 1] * p2[r - l + 1] % mod2) + mod2) % mod2;
    }
};