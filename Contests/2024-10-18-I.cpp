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
const int N=8e2+10;
#define int long long
int n,id[N][N],sc[N][N],w[N][N],p[N],y,oid[N],ow[N],ans,nn;
pair<int,int> osc[N];

signed main(){
//ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>p[i];
        for(int j=1;j<=p[i];++j){
            cin>>id[i][j];
        }for(int j=1;j<=p[i];++j)
            cin>>sc[i][j];
        for(int j=1;j<=p[i];++j)
            cin>>w[i][j];
    }cin>>y;
    for(int o=1;o<=n;++o){
        int score=-114;
        for(int i=1;i<=p[o];++i)
            oid[i]=id[o][i];
        sort(oid+1,oid+p[o]+1);
        for(int i=1;i<=p[o];++i){
            osc[i]={sc[o][i],oid[i]};
        }
        sort(osc+1,osc+p[o]+1,greater<pair<int,int> >());
        for(int i=1;i<=p[o];++i){
            if(osc[i].second==y){
                if(i==1){
                    score=1;
                    break;
                }
                score=osc[o].first;
                for(int j=i-1;j>=0;--j){
                    if(osc[j].first!=osc[i].first){
                        score=j+1;
                        break;
                    }
                }
                break;
            } 
        }
        if(score==-114){
            continue;
        } ++nn;
        // score++;
        ans+=w[o][score];
        // dbg(o,score,ans,"_");
    }
    if(ans%nn==0){
        cout<<ans;
        return 0;
    }
    cout<<ans/nn<<"+"<<ans%nn/(__gcd(ans%nn,nn))<<"/"<<nn/(__gcd(ans%nn,nn));
}
/*
1 5
30 32 10 22 20
10 30 30 30 40
1 2 3 4 5
22
*/