struct Kmp {
	vector<int> next;

	void getNext(string s) {
		int j = 0, k = -1, n = s.size();
		next.resize(n + 1);
		next[0] = -1;
		while (j < n) {
			if (k == -1 || s[j] == s[k]) {
				next[++j] = ++k;
			} else
				k = next[k];
		}
	}

	int kmp(string s, string p) {
		int n = s.size(), m = p.size();
		int i = 0, j = 0;

		while (i < n && j < m) {
			if (j == -1 || s[i] == p[j]) {
				i ++, j ++;
			} else {
				j = next[j];
			}
		}
		if (j == m) return i;
		else return -1;
	}
};