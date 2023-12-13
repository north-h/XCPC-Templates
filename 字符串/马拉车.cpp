template <class T>
struct Manacher {
    vector<T> d;
    string str = "$#";
    Manacher(string s) : d((s.size() + 1) * 2) {
        for(auto i : s) {
            str += i;
            str += '#';
        }
        d[1] = 1;
        for(int i = 2, l, r = 1; i < str.size(); i++) {
            if(i <= r)d[i] = min(d[r + l - i], r - i + 1);
            while(str[i - d[i]] == str[i + d[i]])d[i]++;
            if(i + d[i] - 1 > r)l = i - d[i] + 1, r = i + d[i] - 1;
        }
    }

    T query() {
        T len = 0;
        for(auto i : d)len = max(len, i);
        return len - 1;
    }
};