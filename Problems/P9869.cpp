#include<bits/stdc++.h>
// #pragma GCC optimize(2)
// #pragma comment (linker, "/STACK:1024000000,1024000000")
// #pragma comment(linker, "/HEAP:2000000")
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
const int N=1e5+10;
const int T=1e5+2,F=-1e5-2,U=0;
int c,t,n,m,a,b;
char v;
class M{
    public:
        int data[(N<<1)+10];
        int& operator[](const int x){
            return data[x+N];
        }void clear(){
            memset(data,0,sizeof(data));
        }
};
M fa;
// bitset<N*2> vis;
int getfa(int id){
    // if(vis[id]) return id;
    if(fa[id]==-id) return -id;
    if(fa[id]==id) return id;
    // vis[id]=1;
    return fa[id]=((fa[id]>0)?(getfa(fa[id])):(-getfa(-fa[id])));
}int getfa2(int id){
    if(fa[id]==U||fa[id]==T||fa[id]==F) return id;
    if(fa[id]==-id) return -id;
    if(fa[id]==id) return id;
    // vis[id]=1;
    return fa[id]=((fa[id]>0)?(getfa(fa[id])):(-getfa(-fa[id])));
}
int main(){
    // qfopen("tribool2.in","tribool.out");
    // freopen("tribool5.in","r",stdin);
    // auto_init();
//ios::sync_with_stdio(0);
    cin>>c>>t;
    while(t--){
        // vis.reset();
        fa.clear();
        int ans=0;
        cin>>n>>m;
        for(int i=-n;i<=n;++i){
            fa[i]=i;
        }fa[T]=T,fa[F]=F,fa[0]=0;
        for(int i=1;i<=m;++i){
            cin>>v;
            if(v=='T'){
                cin>>a;
                fa[a]=T;
            }else if(v=='F'){
                cin>>a;
                fa[a]=F;
            }else if(v=='U'){
                cin>>a;
                fa[a]=0;
            }else if(v=='+'){
                cin>>a>>b;
                fa[a]=getfa2(b);
            }else if(v=='-'){
                cin>>a>>b;
                fa[a]=-getfa2(b);
            }for(int i=-n;i<=n;++i)
                dbg(i,getfa2(i));
            dbg("_____________________");
        }
        for(int i=1;i<=n;++i){
            dbg(i,getfa(i));
            if(getfa(i)==-i) 
                fa[i]=U; 
        }for(int i=1;i<=n;++i){
            if(getfa(i)==U) ++ans;
        }
        cout<<ans<<"\n";
    }
}
/*
1 1
10 10
F 7
- 10 4
- 7 4
U 6
+ 6 4
U 4
U 4
- 7 10
F 7
+ 4 1
*/