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
const int N=3e5+10,MOD=998244353;
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
const int M=N*32; 
struct SGT
{
    int rt[M],val[M],ls[M],rs[M],idx;
    void Modify(int &x,int y,int l,int r,int p,int v)
    {
        x=++idx;
        ls[x]=ls[y],rs[x]=rs[y],val[x]=val[y]+v;
        if(l==r) return; 
        int mid=(l+r)>>1;
        if(p<=mid) Modify(ls[x],ls[y],l,mid,p,v);
        else Modify(rs[x],rs[y],mid+1,r,p,v); 
    }
    int Query(int p,int l,int r,int x)
    {
        if(l==r) return val[p];
        int mid=(l+r)>>1;
        if(x<=mid) return Query(ls[p],l,mid,x)+val[rs[p]];
        else return Query(rs[p],mid+1,r,x); 
    }
    int Ask(int x,int y,int l,int r,int p)
    {
        if(l==r) return val[x]-val[y];
        int mid=(l+r)>>1;
        if(p<=mid) return Ask(ls[x],ls[y],l,mid,p);
        else return Ask(rs[x],rs[y],mid+1,r,p);
    }
}T; 
int n,a[N],lst[N],val[N],pos[N],fa[N];
void Solve()
{
    cin>>n; vector<int> h;
    for(int i=1;i<=n;++i) 
    {
        cin>>a[i],val[i]=val[i-1]^a[i];
        h.push_back(a[i]);
    }
    sort(all(h)); h.erase(unique(all(h)),h.end());
    for(int i=1;i<=n;++i)
    {
        if(a[i]!=a[i+1]) continue;
        pos[i]=1; 
    }
    for(int i=n;i>=1;--i)
    {
        if(pos[i])
        {
            fa[i]=1;
            fa[i]+=fa[i+2];
        }
    }
    for(int i=1;i<=n;++i)
    {
        a[i]=lower_bound(all(h),a[i])-h.begin()+1;
        if(!lst[a[i]]) T.Modify(T.rt[i],T.rt[i-1],1,n,i,1);
        else
        {
            T.Modify(T.rt[i],T.rt[i-1],1,n,lst[a[i]],-1);
            T.Modify(T.rt[i],T.rt[i],1,n,i,1);
        }
        lst[a[i]]=i;
    }
    int res=0;
    for(int i=1;i<=n;++i)
    {
        int l=1,r=fa[i],ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if((val[i+2*mid-1]^val[i-1])==0&&T.Query(T.rt[i+2*mid-1],1,n,i)==mid) l=mid+1,ans=mid;
            else r=mid-1; 
        }
        if(res<ans*2) cout<<i<<" "<<r<<'\n';
            res=max(res,ans*2);
    }
    cout<<res<<'\n';
}
bool M2;
int main()
{
   freopen("aa.in","r",stdin);
//    freopen("1.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=clock();
    int t=1; //cin>>t;
    while(t--) Solve();
    See_Memory; See_Time;
    Nai_Long;
}