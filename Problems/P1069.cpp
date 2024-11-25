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
const int N=1e5+10;
const int maxV=5e4+10;
#define int long long
bitset<maxV> vis;
vector<int> v;
void init(){
    for(int i=2;i<maxV;++i){
        if(vis[i]) continue;
        v.push_back(i);
        for(int j=i+i;j<maxV;j+=i){
            vis[j]=1;
        }
    }
}
int n,m1,m2,s[N],ans=LONG_LONG_MAX,ps,cnt,p[N],pm[N];
signed main(){
//ios::sync_with_stdio(0);
    init();
    // cout<<v.size();
    cin>>n>>m1>>m2;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    for(int ss:v){
        while(m1%ss==0) 
            m1/=ss,pm[cnt]++;
        ++cnt;
    }
    for(int i=1,curt;i<=n;++i){
        curt=cnt=0;
        memset(p,0,sizeof(p));
        for(int ss:v){
            while(s[i]%ss==0)
                s[i]/=ss,p[cnt]++;
            ++cnt;
            if(s[i]==1) break;
        }
        for(int j=0;j<v.size();++j){
            int t1=v[j];
            if(pm[j]==0) continue;
            if(p[j]==0){
                curt=LONG_LONG_MAX;
                break;
            }
            curt=maxm(curt,ceil((double)m2*pm[j]/p[j]));
        }ans=minm(ans,curt);
    }
    if(ans>=LONG_LONG_MAX)
        cout<<"-1\n";
    else
        cout<<ans;
}