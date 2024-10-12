#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<stack>
#include<map>
#include<ctime>
#define int long long
using namespace std;
int T;
const int N=1e2;
int dir[N][3]={{0,2},{0,-2},
{1,2},{1,-2},
{2,1},{2,2},{2,0},{2,-1},{2,-2},
{-1,2},{-1,-2},
{-2,1},{-2,2},{-2,0},{-2,-1},{-2,-2}
};
int ans=-1145141919810;
int n,m,mp[N][N];
void dfs(int x,int y,int tot)
{
    if(!(x>=1&&x<=n&&y>=1&&y<=m))
        return;
	for(int i=0;i<16;i++)
	{
		int xx=x+dir[i][0];
		int yy=y+dir[i][1];
		if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
		{
			dfs(xx,yy,tot+mp[x][y]);
		}
		ans=max(tot,ans);
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		// int n,m,mp[N][N];
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				dfs(i,j,0);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}