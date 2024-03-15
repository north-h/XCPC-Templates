struct comb2{
    vector<int> fac,inf;

    comb2(int n) {
        fac.resize(n + 1);
        inf.resize(n + 1);
        fac[0] = inf[0] = 1;
        for(int i = 1; i <= n; i++){
            fac[i] = fac[i - 1] * i % mod;
            inf[i] = inf[i - 1] * ksm(i, mod - 2) % mod;
        }
    }

    int ksm(int a, int b){    // 快速幂
        int res = 1;
        while(b){
            if(b & 1) res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    
    int query(int n, int m) {
        int ans;
        ans = fac[n] * inf[n - m] % mod * inf[m] % mod;
        return ans;
    }
 };