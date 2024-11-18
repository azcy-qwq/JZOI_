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
}using namespace azcy;
#define int long long
const int N=1e4+10;
int n,m;
pair<int,int> a[N],b[N],c[N];
typedef pair<int,int> pii;
bool cmp(pii a,pii b){
    if(a.first-a.second==b.first-b.second) return a<b;
    return a.first-a.second<b.first-b.second;
}
bool cmp2(pii a,pii b){
    return a.second>b.second;
}
queue<int> q;
bool flag1=1,flag2=1;
signed main(){
    // freopen("buy5.in","r",stdin);
ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        if(a[i].first!=a[i].second) flag1=0;
    }for(int i=1;i<=m;++i){
        cin>>b[i].first>>b[i].second;
        q.push(i);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;++i){
        c[i]={a[i].second,0};
    }
    sort(b+1,b+m+1,cmp2);
    // for(int i=1;i<=n;++i)
    //     dbg(i,a[i].first,a[i].second,"_");
    // for(int i=1;i<=m;++i){
    //     dbg(i,b[i].first,b[i].second);
    // }
    if(n>=1e5){
        long long ans=0;
        {
            for(int i=1;i<=n;++i)
                ans+=a[i].first;
            for(int i=1;i<=min(n,m);++i){
                ans-=b[i].second;
            }
            cout<<ans;
            return 0;
        }
        
    }
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        if(temp==0) continue;
        // dbg(temp);
        for(int i=1;i<=n;++i){
            if(b[temp].first<=a[i].first){
                if(a[i].first-b[temp].second<c[i].first){
                    dbg(c[i].second);
                    q.push(c[i].second);
                    c[i].first=a[i].first-b[temp].second;
                    c[i].second=temp;
                    break;
                }
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=n;++i){
        ans+=c[i].first;
        // dbg(i,c[i].first,c[i].second,a[i].first,a[i].second);
    }
    cout<<ans;
}
/*

1 2 0 4 2 
2 1 3 5 2
3 3 0 6 3
4 4 0 6 4
5 3 4 7 5

*/