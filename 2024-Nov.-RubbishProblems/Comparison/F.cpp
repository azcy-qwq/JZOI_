#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 105;
const int mod = 2017;
struct matrix
{
    int n, m;
    int mat[MAXN][MAXN];
    matrix()
    {
        memset(mat, 0, sizeof(mat));
    }
};
matrix matrix_mul(matrix a, matrix b)
{
    matrix c;
    c.n = a.n, c.m = b.m;
    for (int i = 0; i <= c.n; i++)
        for (int j = 0; j <= c.m; j++)
            for (int z = 0; z <= a.m; z++)
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][z] * b.mat[z][j] % mod) % mod;
    return c;
}
matrix quick_pow_matrix(matrix x, int p)
{
    matrix r;
    r.n = r.m = x.n;
    for (int i = 1; i <= r.n; i++)
        r.mat[i][i] = 1;
    while (p)
    {
        if (p & 1)
            r = matrix_mul(r, x);
        x = matrix_mul(x, x);
        p >>= 1;
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, t, ret = 0;
    cin >> n >> m;
    matrix A;
    A.n = A.m = n;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        A.mat[u][v] = 1;
        A.mat[v][u] = 1;
    }
    for (int i = 0; i <= n; i++)
        A.mat[i][i] = 1;
    for (int i = 0; i <= n; i++)
        A.mat[i][0] = 1;
    cin >> t;
    matrix ans = quick_pow_matrix(A, t);
    for (int i = 0; i <= n; i++)
        ret = (ret + ans.mat[1][i]) % mod;
    cout << ret;
    return 0;
}