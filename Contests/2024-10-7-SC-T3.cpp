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
}using namespace azcy;
const int N=1e4+10;
int n,p[N],c[N],ans;
pair<int,int> dir[2]={{0,1},{1,0}};
void dfs(int x,int y,int cur){
    if(x==n&&y==n){
        // for(int i=1;i<=2*n;++i)
        //     cout<<c[i]<<" ";
        // cout<<"\n";
        ++ans;
        return ;
    }
    int tx,ty;
    if(p[cur]==cur){
        for(int i=0;i<=1;++i)
        {
            tx=x+dir[i].first,ty=y+dir[i].second;
            if(tx>n||ty>n||ty>tx) continue;
            c[cur]=i;
            dfs(tx,ty,cur+1);
        }
    }else{
        tx=x+dir[c[p[cur]]].first,ty=y+dir[c[p[cur]]].second;
        if(tx>n||ty>n||ty>tx) return;
        c[cur]=c[p[cur]];
        dfs(tx,ty,cur+1);
    }
}
int main(){
ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=2*n;++i)
        cin>>p[i];
    dfs(0,0,1);
    cout<<ans;
}