template<typename T>
struct segment_sieve {
	vector<bool> is_prime, is_prime_small;
	vector<T> prime;
	segment_sieve() {
		is_prime.resize(1000010);
		is_prime_small.resize(1000100);
	}
 
	//对区间[a,b]内的整数执行筛法，is_prime[i-a]=true  ---  表示i是素数 注意这里下标偏移了a，所以从0开始。
	void get_num(T a, T b) {
		if (a == 1) a = 2;
		for (T i = 0; i * i <= b; ++i)
			is_prime_small[i] = true; //对[2,sqrt(b))的初始化全为质数
		for (T i = 0; i <= b - a; ++i)
			is_prime[i] = true; //对下标偏移后的[a,b)进行初始化
 
		for (T i = 2; i * i <= b; ++i) {
			if (is_prime_small[i]) {
				for (T j = 2 * i; j * j <= b; j += i)
					is_prime_small[j] = false; //筛选[2,sqrt(b));
				//(a+i-1)/i得到最接近a的i的倍数，最低是i的2倍，然后筛选
				for (T j = max((T)2, (a + i - 1) / i) * i; j <= b; j += i)
					is_prime[j - a] = false;
			}
		}
		for (T i = 0; i <= b - a; ++i) //统计个数
			if (is_prime[i])
				prime.push_back(i + a);
	}
};