template<class T>
struct Trie {
    T idx = 0;
    vector<vector<T>> s;
    vector<T>cnt;
    Trie(T n): cnt(n, 0), s(n, vector<T>(26, 0)) {}
    void insert(string str) {
        T p = 0;
        for (int i = 0; i < str.size(); i++) {
            T u = str[i] - 'a';
            if (!s[p][u]) s[p][u] = ++idx;
            p = s[p][u];
        }
        cnt[p]++;
    }

    T query(string str) {
        T p = 0;
        for (int i = 0; i < str.size(); i++) {
            T u = str[i] - 'a';
            if (!s[p][u]) return 0;
            p = s[p][u];
        }
        return cnt[p];
    }
};