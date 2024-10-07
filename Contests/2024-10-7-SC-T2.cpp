#include<bits/stdc++.h>
using namespace std;
#define int long long
namespace IN {
    #define MAX_INPUT 25000003
    #define getc()(p1 == p2 && (p2 = (p1 = buf) + inbuf -> sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : * p1++)
    char buf[MAX_INPUT], * p1, * p2;
    template < typename T > inline bool redi(T & x) {
        static std::streambuf * inbuf = cin.rdbuf();
        x = 0;
        register int f = 0, flag = false;
        register char ch = getc();
        while (!std::isdigit(ch)) {
            if (ch == '-') f = 1;
            ch = getc();
        }
        if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc(), flag = true;
        while (std::isdigit(ch)) {
            x = x * 10 + ch - 48;
            ch = getc();
        }
        x = f ? -x : x;
        return flag;
    }
    template < typename T, typename...Args > inline bool redi(T & a, Args & ...args) {
        return redi(a) && redi(args...);
    }
    #undef getc
}
 
namespace OUT {
    template < typename T > inline void put(T x) {
        static std::streambuf * outbuf = cerr.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf -> sputc('-');
            x = -x;
        }
        if (!x) {
            outbuf -> sputc('0');
            outbuf -> sputc('\n');
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf -> sputc(stack[top]);
            --top;
        }
        outbuf -> sputc('\n');
    }
    inline void putc(const char ch) {
        static std::streambuf * outbuf = cerr.rdbuf();
        outbuf -> sputc(ch);
    }
    template < typename T > inline void put(const char ch, T x) {
        static std::streambuf * outbuf = cerr.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf -> sputc('-');
            x = -x;
        }
        if (!x) {
            outbuf -> sputc('0');
            outbuf -> sputc(ch);
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf -> sputc(stack[top]);
            --top;
        }
        outbuf -> sputc(ch);
    }
    template < typename T, typename...Args > inline void put(T a, Args...args) {
        put(a);
        put(args...);
    }
    template < typename T, typename...Args > inline void put(const char ch, T a, Args...args) {
        put(ch, a);
        put(ch, args...);
    }
}
using IN::redi;
using OUT::put;
using OUT::putc;
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
}using namespace azcy;
const int N=1e4+10;
priority_queue<int,vector<int>,greater<int> > ans;
int n,m,k,S,T,u,v,w,dp[N];
vector<int> nei[N];
vector<int> val[N];
bitset<N> vis;
bitset<N> ava;
bool dfs(int id,int fa){
    vis[id]=1;
    if(id==T) {
        ava[id]=1;
        return 1;
    }
    bool flag=0;
    for(int u:nei[id]){
        if(u==fa||vis[u]) continue;
        flag|=dfs(u,id);
    }
    ava[id]=flag;
    return flag;
}
vector<int> circ;
void df5(int id,int fa,int v){
    if(id==T){
        ans.push(v);
        // if(ans.size()>=k) return ;
        // return ;
    } 
    if(vis[id]==1){
        circ.push_back(v-dp[id]);
        return ;
    }
    vis[id]=1;
    int temp=0;
    for(int u:nei[id]){
        if(ava[id]==0) continue;
        df5(u,id,v+val[id][temp]);
        ++temp;
    }
    dp[id]=v;
}
const int N2=2e6+10;
int ev[N2];
void eth(){
    int cnt=0;
    sort(circ.begin(),circ.end());
    while(ans.size())
        ev[ans.top()]=1,ans.pop();
    for(int i=1;i<=100000;++i){
        if(ev[i]==0) continue;
        cnt+=ev[i];
        if(k<=cnt){
            cout<<i;
            exit(0);
        }
        for(int k=0;k<circ.size();++k){
            for(int j=i+circ[k];j<=100000;j+=circ[k])
                ev[j]+=ev[i];
        }
    }
    if(circ.size()==0){
        cout<<"-1\n";
        exit(0);
    }
    cout<<k-cnt+100000;
    exit(0);
}
signed main(){
ios::sync_with_stdio(0);
    cin>>n>>m>>k>>S>>T;
    for(int i=1;i<=m;++i){
        cin>>u>>v>>w;
        nei[u].push_back(v);
        val[u].push_back(w);
    }
    dfs(S,S);
    vis.reset();
    df5(S,S,0);
    if(ans.size()==0){
        cout<<"-1";
        return 0;
    }
    eth();
}