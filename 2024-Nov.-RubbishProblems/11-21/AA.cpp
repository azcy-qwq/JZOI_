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
const int N=1e4+10,MOD=1000007;
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
    template<typename T> inline int Mmax(T &a,T b){return a<b?a=b,b:a;}
    template<typename T> inline int Mmin(T &a,T b){return a>b?a=b,b:a;}
    template<typename...Args> inline int Cadd(int a,int b,Args...args){return Cadd(Cadd(a,b),args...);}
    template<typename...Args> inline int Cmul(int a,int b,Args...args){return Cmul(Cmul(a,b),args...);}
    template<typename...Args> inline int Cdel(int a,int b,Args...args){return Cdel(Cdel(a,b),args...);}
    template<typename...Args> inline void Madd(int &a,int b,Args...args){Madd(a,b),Madd(a,args...);}
    template<typename...Args> inline void Mdel(int &a,int b,Args...args){Mdel(a,b),Mdel(a,args...);}
    template<typename...Args> inline void Mmul(int &a,int b,Args...args){Mmul(a,b),Mmul(a,args...);}
    template<typename...Args,typename T> inline int Mmax(T &a,Args...args){return Mmax(a,Mmax(args...));}
    template<typename...Args,typename T> inline int Mmin(T &a,Args...args){return Mmin(a,Mmin(args...));}
    int ksm(int x,int y){int s=1;for(;y;y>>=1,Mmul(x,x)) if(y&1) Mmul(s,x); return s;}
}
using namespace MTool;
int n,Mx[N],a[N],dp[N];
void Solve()
{
    cin>>n; int ans=1;
    for(int i=1;i<=n;++i)
        dp[i]=1,cin>>a[i],Mmax(Mx[i],Mx[i-1],a[i]);
    for(int i=n;i>=1;--i)
    {
        Madd(ans,Cmul(a[i]-1,dp[Mx[i-1]]));
        for(int j=1;j<=i;++j)    
            dp[j]=Cadd(Cmul(dp[j],j),dp[j+1]);
    }
    cout<<ans<<'\n'; 
}
bool M2;
int main()
{
//    freopen("maou.in","r",stdin);
//    freopen("maou.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=clock();
    int t=1; //cin>>t;
    while(t--) Solve();
    See_Memory; See_Time;
    Nai_Long;
}//5 1 1 2 1 3