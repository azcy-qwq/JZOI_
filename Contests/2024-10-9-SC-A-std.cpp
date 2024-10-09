#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MOD = 2017;
int n, m, u, v, t;
struct mat
{
    LL a[112][112];

    mat() { memset(a, 0, sizeof a); }

    mat operator-(const mat &T) const
    {
        mat res;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
            {
                res.a[i][j] = (a[i][j] - T.a[i][j]) % MOD;
            }
        return res;
    }

    mat operator+(const mat &T) const
    {
        mat res;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
            {
                res.a[i][j] = (a[i][j] + T.a[i][j]) % MOD;
            }
        return res;
    }

    mat operator*(const mat &T) const
    {
        mat res;
        int r;
        for (int i = 0; i <= n; ++i)
            for (int k = 0; k <= n; ++k)
            {
                r = a[i][k];
                for (int j = 0; j <= n; ++j)
                    res.a[i][j] += T.a[k][j] * r, res.a[i][j] %= MOD;
            }
        return res;
    }

    mat operator^(LL x) const
    {
        mat res, bas;
        for (int i = 0; i <= n; ++i)
            res.a[i][i] = 1;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                bas.a[i][j] = a[i][j] % MOD;
        while (x)
        {
            if (x & 1)
                res = res * bas;
            bas = bas * bas;
            x >>= 1;
        }
        return res;
    }
}base;
int ans;
signed main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<=n;++i)
        base.a[i][i]=1,base.a[i][0]=1;
    for (int i = 1; i <= m; ++i)
    {
        cin>>u>>v;
        base.a[u][v]=1;
        base.a[v][u]=1;
    }
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j)
            cout<<base.a[i][j];
        cout<<endl;
    }
    cin>>t;
    // ++n;
    base=base^t;
    for(int i=0;i<=n;++i){
        for(int j=0;j<=n;++j)
            cout<<base.a[i][j];
        cout<<endl;
    }
    for(int i=0;i<=n;++i){
        ans+=base.a[1][i];
        ans%=MOD;
    }
    cout<<ans;
}