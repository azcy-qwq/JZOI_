#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
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
struct tri{
    int lx,rx,uy,dy;
    bool operator<(const tri& x)const{
        return rx<=x.lx&&uy<=x.dy;
    }bool operator>(const tri& x)const{
        return lx>=x.rx&&dy>=x.uy;
    }bool operator==(const tri& x)const{
        return !(*this<x||*this>x);
    }
};
const int inf=INT_MAX>>1;
tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> tr;
long long ans;
pair<int,int> pii[N];
int n,k,x,y,flag;
int main(){
    // freopen("P2202_3.in","r",stdin);
    auto_init();
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>pii[i].first>>pii[i].second;
    sort(pii+1,pii+n+1);
    tr.insert({-inf,0});
    tr.insert({inf,0});
    for(int i=1,l=1;i<=n;++i){
        if(flag>=2) break;
        while(i>=l&&pii[i].first-pii[l].first>=k){
            tr.erase({pii[l].second,l}),++l;
        }
        dbg(i,l,tr.size());
        if((flag<2)){
            auto it=tr.lower_bound({pii[i].second,i});
            // dbg(" A",(*it).first,(*it).second);
            if(abs((*it).first-pii[i].second)<k){
                // dbg("  A1",(*it).first,(*it).second);
                ++flag;
                if(flag==1)
                    ans=abs(k-abs(pii[(*it).second].first-pii[i].first))*
                    abs(k-abs(pii[(*it).second].second-pii[i].second));
                ++it;
                if(abs((*it).first-pii[i].second)<k) 
                    ++flag;
                --it;
            }--it;
            // dbg(" B",(*it).first,(*it).second);
            if(abs((*it).first-pii[i].second)<k){
                // dbg("  B1",(*it).first,(*it).second);
                ++flag;
                if(flag==1)
                    ans=abs(k-abs(pii[(*it).second].first-pii[i].first))*
                    abs(k-abs(pii[(*it).second].second-pii[i].second));
                --it;
                if(abs((*it).first-pii[i].second)<k) 
                    ++flag;
                ++it;
            }
        }tr.insert({pii[i].second,i});
    }if(flag==0){
        cout<<"0\n";
    }else if(flag==1){
        cout<<ans<<"\n";
    }else{
        cout<<"-1\n";
    }
}