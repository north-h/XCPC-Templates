struct Trie {
    int idx = 0;
    int s[100010][26], cnt[100010];
    bool exit[100010];
    void insert(string str) {
        int p = 0;
        for (int i = 0; i < str.size(); i++) {
            int u = str[i] - 'a';
            if (!s[p][u]) s[p][u] = ++idx;
            p = s[p][u];
            cnt[p]++;
        }
        exit[p] = 1;
    }

    int query(string str) {
        int p = 0;
        for (int i = 0; i < str.size(); i++) {
            int u = str[i] - 'a';
            if (!s[p][u]) return 0;
            p = s[p][u];
        }
        return cnt[p];
    }
