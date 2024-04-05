#include <bits/stdc++.h>
using namespace std;

struct trie {
  int n;
  vector<array<int, 52>> trans;
  vector<int> cnt;
  trie() : n(0) { new_node(); }
  int new_node() {
    trans.push_back({});
    trans.back().fill(0);
    cnt.push_back(0);
    return n++;
  }
  int insert(const string &s) {
    int now = 0;
    for (char c : s) {
      int i = c - 'a';
      if (c >= 'A') i = c - 'A' + 26;
      if (!trans[now][i]) {
        trans[now][i] = new_node();
      }
      now = trans[now][i];
    }
    cnt[now]++;//以该结点结尾的单词数+1
    return now;
  }
};

struct trie2 {//常规
  int trans[100010][26], cnt;
  bool exist[100010];

  void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (!trans[p][c]) trans[p][c] = ++cnt;
      p = trans[p][c];
    }
    exist[p] = 1;
  }

  bool find(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
      int c = s[i] - 'a';
      if (!trans[p][c]) return 0;
      p = trans[p][c];
    }
    return exist[p];
  }
};