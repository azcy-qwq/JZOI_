#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define all(x) x.begin(),x.end()
#define I_Will_Win return 0
#define See_Memory cerr<<abs(&M1-&M2)/1024.0/1024.0<<'\n'
#define See_Time cerr<<(clock()-T)*1.0/CLOCKS_PER_SEC<<'\n'
using namespace std;
const int N=20+10,mod=571373;
bool M1;
mt19937 rng(time(0));
int n,q,m,a[N];
void Add(int &x,int y){x=(x+y>=mod?x+y-mod:x+y);}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
void Mul(int &x,int y){x=1ll*x*y%mod;}
int mul(int x,int y){return 1l*x*y%mod;}
struct SGT
{
	int l[N],r[N],val[N],tAdd[N],tMul[N];
	#define ls(x) (x<<1)
	#define rs(x) (x<<1|1)
	#define mid ((l[x]+r[x])>>1)
	#define len(x) (r[x]-l[x]+1)
	void Pushup(int p){val[p]=add(val[ls(p)],val[rs(p)]);}
	void Pushdown(int p)
	{
		val[ls(p)]=add(mul(val[ls(p)],tMul[p]),mul(len(ls(p)),tAdd[p]));
		val[rs(p)]=add(mul(val[rs(p)],tMul[p]),mul(len(rs(p)),tAdd[p]));
		Mul(tMul[ls(p)],tMul[p]); Mul(tMul[rs(p)],tMul[p]);
		Mul(tAdd[ls(p)],tMul[p]); Mul(tAdd[rs(p)],tMul[p]);
		Add(tAdd[ls(p)],tAdd[p]); Add(tAdd[rs(p)],tAdd[p]);
		tAdd[p]=0,tMul[p]=1;
	}
	void Build(int p,int x,int y)
	{
		l[p]=x,r[p]=y,tMul[p]=1;
		if(x==y) return val[p]=a[x]%mod,void();
		Build(ls(p),x,mid),Build(rs(p),mid+1,y);
		Pushup(p);
	}
	void Modify_Add(int p,int x,int y,int v)
	{
		if(x<=l[p]&&r[p]<=y)
		{
			Add(val[p],mul(len(p),v)); 
			Add(tAdd[p],v); return;
		}
		Pushdown(p);
		if(x<=mid) Modify_Add(ls(p),x,y,v);
		if(y>mid) Modify_Add(rs(p),x,y,v);
		Pushup(p); 
	} 
	void Modify_Mul(int p,int x,int y,int v)
	{
		if(x<=l[p]&&r[p]<=y)
		{
			Mul(val[p],v); Mul(tAdd[p],v);
			Mul(tMul[p],v); return;
		}
		Pushdown(p);
		if(x<=mid) Modify_Mul(ls(p),x,y,v);
		if(y>mid) Modify_Mul(rs(p),x,y,v);
		Pushup(p); 
	}
	int Query(int p,int x,int y)
	{
		if(x<=l[p]&&r[p]<=y) return val[p];
		Pushdown(p); int res=0;
		if(x<=mid) Add(res,Query(ls(p),x,y));
		if(y>mid) Add(res,Query(rs(p),x,y));
		return res;
	}
}T;
void Solve()
{
	cin>>n>>q>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	T.Build(1,1,n); 
	while(q--) 
	{
		int op,x,y,k; cin>>op>>x>>y;
		if(op==1) cin>>k,T.Modify_Mul(1,x,y,k);
		if(op==2) cin>>k,T.Modify_Add(1,x,y,k);
		if(op==3) cout<<T.Query(1,x,y)<<'\n';
	}
}
bool M2;
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int T=clock();
	int t=1; //cin>>t;
	while(t--) Solve();
	See_Memory; See_Time;
	I_Will_Win;
}
/*
5 5 38
1 5 4 2 3
3 1 5
2 1 4 1
1 2 4 2
2 3 5 5
3 1 4
*/
