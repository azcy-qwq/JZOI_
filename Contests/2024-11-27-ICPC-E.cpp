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
int T,n,c[N],fa[N],f[N],len[N];
int getfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}void merge(int x,int y){
    x=getfa(x),y=getfa(y);
    fa[y]=x;
}
vector<int> son[N];
int main(){
ios::sync_with_stdio(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;++i)
            son[i].clear();
        for(int i=1;i<=n;++i){
            cin>>c[i];
            for(int j=1;j<=c[i];++j){
                cin>>c[0];
                son[i].push_back(c[0]);
            }
        }iota(fa+1,fa+n+1,1);int temp;
        for(int i=n;i>=1;--i)
            for(int u:son[i]){
                temp=getfa(u);
                merge(i,temp);
                f[temp]=i;
            }
        for(int i=2;i<=n;++i)
            cout<<f[i]<<" "<<i<<"\n";
    }
}
/*
1
8
2 2 6
2 4 5
2 7 8
0
0
1 7
0
0

*/