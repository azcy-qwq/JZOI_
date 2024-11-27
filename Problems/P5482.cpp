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
const int N=2e5+10;
const int inf=INT_MAX;
int n,cnt,a;
double b,c,ans,wht[N];
string s;
tree<pair<double,int>,null_type,less<pair<double,int> >,rb_tree_tag,tree_order_statistics_node_update > trl,trg;
bitset<N> bs;
bitset<N> pos;
signed main(){
    auto_init();
    // qfopen("P5482_3.in","P5482.out");
    // freopen("P5482_3.in","r",stdin);
//ios::sync_with_stdio(0);
    cin>>n;
    // trl.insert({inf,0});trg.insert({inf,0});
    // trl.insert({-inf,0});trg.insert({-inf,0});
    trl.insert({ inf,0});
    trg.insert({-inf,0});
    while(n--){
        cin>>s>>a;
        if(s=="Add"){
            cin>>b>>c;
            ++cnt;
            if(a==0){
                if(b>c){
                    trl.insert({-inf,cnt});
                    wht[cnt]=-inf;
                }else bs[cnt]=1;
                continue;
            }
            c-=b;
            c/=a;
            if(a>0){
                trl.insert({c,cnt});
                wht[cnt]=c;
            }else{
                trg.insert({c,cnt});
                wht[cnt]=c;
                pos[cnt]=1;
            }
        }else if(s=="Del"){
            if(bs[a]) continue;
            if(pos[a]){
                trg.erase({wht[a],a});
                bs[a]=1;
            }else{
                trl.erase({wht[a],a});
                bs[a]=1;
            }
        }else{
            // dbg("__________________________________________________");
            // dbg("  ",a);
            // dbg("  ",trl.size());
            // for(auto u:trl){
            //     cerr<<fixed<<setprecision(3);
            //     dbg("   ",u.first);
            // }
            // dbg("  ",trg.size());
            // for(auto u:trg){
            //     cerr<<fixed<<setprecision(3);
            //     dbg("   ",u.first);
            // }
            // dbg("  ",trl.order_of_key(*trl.upper_bound({a,inf})),(*trl.upper_bound({a,inf})).first);
            // dbg("  ",trg.order_of_key(*trg.lower_bound({a,-inf})),(*trg.lower_bound({a,-inf})).first);
            int xb=trg.size()-trg.order_of_key(*trg.upper_bound({a,inf})),
                xa=trl.order_of_key(*trl.lower_bound({a,-inf}));
            // dbg(trl.size(),trg.size(),xa,xb,(*trl.begin()).first,(*trg.rbegin()).first);
            // dbg("——————————————————————————————————————————————————");
            if(trl.empty()||(*trl.begin()).first>=a) 
                xa=0;
            if(trg.empty()||(*trg.rbegin()).first<=a) 
                xb=0;
            cout<<xa+xb<<'\n';
        }
    }
}
