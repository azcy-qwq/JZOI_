#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define Nai_Long return 0
#define See_Memory cerr<<abs(&M1-&M2)/1024.0/1024.0<<"MB\n"
#define See_Time cerr<<(clock()-T)*1.0/CLOCKS_PER_SEC<<"s\n"
using namespace std;
const int N=2e5+10,MOD=998244353;
bool M1;
mt19937 rng(time(0));
namespace MTool
{
    inline int Cadd(int a,int b){return a+b>=MOD?a+b-MOD:a+b;}
    inline int Cdel(int a,int b){return a-b<0?a-b+MOD:a-b;}
    inline int Cmul(int a,int b){return 1ll*a*b%MOD;}
    inline void Madd(int &a,int b){a=(a+b>=MOD?a+b-MOD:a+b);}
    inline void Mdel(int &a,int b){a=(a-b<0?a-b+MOD:a-b);}
    inline void Mmul(int &a,int b){a=1ll*a*b%MOD;}
    inline int Cmod(int x){return (x%MOD+MOD)%MOD;}
    inline void Mmod(int &x){x=(x%MOD+MOD)%MOD;}
    template<typename T> inline T Mmax(T &a,T b){return a<b?a=b,1:0;}
    template<typename T> inline bool Mmin(T &a,T b){return a>b?a=b,1:0;}
    template<typename...Args> inline int Cadd(int a,int b,Args...args){return Cadd(Cadd(a,b),args...);}
    template<typename...Args> inline int Cmul(int a,int b,Args...args){return Cmul(Cmul(a,b),args...);}
    template<typename...Args> inline int Cdel(int a,int b,Args...args){return Cdel(Cdel(a,b),args...);}
    template<typename...Args> inline void Madd(int &a,int b,Args...args){Madd(a,b),Madd(a,args...);}
    template<typename...Args> inline void Mdel(int &a,int b,Args...args){Mdel(a,b),Mdel(a,args...);}
    template<typename...Args> inline void Mmul(int &a,int b,Args...args){Mmul(a,b),Mmul(a,args...);}
    template<typename...Args,typename T> inline T Mmax(T &a,Args...args){return Mmax(a,Mmax(args...));}
    template<typename...Args,typename T> inline bool Mmin(T &a,Args...args){return Mmin(a,Mmin(args...));}
    int ksm(int x,int y){int s=1;for(;y;y>>=1,Mmul(x,x)) if(y&1) Mmul(s,x); return s;}
}
using namespace MTool;
int n,q; ll c[N],dp[N],dep[N];
vector<pair<int,ll>> g[N]; 
void Dfs1(int u,int fa)
{
    dp[u]=c[u]; 
    for(auto k:g[u])
    {
        int v=k.fi; ll w=k.se;
        if(v==fa) continue;
        dep[v]=dep[u]+w; Dfs1(v,u); 
        Mmax(dp[u],dp[v]-2ll*w);
    }
}
int f[N][18]; ll Max[N][18];
void Dfs2(int u,int fa)
{
    f[u][0]=fa; Max[u][0]=dp[u];
    for(int i=1;i<=17;++i)
    {
        f[u][i]=f[f[u][i-1]][i-1];
        Mmax(Max[u][i],Max[u][i-1],Max[Max[u][i-1]][i-1]);
    }
    for(auto v:g[u]) if(v.fi!=fa) Dfs2(v.fi,u); 
}
void Solve()
{
    cin>>n>>q;
    for(int i=1;i<=n;++i) cin>>c[i];
    for(int i=2;i<=n;++i)
    {
        int u,v; ll w; cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    
}    
bool M2;
int main()
{
//    freopen("speaker.in","r",stdin);
//    freopen("speaker.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=clock();
    int t=1; //cin>>t;
    while(t--) Solve();
    See_Memory; See_Time;
    Nai_Long;
}