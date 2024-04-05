#include <bits/stdc++.h>
 
using namespace std;
 
struct UFS {
    int sz;
    vector<int> rank, p;
    void link(int x, int y) {
        if (x == y)
            return;
        if (rank[x] > rank[y])
            p[y] = x;
        else
            p[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }
    void init(int n) {
        sz = n;
        rank.resize(n + 1);
        p.resize(n + 1);
        for (int i = 0; i <= sz; i++) {
            p[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x) {
        return x == p[x] ? x : (p[x] = find(p[x]));
    }
    void unin(int x, int y) {
        link(find(x), find(y));
    }
    void compress() {
        for (int i = 0; i < sz; i++)
            find(i);
    }
};
//种类并查集 merge(y + n, x),merge(x + n, y)
 