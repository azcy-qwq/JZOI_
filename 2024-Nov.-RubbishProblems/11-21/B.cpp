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
const int N=1e7+10,MOD=1e9+7;
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
int l[25],r[25];
bitset<N> st,c[25];
void Solve()
{
    int n,m,st=0; cin>>n>>m;
    unordered_map<int,bool> q;
    for(int i=0;i<m;++i) 
    {
        cin>>l[i]>>r[i],l[i]--,r[i]--;
        c[i].reset();
        for(int j=l[i];j<=r[i];++j)
            c[i].set(j);
    }
    for(int i=0;i<(1<<m);++i)
    {
        st.reset();
        for(int j=0;j<m;++j)
        {
            if(!(i>>j&1)) continue;
            
        }
    }
    cout<<sz(q)<<'\n';
}
bool M2;
int main()
{
//    freopen("steins.in","r",stdin);
//    freopen("steins.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=clock();
    int t=1; cin>>t;
    while(t--) Solve();
    See_Memory; See_Time;
    Nai_Long;
}