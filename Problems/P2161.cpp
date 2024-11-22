#include<bits/stdc++.h>
#include<bits/extc++.h>
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
struct seg{
    int l,r;
    bool operator<(const seg &x)const{
        return r<x.l;
    }bool operator>(const seg &x)const{
        return l>x.r;
    }bool operator==(const seg &x)const{
        return !((x<*this)||(x>*this));
    }
};
using namespace __gnu_pbds;
tree<seg,null_type,less<seg>,rb_tree_tag,tree_order_statistics_node_update> tr;
int n,x,y,a1,a2;
char ch;
int main(){
    auto_init();
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>ch;
        if(ch=='A'){
            a1=tr.size();
            cin>>x>>y;
            auto it=tr.find((seg){x,y});
            while(it!=tr.end()){
                tr.erase(it);it=tr.find((seg){x,y});
            }tr.insert((seg){x,y});
            a2=tr.size();
            cout<<a1-a2+1<<'\n';
        }else{
            cout<<tr.size()<<'\n';
        }
    }
}