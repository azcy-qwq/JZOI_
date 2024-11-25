#include<bits/stdc++.h>
using namespace std;
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
const int N=1e6+10;
#define int long long
bool m1;
pair<int,pair<int,int> > e[N];
vector<pair<int,int> > nei[N];
int fa[N];
int n,m,ans=INT_MAX,tt,dis1[N],dis2[N];
bool m2;
void dfs1(int id,int fa){
    for(auto to:nei[id]){
        if(to.first==fa) continue;
        dis1[to.first]=maxm(dis1[id],to.second);
        dfs1(to.first,id);
    }
}void dfs2(int id,int fa){
    for(auto to:nei[id]){
        if(to.first==fa) continue;
        dis2[to.first]=maxm(dis2[id],to.second);
        dfs2(to.first,id);
    }
}
int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
    x=getfa(x),y=getfa(y);
    fa[x]=fa[y];
}
bool query(int x,int y){
    x=getfa(x),y=getfa(y);
    if(x==y) return 1;
    else return 0;
}
void solve1(){
    iota(fa+1,fa+n+2,1);
    for(int i=1;i<=m;++i){
        if(query(e[i].second.first,e[i].second.second)) continue;
        merge(e[i].second.first,e[i].second.second);
        nei[e[i].second.first].push_back({e[i].second.second,e[i].first});
        nei[e[i].second.second].push_back({e[i].second.first,e[i].first});

    }dfs1(1,0);
    dfs2(n,0);
    int w,u,v;
    for(int i=1;i<=m;++i){
        auto to=e[i];
        w=to.first,u=to.second.first,v=to.second.second;
        if(dis1[u]<=w&&dis2[v]<=w) 
            ans=minm(ans,maxm(dis1[u],dis2[v])+w);
        swap(u,v);
        if(dis1[u]<=w&&dis2[v]<=w) 
            ans=minm(ans,maxm(dis1[u],dis2[v])+w);
    }
}
void solve2(){
    // iota(fa+1,fa+n+1,1);
    for(int i=1;i<=m;++i){
        if((e[i].second.first==1&&e[i].second.second==n)||
            (e[i].second.first==n&&e[i].second.second==1)) ans=minm(ans,e[i].first);
    }
}
signed main(){
//ios::sync_with_stdio(0);
    // cerr<<(&m2-&m1)/1024/1024;
auto_init();
    cin>>n>>m;
    for(int i=1;i<=m;++i)
        cin>>e[i].second.first>>e[i].second.second>>e[i].first;
    sort(e+1,e+m+1);
    solve1();
    solve2();
    cout<<ans;
}
/*
6 9
1 3 10
1 2 15
2 4 20
3 4 20
4 6 15
5 6 12
3 5 10
1 5 13
2 3 9
*/