template<class T, int P>
struct SH {
    vector<T> p, h;
    string s;
    SH(const string &str) :
        s(" " + str), p(str.size() + 1),
        h(str.size() + 1) {
        p[0] = 1;
        for (int i = 1; i < s.size(); i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + s[i];
        }
    }
    T get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};