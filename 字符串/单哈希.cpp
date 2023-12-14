template<class T, int P, int mod>
struct Hash {
    vector<T> p, h;
    string s;
    Hash(const string &str) :
        s(" " + str),
        p(str.size() + 1) {
        p[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            p[i] = (p[i - 1] * P) % mod;
            h[i] = (h[i - 1] * P + s[i]) % mod;
        }
    }
    T get(int l, int r) {
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
    }
};