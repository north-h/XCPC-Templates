#include <bits/stdc++.h>
 
using namespace std;
 
//欧拉函数,质数
vector<int> euler_range(int n) {
    vector<int> phi(n + 1), prime;
    vector<bool> is_prime(n + 1, true);
    is_prime[1] = 0, phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) prime.push_back(i), phi[i] = i - 1;
        for (int j = 0; j < (int)prime.size() && i * prime[j] <= n; j++) {
            is_prime[i * prime[j]] = 0;
            if (i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            else {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
    return phi;
}