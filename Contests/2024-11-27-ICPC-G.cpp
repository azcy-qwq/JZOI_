#include<bits/stdc++.h>
#define int long long
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
namespace azcy{
    using namespace std;
    bool debug_switch=1;
    void auto_init(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME,string OUTPUT_FILE_NAME){
        freopen(INPUT_FILE_NAME.data(),"r",stdin);
        freopen(OUTPUT_FILE_NAME.data(),"w",stdout);
    }
    template<typename T>
    void dbgo(T x){
        cerr<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cerr<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cerr<<first<<" ";
        dbgo(rest...);
        cerr<<"\n";
    }//made by _azcy
    template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cerr << x << "\n";
    }
    template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }template<typename T1,typename T2>
    inline T1 maxm(T1 a,T2 b){
        return (a>b)?(a):(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }template<typename T1,typename T2>
    inline T1 minm(T1 a,T2 b){
        return (a<b)?a:(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
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
int vis[62][2],sum[62];
void Solve()
{
	for(int i=0;i<=61;++i)
		vis[i][0]=vis[i][1]=sum[i]=0;
	int n,k; cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i) 
	{
		cin>>a[i];
		if(i==1) continue;
		for(int j=61;i>=0;--j)
		{
			if((a[i]&(1ll<<j))!=(a[i-1]&(1ll<<j)))
			{
                dbg((1ll<<j),(a[i-1])&(1ll<<j));
				vis[j][(a[i-1])&(1ll<<j)]=1;
				break;
			}
		}
	}
	for(int i=0;i<=61;++i)
		if(vis[i][0]&&vis[i][1])
			return cout<<"0\n",void();
	for(int i=0;i<=61;++i)
	{
		if(!i) sum[i]+=(vis[i][0]||vis[i][1]);
		else sum[i]=sum[i-1]+(vis[i][0]||vis[i][1]);
	}
	int ans=0;
	for(int i=61;i>=0;--i)
	{
		int c=k&(1ll<<i);
		if(vis[i][1]&&!c) break;
		if(!vis[i][1]&&c)
			ans+=(1ll<<(i-(i?sum[i-1]:0)));
		if(vis[i][0]&&c) break;
	}
	cout<<ans<<'\n';
}
bool M2;
signed main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int T=clock();
	int t=1; cin>>t;
	while(t--) Solve();
	See_Memory; See_Time;
	Nai_Long;
}
/*
2
4 1000000000000
92484912 894218424121 421849217421 92138421978124
6 1000000000000
92484912 894218424121 421849217421 92138421978124 998244353 99824435399824435
*/





