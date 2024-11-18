#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+5;
int n,m,sx,sy,ex,ey,ans1=1e9,ans2=1e9;
struct node{
    int v,w;
};
vector<node>e[N];
int mp[N][N],vis[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
inline void dfs(int sx1,int sy1,int sum)
{
    ans1=1e9;
    vis[sx][sy]=1;
    if(sx1==ex&&sy1==ey) 
    {
        ans1=min(sum,ans1);
        return ;
    }
    if(sum>=ans1) return ;
    int flag=0;
    for(int i=0;i<4;i++)
    {
        int xx=dx[i]+sx1,yy=dy[i]+sy1;
        if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&mp[xx][yy]!=-1&&!vis[xx][yy])
        {
            vis[xx][yy]=1;
            dfs(xx,yy,sum+mp[xx][yy]);            
        }
        else flag++;
    }
    if(flag==0) 
    {
        ans1=-1;
        return ;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>n>>m>>sx>>sy>>ex>>ey)
    {
        memset(mp,0,sizeof(mp));
        memset(vis,0,sizeof(vis));
        string s; getline(cin,s);
        for(int i=1;i<=n;i++)
        {
            string s; getline(cin,s);
            stringstream ss(s);
            for(int j=1;j<=m;j++)
            {
                string w;  ss>>w;
                if(w=="*") mp[i][j]=-1;
                else mp[i][j]=stoi(w);
            }
        }
        dfs(sx,sy,mp[sx][sy]);
        cout<<ans1<<'\n';
    }
     return 0;  
}