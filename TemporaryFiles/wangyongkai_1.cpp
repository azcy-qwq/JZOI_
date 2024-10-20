#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<iomanip>
#include<vector>
#define int long long 
#define inf LONG_LONG_MAX
using namespace std;
const int N=1e6;
struct node{
	int v,w;
};
vector<node>e[N];
int d[100],vis[100];
int p;
inline void spfa(int s)
{
	queue<int>q;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<100;i++)
	{
		d[i]=inf;
	}
	q.push(s);
	d[s]=0;
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(auto i:e[u])
		{
			int v=i.v,w=i.w;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		char a,b;
		int w;
		cin>>a>>b>>w;
		int u=a-'A',v=b-'A';
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	spfa('Z'-'A');
	int minn=inf;
	char id;
	for(int i=1;i<100;i++)
	{
		if(d[i]<minn&&d[i]!=0&&i+'A'<97)
		{
			id=i+'A';
			minn=d[i];
		} 
	//	cout<<minn<<'\n';
	}
	cout<<id<<' '<<minn<<'\n';
	return 0;
}