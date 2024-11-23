#include<bits/stdc++.h>
#include<bits/extc++.h>
// using namespace __gnu_pbds;
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
int n,k,h[N];
typedef pair<int,int> pii;
// struct P4366
// {
//     long long sum1=0,sum2=0;
//     bitset<N> to;
//     __gnu_pbds::priority_queue<pii>::iterator it1[N];
//     __gnu_pbds::priority_queue<pii,greater<pii> >::iterator it2[N];
//     __gnu_pbds::priority_queue<pii> pq;//smaller
//     __gnu_pbds::priority_queue<pii,greater<pii> > pq2;//bigger
//     void balance(){
//         pii temp,temp2;
//         while(pq.size()<pq2.size()-1){
//             temp=pq2.top();
//             pq2.pop();
//             sum2-=h[temp.second];
//             sum1+=h[temp.second];
//             it1[temp.second]=pq.push(temp).m_p_nd;
//             to[temp.second]=0;
//         }while(pq2.size()<pq.size()){
//             temp=pq.top();
//             pq.pop();
//             sum2+=h[temp.second];
//             sum1-=h[temp.second];
//             it2[temp.second]=pq2.push(temp).m_p_nd;
//             to[temp.second]=1;
//         }while((!pq2.empty())&&(!pq.empty())&&pq2.top()<pq.top()){
//             temp=pq.top();
//             temp2=pq2.top();
//             sum2-=temp2.first;sum2+=temp.first;
//             sum1-=temp.first;sum1+=temp2.first;
//             to[temp.second]=1;
//             to[temp2.second]=0;
//             it1[temp2.second]=pq.push(temp2).m_p_nd;
//             it2[temp.second] =pq2.push(temp).m_p_nd;
//         }
//     }
//     void insert(int x){
//         if(pq.empty()){
//             it2[x]=pq2.push({h[x],x}).m_p_nd,to[x]=1,sum2+=h[x];
//             // return;
//         }
//         else if(h[x]>=pq.top().first)
//             it2[x]=pq2.push({h[x],x}).m_p_nd,to[x]=1,sum2+=h[x];
//         else
//             it1[x]=pq.push({h[x],x}).m_p_nd ,        sum1+=h[x];
//         balance();
//     }void del(int x){
//         if(to[x])
//             pq2.erase(it2[x]),sum2-=h[x];
//         else    
//             pq .erase(it1[x]),sum1-=h[x];
//         balance();
//     }
//     /* data */
// }a;

int ansd=INT_MAX,ansl,cur,ansx;
int main(){
    auto_init();
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>h[i];
    }
    // for(int i=1;i<=k;++i){
        // a.insert(i);
        // dbg(a.pq2.size(),a.sum2,'|',a.pq.size(),a.sum1);
    // }for(int l=1,r=k+1;r<=n+1;++r,++l){
        // dbg(a.pq2.top().first,a.pq2.size(),a.sum2,'|',a.pq.top().first,a.pq.size(),a.sum1);
        // cur=a.pq2.top().first*a.pq.size()-a.sum1+a.sum2-a.pq2.top().first*a.pq2.size();
        // if(ansd>cur) ansd=cur,ansl=l,ansx=a.pq2.top().first;
        // if(r>n) break;
        // a.del(l);
        // a.insert(r);
    // }cout<<ansd<<'\n';
    for(int i=1;i<=n;++i){
        if(i>=ansl&&i-ansl+1<=k)
            cout<<ansd<<'\n';
        else
            cout<<h[i]<<'\n';
    }
}