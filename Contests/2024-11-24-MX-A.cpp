#include<bits/stdc++.h>
using namespace std;
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
#define int long long
int T,ans,n,v[N],cnt[10];
signed main(){
    // priority_queue<int> q;
    // q.push(2);
    // q.push(3);
    // cout<<q.top();
    // return 0;
    qfopen("card3.in","card.out");
//ios::sync_with_stdio(0);
    auto_init();
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        queue<int> q3;
        multiset<int> q;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>v[i];
            if(v[i]==0) continue;
            if(v[i]%3) q.insert(v[i]);
            else q3.push(v[i]);
        }bool flag=1;
        while(flag){
            if((q.size()>=1)&&(q3.size()>=1)){
                ++ans;
                int a=q3.front(),b=*q.rbegin();
                q3.pop(),q.erase(q.find(b));
                a-=3,b--;
                if(a) q3.push(a);
                if(b>0&&b%3==0) q3.push(b);
                if(b%3!=0) q.insert(b);
            }else if(q.empty()&&(q3.size()>=2)){
                ++ans;
                int a=q3.front();
                q3.pop();
                int b=q3.front();
                q3.pop();
                a-=3,b--;
                if(a) q3.push(a);
                q.insert(b);
            }else if(q3.empty()&&(q.size()>=2)){
                int a=*q.rbegin();
                if(a<3) break;++ans;
                q.erase(q.find(*q.rbegin()));
                int b=*q.rbegin();
                q.erase(q.find(*q.rbegin()));
                a-=3;
                b--;
                if(a)
                    q.insert(a);
                if(b){
                    if(b%3==0)
                        q3.push(b);
                    else 
                        q.insert(b);
                }
                    
            }else break;
        }ans+=q.size();
        if(!q3.empty()) ans+=q3.front()/4+(q3.front()%4)/2+(q3.front()%2);
        cout<<ans<<'\n';
    }
}
/*
1
5
2 2 4 2 3
*/