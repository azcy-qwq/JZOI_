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
    }template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=2e3+2;
typedef long long ll;
int n,m,m1[N][N],m2[N][N],qzh1[N][N],qzh2[N][N],xa,xb,ya,yb;
int main(){
    qfopen("matrix.in","matrix.out");
    auto_init();
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>m1[i][j];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>m2[i][j];
    for(int j=1;j<=n;++j)
        for(int i=1;i<=n;++i){
            qzh1[i][j]=qzh1[i-1][j]+m1[i][j];
        }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            qzh2[i][j]=qzh2[i][j-1]+m2[i][j];
    while(m--){
        cin>>xa>>ya>>xb>>yb;
        if(xa>xb) swap(xa,xb);
        if(ya>yb) swap(ya,yb);
        ll ans=0;
        for(int i=1;i<=n;++i){
            // dbg("AAA",qzh1[xb][i]-qzh1[xa-1][i],qzh2[i][yb]-qzh2[i][ya-1]);
            ans+=(qzh1[xb][i]-qzh1[xa-1][i])*(qzh2[i][yb]-qzh2[i][ya-1]);
        }cout<<ans<<'\n';
    }
}