int C[N][N];

void comb(){
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(!j) {
                C[i][j] = 1;
                continue;
            }
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= mod;
        }
    }
}