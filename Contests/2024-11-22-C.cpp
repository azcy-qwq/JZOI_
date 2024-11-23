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
int n,hzh1[N],hzh2[N],ans=1;
string s;
int main(){
//ios::sync_with_stdio(0);
    cin>>n;
    cin>>s;
    s='#'+s;
    for(int i=n;i>=1;--i){
        if(s[i]!='1') hzh1[i]=0;
        else hzh1[i]=hzh1[i+1]+1;
        if(s[i]!='2') hzh2[i]=0;
        else hzh2[i]=hzh2[i+1]+1;
    }for(int cur=1;cur<=n;){
        if(s[cur]=='/') 
            ++cur;
        else if(s[cur]=='2') 
            cur+=hzh2[cur];
        else{
            int a1,a2;
            a1=hzh1[cur];
            cur+=hzh1[cur];
            if(s[cur]!='/') continue;
            ++cur;
            a2=hzh2[cur];
            cur+=hzh2[cur];
            ans=maxm(ans,minm(a1,a2)*2+1);
        }
    }cout<<ans;
}//26 11222/11/2/12111/1222122/211