#include <bits/stdc++.h>
using namespace std;
 
 
struct Matrix {
	using i64 = long long;
	i64 N;
	vector<vector<i64>> A;
	Matrix() { N = 0;}
	Matrix(int n) {
		N = n;
		A.resize(N + 1);
		for (int i = 0; i <= N; i ++)
			A[i].resize(N + 1, 0);
	}
	Matrix operator*(const Matrix &b) const {
		Matrix res(b.N);
 
		for (int i = 1; i <= b.N; ++i)
			for (int j = 1; j <= b.N; ++j)
				for (int k = 1; k <= b.N; ++k)
					res.A[i][j] = (res.A[i][j] + A[i][k] * b.A[k][j]);
		return res;
	}
	Matrix qpow(i64 k) {
		Matrix res(N);
 
		//斐波那契数列初始化
		//res.A[1][1] = res.A[1][2] = 1;
		//A[1][1] = A[1][2] = A[2][1] = 1;
 
		//单位矩阵
		for (int i = 0; i <= N; i ++)
			res.A[i][i] = 1;
 
		while (k) {
			if (k & 1) res = res * (*this);
			(*this) = (*this) * (*this);
			k >>= 1;
		}
		return res;
	}
};