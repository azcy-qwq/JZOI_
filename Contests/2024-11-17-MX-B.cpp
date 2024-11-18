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
    }template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=1e5+10;
typedef long double ld;
typedef long long ll;
const int n2=28;
const int n3=18;
const double inf=1e63;
bool M1;
int n,q,p[N],t[N],x[N];
double qry;
double p2[100],p3[100],ans;
double dp[N][n2+1][n3+1];
bool M2;
#define See_Memory cerr<<abs(&M1-&M2)/1024.0/1024.0<<"MB\n"
void init(){
    p2[0]=1;
    for(int i=1;i<=58;++i)
        p2[i]=p2[i-1]*2;
    p3[0]=1;
    for(int i=1;i<=38;++i)
        p3[i]=p3[i-1]*3;
}
inline double calc(int id,double speed){
    return (p[id]-p[id-1])/speed;
}
void display(){
    for(int i=0;i<=n;++i){
        cerr<<i<<":\n";
        for(int j=0;j<=n2;++j){
            for(int k=0;k<=n3;++k){
                if(dp[i][j][k]<INT_MAX)
                    dbg("  ",p3[k]*p2[j],dp[i][j][k]);
            }
        }
        cerr<<'\n';
    }
}
bool flag8=1,flag4=0;
int main(){
// ios::sync_with_stdio(0);
    auto_init();
    // See_Memory;
    // return 0;
    // qfopen("ship4.in","ship.out");
    init();
    cin>>n>>q;
    // See_Memory;
    for(int i=1;i<=n;++i){
        cin>>p[i]>>t[i]>>x[i];
        // if(x[i]!=1) flag4=0;
        // if(x[i]==3) flag8=0;
    }if(flag4){
        for(int i=1;i<=1;++i){
            cin>>qry;
            cout<<qry<<"\n";
        }
        return 0;
    }for(int i=0;i<=n;++i)
        for(int j=0;j<=n2;++j)
            for(int k=0;k<=n3;++k)
                dp[i][j][k]=LONG_LONG_MAX;
    dp[0][0][0]=0;
    for(int i=1;i<=n;++i){
        if(x[i]==2){
            for(int j=0;j<=n2;++j){
                for(int k=0;k<=n3;++k){
                    dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j][k]+calc(i,p2[j]*p3[k]));
                    if(j>0) dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j-1][k]+calc(i,p2[j-1]*p3[k])+t[i]);
                }
            }
        }else if(x[i]==3){
            for(int j=0;j<=n2;++j){
                for(int k=0;k<=n3;++k){
                    dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j][k]+calc(i,p2[j]*p3[k]));
                    if(k>0) dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j][k-1]+calc(i,p2[j]*p3[k-1])+t[i]);
                }
            }
        }else if(x[i]==4){
            for(int j=0;j<=n2;++j){
                for(int k=0;k<=n3;++k){
                    dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j][k]+calc(i,p2[j]*p3[k]));
                    if(j>1) dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j-2][k]+calc(i,p2[j-2]*p3[k])+t[i]);
                }
            }
        }else{
            for(int j=0;j<=n2;++j){
                for(int k=0;k<=n3;++k){
                    dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j][k]+calc(i,p2[j]*p3[k]));
                    // if(j>1) dp[i][j][k]=minm(dp[i][j][k],dp[i-1][j-2][k]+calc(i,p2[j-2]*p3[k])+t[i]);
                }
            }
        }
    }
    // display();
    for(int i=1;i<=q;++i){
        cin>>qry;
        int x=upper_bound(p+1,p+n+1,qry)-p-1;
        ans=inf;
        // cout<<x<<'\n';
        for(int j=0;j<=n2;++j){
            for(int k=0;k<=n3;++k){
                ans=minm(ans,dp[x][j][k]+(qry-p[x])/(p2[j]*p3[k]));
            }
        }
        cout<<fixed<<setprecision(12)<<ans<<'\n';
    }
    // cerr<<(double)clock()/CLOCKS_PER_SEC;
}