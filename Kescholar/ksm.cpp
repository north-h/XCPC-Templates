i64 ksm(i64 a, i64 n, i64 mod) {
	i64 ans = 1;
	while (n) {
		if (n & 1)
			ans = (ans * a) % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans % mod;
}

i64 ksm(i64 a, i64 n) {
	i64 ans = 1;
	while (n) {
		if (n & 1)
			ans = (ans * a);
		a = a * a;
		n >>= 1;
	}
	return ans ;
}