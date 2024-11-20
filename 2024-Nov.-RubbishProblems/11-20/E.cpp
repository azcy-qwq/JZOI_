#include <cstdio>
#define ll long long
const ll mod=998244353ll;
const int N=3000;
ll po[N*N+10],C[N+10][N+10],a[N+10],f[N+10],d[N+10];
int n;
void init()
{
    po[0]=C[0][0]=1;
    for(int i=1;i<=N;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    for(int i=1;i<=N*N;i++) po[i]=po[i-1]*2%mod;
}
ll quickpow(ll d,ll k)
{
    ll f=1;
    while(k)
    {
        if(k&1) f=f*d%mod;
        d=d*d%mod;
        k>>=1;
    }
    return f;
}
int main()
{
    init();
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",d+i);
    a[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
            (a[i]-=po[(i-j)*(i-j-1)/2]*C[i][j]%mod*a[j])%=mod;
        (a[i]+=po[i*(i-1)/2])%=mod;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            (f[i]+=C[i][j]*a[j]%mod*
            (f[i-j]+d[j]*po[(i-j)*(i-j-1)/2]%mod
            *j%mod))%=mod;
        f[i]=(f[i]+mod)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        ll p=quickpow(po[(i*(i-1)/2)]*i%mod,mod-2);
        printf("%lld\n",f[i]*p%mod);
    }
    return 0;
}