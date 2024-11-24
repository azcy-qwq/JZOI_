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
const int N=1e4+10;
const int maxc=(double)CLOCKS_PER_SEC*11.94;
#define ks if(clock()>maxc) return
int a[14][14][14],n,xa,ya,za,cnt,debcnt,fist=1;
long long ans=INT_MAX;
bitset<30> visx,visy,visz;
// bool visx[30],visy[30],visz[30];
struct dot{
    int x,y,z;
    bool operator<(const dot XD)const{
        return x<XD.x;
    }
};
pair<int,dot> d[N];
void ida(int step,long long val){
    
    if(step>=n){
        ans=minm(ans,val);
        return ;
    }
    ++debcnt;
    ks;
    dot skadi;
    int temp=fist;
    for(int i=fist;i<=cnt;++i){
        ks;
        skadi=d[i].second;
        if(visx[skadi.x]||visy[skadi.y]||visz[skadi.z]) continue;
        if(val+d[i].first>=ans) continue;
        fist=i+1;
        visx[skadi.x]=visy[skadi.y]=visz[skadi.z]=1;
        ida(step+1,val+d[i].first);
        visx[skadi.x]=visy[skadi.y]=visz[skadi.z]=0;
    }fist=temp;
}
int main(){
        freopen("icpc.in","r",stdin);
ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k){
                cin>>xa;
                d[++cnt]={xa,{i,j,k}};
            }
    }sort(d+1,d+n+1);
    ida(0,0);
    dbg(debcnt,(double)clock()/CLOCKS_PER_SEC);
    cout<<ans;
}