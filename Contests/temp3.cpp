#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define Nai_Long return 0
#define See_Memory cerr<<abs(&M1-&M2)/1024.0/1024.0<<'\n'
#define See_Time cerr<<(clock()-T)*1.0/CLOCKS_PER_SEC<<'\n'
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
    template<typename T> inline bool Mmax(T &a,T b){return a<b?a=b,1:0;}
    template<typename T> inline bool Mmin(T &a,T b){return a>b?a=b,1:0;}
    inline int power(int x,int y){int s=1;for(;y;y>>=1,Mmul(x,x))if(y&1)Mmul(s,x);return s;}
}
using namespace MTool;
int n,p[N],vis[N],ans,b[N];
int f[N];
void Solve()
{
    cin>>n; bool fl=1;
    for(int i=1;i<=n;++i) 
    {
        cin>>p[i],vis[p[i]]=1;
        if(p[i]) fl=0;
    }
    f[0]=1,f[1]=1,f[2]=2;
    for(int i=3;i<=n;++i)
        Madd(f[i],Cadd(f[i-1],Cmul(i-1,f[i-2])));
    if(fl)
    {
        cout<<f[n]<<'\n'; 
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!p[i]||b[i]) continue;
        if(p[i]!=i)
        {
            int x=p[i],idx=1;
            vector<int> pos; 
            while(p[x])
            {    
                if(!p[x]||b[p[x]]) break;
                pos.push_back(x);
                x=p[x]; b[x]=1; idx++;
            }
            if(p[x])
            {
                if(sz(pos)&1) return cout<<"0\n",void();
                continue;
            }
            p[x]=i;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;++i) if(!p[i]) cnt++;
    cout<<f[cnt]<<'\n';
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
/*
9
0 1 6 0 0 3 0 0 4
*/
