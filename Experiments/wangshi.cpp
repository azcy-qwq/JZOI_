#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
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
const int N=1e6+10,MOD=998244353;
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
    template<typename T> inline bool Mmax(T&a,T b){return a<b?a=b,1:0;}
    template<typename T> inline bool Mmin(T&a,T b){return a>b?a=b,1:0;}
    template<typename...Args> inline int Cadd(int a,int b,Args...args){return Cadd(Cadd(a,b),args...);}
    template<typename...Args> inline int Cmul(int a,int b,Args...args){return Cmul(Cmul(a,b),args...);}
    template<typename...Args> inline int Cdel(int a,int b,Args...args){return Cdel(Cdel(a,b),args...);}
    template<typename...Args> inline void Madd(int &a,int b,Args...args){Madd(a,b),Madd(a,args...);}
    template<typename...Args> inline void Mdel(int &a,int b,Args...args){Mdel(a,b),Mdel(a,args...);}
    template<typename...Args> inline void Mmul(int &a,int b,Args...args){Mmul(a,b),Mmul(a,args...);}
    template<typename...Args,typename T> inline bool Mmax(T&a,T b,Args...args){return Mmax(a,b)|Mmax(a,args...);}
    template<typename...Args,typename T> inline bool Mmin(T&a,T b,Args...args){return Mmin(a,b)|Mmin(a,args...);}
    int ksm(int x,int y){int s=1;for(;y;y>>=1,Mmul(x,x)) if(y&1) Mmul(s,x); return s;}
}
using namespace MTool;
mt19937_64 r64(time(0));
int n,a[N];  ull b[N],val[N]; 
bool vis[N];
int Calc(int l,int r)
{
    if(l==r) return (a[l]==1);
    int mid=(l+r)>>1,ans=0; ull sum=0;
    unordered_map<ull,bool> q,clq; 
    q.reserve(1e6);
    // q.rehash(2e7);
    clq.reserve(1e6);
    // clq.rehash(2e7);
    for(int i=mid+1;i<=r;++i) 
    {
        if(vis[a[i]]) break;
        sum^=b[a[i]],q[sum]=1; vis[a[i]]=1;
    }
    for(int i=mid+1;i<=r;++i) 
        if(vis[a[i]]) vis[a[i]]=0;
        else break;
    sum=0; int Max=0;
    for(int i=mid;i>=l;--i)
    {
        if(vis[a[i]]) break; 
        sum^=b[a[i]]; Mmax(Max,a[i]); vis[a[i]]=1;
        if(q[val[Max]^sum]) ans++;
    } 
    for(int i=mid;i>=l;--i) 
        if(vis[a[i]]) vis[a[i]]=0;
        else break;
    swap(q,clq); sum=0;
    for(int i=mid;i>=l;--i)
    {
        if(vis[a[i]]) break;
        sum^=b[a[i]]; q[sum]=1; vis[a[i]]=1;
    }
    for(int i=mid;i>=l;--i) 
        if(vis[a[i]]) vis[a[i]]=0;
        else break;
    sum=0,Max=0;
    for(int i=mid+1;i<=r;++i)
    {
        if(vis[a[i]]) break;
        sum^=b[a[i]]; Mmax(Max,a[i]); vis[a[i]]=1;
        if(q[val[Max]^sum]) ans++;
    }
    for(int i=mid+1;i<=r;++i) 
        if(vis[a[i]]) vis[a[i]]=0;
        else break;
//    cout<<l<<' '<<r<<' '<<mid<<' '<<ans<<'\n';
    return ans+Calc(l,mid)+Calc(mid+1,r);
}
void Solve()
{
    cin>>n;
    for(int i=1;i<=n;++i) 
        b[i]=r64(),val[i]=val[i-1]^b[i];
    for(int i=1;i<=n;++i) cin>>a[i];
    cout<<Calc(1,n)<<'\n';
}
bool M2;
int main()
{
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=clock();
    int t=1; //cin>>t;
    while(t--) Solve();
    // See_Memory; See_Time;
    // Nai_Long;
}