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
const int N=1e4+10;
#define int long long
int n,s[N],t[N],a[N],p[N],b[N],q[N],x;
bool check(int prd){
    int temp=0;
    for(int i=1;i<=n;++i){
        // dbg(i,temp,min(min(ceil(prd/a[i])*p[i],ceil(prd/b[i])*q[i]),min(floor(prd/a[i])*p[i]+(prd%a[i]!=0)*q[i],floor(prd/b[i])*q[i])+(prd%b[i]!=0)*p[i]));
        temp+=min(min(ceil((double)prd/a[i])*p[i],
        ceil((double)prd/b[i])*q[i]),
        min(floor((double)prd/a[i])*p[i]+(prd%a[i]!=0)*q[i],
        floor((double)prd/b[i])*q[i]+(prd%b[i]!=0)*p[i]) );
        // temp+=min((int)ceil((double)prd/a[i])*p[i],
        // (int)ceil((double)prd/b[i])*q[i]);
    }
    if(temp>x) return 0;
    else return 1;
}
signed main(){
//ios::sync_with_stdio(0);
    cin>>n>>x;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>p[i]>>b[i]>>q[i];
    }
    check(100);
    // system("pause");
    int l=0,r=(int)1e9+10,mid;
    while(r>=l){
        
        mid=(l+r)>>1;
        // dbg(l,r,mid,check(mid));
        if(!check(mid)) r=mid-1;
        else l=mid+1;
    }
    // dbg(mid,check(mid+1),check(mid));
    for(int i=mid+40;i>=mid-40;--i){
        if(check(i)){
            cout<<i;
            return 0;
        } 
    }
}