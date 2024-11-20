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
const int N=1010,MOD=998244353;
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
namespace BigNum
{
	vector<char> Init(int x)
	{
		vector<char> a;
		while(x) a.push_back(x%10),x/=10;
		return a;
	}
	vector<char> add(vector<char> a,vector<char> b)
	{
		if(sz(a)<sz(b)) return add(b,a);
		vector<char> c; int t=0;
		for(int i=0;i<sz(a);++i)
		{
			t+=a[i];
			if(i<sz(b)) t+=b[i];
			c.push_back(t%10); t/=10;
		}
		if(t) c.push_back(t);
		return c;
	}
	vector<char> mul(vector<char> a,vector<char> b)
	{
		vector<char> c(sz(a)+sz(b)+1);
		for(int i=0;i<sz(a);++i)
			for(int j=0;j<sz(b);++j)
				c[i+j]+=a[i]*b[j];
		for(int i=0;i<sz(c)-1;++i)
			c[i+1]+=(c[i]/10),c[i]%=10;
		while(sz(c)&&c.back()>10) 
		{
			int tmp=c.back(); c.back()/=10;
			c.push_back(tmp%10);
		}
		while(sz(c)>1&&c.back()==0) c.pop_back();
		return c;
	}	
	void Clear(vector<char> &x)
	{
		x.clear();
	}
	void Print(vector<char> x)
	{
		reverse(all(x));
		for(int k:x) cout<<k; 
        cout<<'\n';
	} 
}
using namespace BigNum;
vector<char> e[N],g[N][N>>1][2],h[N>>1][2];
int n,f[N][2]; 
void dfs(int u,int fa)
{
	g[u][0][0]=Init(1);
	for(int v:e[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		f[u][0]+=max(f[v][0],f[v][1]); 
 	}	
	for(int v:e[u])
	{
		if(v==fa) continue;
		Mmax(f[u][1],f[u][0]-max(f[v][0],f[v][1])+f[v][0]+1);
	}
	for(int v:e[u])
	{
		if(v==fa) continue;
		for(int i=0;i<=f[u][0];++i)
			for(int j=0;j<=f[v][0];++j)
				h[i+j][0]=add(h[i+j][0],mul(g[u][i][0],g[v][j][0])),h[i+j+1][1]=add(h[i+j+1][1],mul(g[u][i][0],g[v][j][0]));
		for(int i=0;i<=f[u][0];++i)
			for(int j=0;j<=f[v][1];++j)
				h[i+j][0]=add(h[i+j][0],mul(g[u][i][0],g[v][j][1]));
		for(int i=0;i<=f[u][1];++i)
			for(int j=0;j<=f[v][0];++j)
				h[i+j][1]=add(h[i+j][1],mul(g[u][i][1],g[v][j][0]));
		for(int i=0;i<=f[u][1];++i)
			for(int j=0;j<=f[v][1];++j)
				h[i+j][1]=add(h[i+j][1],mul(g[u][i][1],g[v][j][1]));	
		for(int i=0;i<=f[u][0];++i) g[u][i][0]=h[i][0],Clear(h[i][0]);
		for(int i=0;i<=f[u][1];++i) g[u][i][1]=h[i][1],Clear(h[i][1]);							
	}	
} 
void Solve()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		int u,m,v; cin>>u>>m;
		while(m--) 
		{
			cin>>v;
			e[u].push_back(v);
			e[v].push_back(u); 
		}
	}
	dfs(1,0);
	cout<<max(f[1][0],f[1][1])<<'\n';
	if(f[1][0]==f[1][1]) Print(add(g[1][f[1][0]][0],g[1][f[1][1]][1]));
	else if(f[1][0]>f[1][1]) Print(g[1][f[1][0]][0]);
	else Print(g[1][f[1][1]][1]);
}
bool M2;
int main()
{
//	freopen("TREE.in","r",stdin);
//	freopen("TREE.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int T=clock();
	int t=1; //cin>>t;
	while(t--) Solve();
	See_Memory; See_Time;
	Nai_Long;
}


