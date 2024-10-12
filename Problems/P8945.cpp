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
// #define int long long
const int N=1.2e7+10;
int n,k,a[N],qzh1[N],qzh2[N],cnt[N],m2[N],m1[N],qzh3[N],ans=INT_MIN;
signed main(){
ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        qzh1[i]=qzh1[i-1]+(a[i]==0)+a[i];
        qzh2[i]=qzh2[i-1]+a[i];
        cnt[i]=cnt[i-1]+(a[i]==0);
        // dbg(i,cnt[i],qzh1[i],qzh2[i]);
    }
    m2[n+1]=INT_MIN;
    for(int i=n;i>=1;--i){
        qzh3[i]=qzh3[i+1]+a[i];
        m2[i]=max(m2[i+1],qzh2[i]);
        // dbg(i,m2[i]-qzh2[i]);
    }
    for(int i=1;i<=n;++i){
        m1[i]=max(m1[i-1],qzh3[i]);
    }for(int i=1;i<=n;++i){
        m1[i]-=qzh3[i],m2[i]-=qzh2[i];
        dbg(i,m1[i],m1[i]+qzh3[i],qzh3[i],m2[i]);
    }
       
    for(int l=1,r=1;r<=n&&l<=n;++l){
        while(cnt[r]-cnt[l-1]<k||r<l){
            if(r>n) break;
            ++r;
        }
        if(r>n) break;
        if(ans<m1[l]+qzh1[r]-qzh1[l-1]+m2[r])
            dbg(l,r);
        ans=max(m1[l]+qzh1[r]-qzh1[l-1]+m2[r],ans);
    }
    cout<<ans;
}
/*
20 3
1 0 -1 0 0 -1 0 1 0 0 -1 0 -1 0 0 1 -1 -1 1 0
*/