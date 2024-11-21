#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
typedef pair<int,int> PII;
int n,f[N],g[N],h[N],d[N],val[N];
vector<int> e[N];
void dfs1(int x,int fa)
{
	g[x]=val[x];
	for(int y:e[x])
	{
		if(y==fa) continue;
		dfs1(y,x);
		g[x]=max(g[x],f[x]+f[y]+val[x]);
		g[x]=max(g[x],g[y]);
		f[x]=max(f[x],f[y]);	
	}
	f[x]+=val[x];	
} 
bool cmp1(int a,int b)
{
	return f[a]>f[b];
}
bool cmp2(int a,int b)
{
	return g[a]>g[b];
}
int res;
void dfs2(int x,int fa)
{
	vector<int> u,v; 
	for(int y:e[x])
	{
		if(y==fa) continue;
		v.push_back(y);
		u.push_back(y);
	}
	sort(u.begin(),u.end(),cmp2);u.push_back(0);
	sort(v.begin(),v.end(),cmp1);v.push_back(0);v.push_back(0);
	for(int y:e[x])
	{
		if(y==fa) continue;
		d[y]=max({d[x],max(h[x],(y==v[0]||y==v[1]?f[v[2]]:f[v[1]]))+(y==v[0]?f[v[1]]:f[v[0]])+val[x],(y==u[0]?g[u[1]]:g[u[0]])});
		res=max(res,g[y]+d[y]);
		h[y]=max(h[x],(y==v[0]?f[v[1]]:f[v[0]]))+val[x];
		dfs2(y,x);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	// for(int i=1;i<=n;++i) val[i]=1;
	for(int i=1;i<n;++i)
	{
		int x,y; cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs1(1,0),dfs2(1,0);
	cout<<res-1<<'\n';
	return 0;
}

