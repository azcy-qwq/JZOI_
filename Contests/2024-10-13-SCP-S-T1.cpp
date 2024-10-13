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
const int N=1e6+10;
#define int long long
int a[N],n,cnt[N],c,T,v[12],ans,dp[7],dpa;
char ch;
string s;
signed main(){
    // freopen("bargain5.in","r",stdin);
    // freopen("bargain.out","w",stdout);
ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>s;
        ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<s.length();++i){
            // cin>>ch;
            a[i+1]=s[i]-'0';
            cnt[s[i]-'0']++;
        }
        for(int i=1;i<=9;++i)
            cin>>v[i];
        for(int i=1;i<=9;++i){
            ans+=cnt[i]*v[i];
        }
        s='#'+s;
        dp[0]=0;
        dpa=0;
        for(int i=1;i<=5;++i)
            dp[i]=INT_MAX;
        for(int i=s.length()-1;i>=1;--i){
            for(int j=min((int)5,(int)s.length()-i);j>=1;--j){
                dp[j]=min(dp[j],dp[j-1]-v[a[i]]+(int)pow(10,j-1)*(a[i]));
                // dbg(i,j,dp[j]);
            }
        }
        for(int i=0;i<=5;++i)
            dpa=min(dpa,dp[i]);
        // dbg(ans,dpa,"_");
        cout<<ans+dpa<<"\n";
    }
    // system("pause");
}
/*
0
3
123
10 10 10 10 10 10 10 10 10 
1121
2 1 2 2 2 2 2 2 2
123
15 50 50 8 0 0 0 0 0
*/