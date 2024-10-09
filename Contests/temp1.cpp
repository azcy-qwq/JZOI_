#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 110;
const int Mod = 2017;

struct Matrix {
	int a[maxn][maxn], n, m;
	int* operator [](int x) { return a[x]; }
	void clear() { n = 0, m = 0, memset(a, 0, sizeof(a)); }
} a;

Matrix operator *(Matrix &x, Matrix &y) {
	Matrix z; z.clear(); z.n = x.n, z.m = y.m;
	for (int i = 0; i <= x.n; ++i) {
		for (int j = 0; j <= x.m; ++j) {
			for (int k = 0; k <= y.m; ++k) z[i][k] = (z[i][k] + x[i][j] * y[j][k]) % Mod;
		}
	}
	return z;
}

Matrix qpow(Matrix &base, int p) {
	Matrix res = base; --p;
	while (p) {
		if (p & 1) res = res * base;
		base = base * base;
		p >>= 1;
	}
	return res;
}

int n, m, t, ans;

int main() {
	scanf("%d%d", &n, &m); a.n = n, a.m = n;
	for (int i = 0; i <= n; ++i) a[i][i] = 1, a[i][0] = 1;
	for (int i = 1; i <= m; ++i) {
		int u, v; scanf("%d%d", &u, &v);
		a[u][v] = 1; a[v][u] = 1;
	}
	scanf("%d", &t);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j)
            cout<<a[i][j];
        cout<<endl;
    }
        
	a = qpow(a, t);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j)
            cout<<a[i][j];
        cout<<endl;
    } for (int i = 0; i <= n; ++i) ans = (ans + a[1][i]) % Mod;
	printf("%d", ans);
	return 0;
}