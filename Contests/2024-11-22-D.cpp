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
int n,a[N],ans;
map<int,bool> s;
deque<int> q;
int x;
int main(){
    freopen("aa.in","r",stdin);
    auto_init();
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    // cout<<a[362];
    // dbg(a[415],a[417]);
    for(int i=1;i<=n;i+=2){
        // if(i==399) 
            // system("pause"),dbg("a");
        if(a[i]!=a[i+1]){
            // x=0;
            q.clear();
            s.clear();
            continue;
        }else if(s[a[i]]){
            while(1){
                if(q.front()==a[i]){
                    q.pop_front();
                    break;
                }s[q.front()]=0;q.pop_front();
            }
            q.push_back(a[i]);
            ans=maxm(ans,q.size()*2);
        }else{
            s[a[i]]=1;
            q.push_back(a[i]);
            // if(ans<q.size()*2) cout<<i<<'\n';
            ans=maxm(ans,q.size()*2);
        }
    }q.clear();
    s.clear();
    for(int i=2;i<=n;i+=2){
        if(a[i]!=a[i+1]){
            q.clear();
            s.clear();
            continue;
        }else if(s[a[i]]){
            while(1){
                if(q.front()==a[i]){
                    q.pop_front();
                    break;
                }s[q.front()]=0;q.pop_front();
            }
            
            q.push_back(a[i]);
            ans=maxm(ans,q.size()*2);
        }else{
            s[a[i]]=1;
            q.push_back(a[i]);
            ans=maxm(ans,q.size()*2);
        }
    }cout<<ans;
}/*
30
22 22 3 8 7 4 4 5 5 2 2 3 3 2 2 6 6 9 9 11 11 22 22 33 44 55 33 44 44 33 33
10 10 8 8 18 18 16 16 9 9 19 19 9 9 19 19 9 9 13 13 8 8 18 18 7 7 17 17 18 18 10 10
1 1 0 0 7 7 19 19 0 0 1 1 9 9 8 8 16 16 17 17 18 18 0 0 14 14 3 3 10 10 8 8
*/