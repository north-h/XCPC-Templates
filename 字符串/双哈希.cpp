template<class T, int P1, int mod1, int P2, int mod2>
struct Hash {
    vector<T> p1, p2, h1, h2;
    string s;
    Hash(const string &str) :
        s(" " + str),
        p1(str.size() + 1),
        h1(str.size() + 1),
        p2(str.size() + 1),
        h2(str.size() + 1) {
        p1[0] = p2[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            p1[i] = (p1[i - 1] * P1) % mod1;
            h1[i] = (h1[i - 1] * P1 % mod1 + s[i]) % mod1;
            p2[i] = (p2[i - 1] * P2) % mod2;
            h2[i] = (h2[i - 1] * P2 % mod2 + s[i]) % mod2;
        }
    }

    T get1(int l, int r) {
        return (h1[r] - (h1[l - 1] * p1[r - l + 1] % mod1) + mod1) % mod1;
    }

    T get2(int l, int r) {
        return (h2[r] - (h2[l - 1] * p2[r - l + 1] % mod2) + mod2) % mod2;
    }
};