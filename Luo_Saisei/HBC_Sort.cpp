#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
const int N=1e6+10;
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
template<typename T>
bool check(T *x,int n){
    for(int i=1;i<n;++i)
        if(x[i]<x[i-1]) 
            return false;
    return true;
}
template<typename T>
int HBC_Sort(T *x               //First Pointer of the Array
            ,int n              //Length
            ){
    if(n==1) return 0;          // No Need for Sort
    random_device rd;           //Device-Based RealRandom Engine
    mt19937 rnd(rd()+time(0));  //32-bit Random Engine
    bool flag=check(x,n);       //If the Array is Sorted 
    int cnt=0,a,b;
    while(!flag){
        a=rnd()%n,b=rnd()%n;
        if(a>b) swap(a,b);      //a<=b
        ++cnt;
        if(x[a]>x[b]) swap(x[a],x[b]);  //if unsorted
        if(cnt%n==0) flag=check(x,n);   //Update
    }return cnt;
}
int n,a[N];
tree<int,null_type,less<int> > tr;
int main(){
    qfopen("aa.in","aa.out");
    auto_init();
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        tr.insert(a[i]);
    // stable_sort(a+1,a+n+1);
    // HBC_Sort(a+1,n);
    // priority_queue<int,vector<int> ,greater<int> >pq;
    // for(int i=1;i<=n;++i)
    //     pq.push(a[i]);
    for(int i=1;i<=n;++i){
        if(tr.empty()) break;
        cout<<(*tr.begin())<<' ';
        tr.erase(tr.begin());
    }
        
    dbg(clock());
}