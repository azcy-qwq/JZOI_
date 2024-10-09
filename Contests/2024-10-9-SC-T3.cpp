#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
bitset<N> vis[N];
pair<int,int> dir[4]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,ans;
void dfs(int x,int y){
    if(x<=0||y<=0||x>=n||y>=m){
        ++ans;
        return;
    } 
    vis[x][y]=1;
    int tx,ty;
    for(int i=0;i<4;++i){
        tx=x+dir[i].first,ty=y+dir[i].second;
        if(tx>=0&&ty>=0)
            if(vis[tx][ty]) continue;
        else dfs(tx,ty);
    }
    vis[x][y]=0;
}
int main(){
// ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<n;++i){
        vis[i][0]=1;
        dfs(i,1);
        vis[i][0]=0;
    }for(int i=1;i<m;++i){
        vis[0][i]=1;
        dfs(1,i);
        vis[0][i]=0;
    }
    cout<<ans*2;
    system("pause");
    
}