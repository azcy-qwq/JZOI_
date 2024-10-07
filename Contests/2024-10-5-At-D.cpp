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
double calc(double x1,double _y1,double x2,double _y2){
    double dx=x2-x1,dy=_y2-_y1;
    return sqrt(dx*dx+dy*dy);
}
int x[N][2],y[N][2],n,s,t,a[N<<2];
long double ans=1e18;
int main(){
//ios::sync_with_stdio(0);
    cin>>n>>s>>t;
    for(int i=1;i<=n;++i)
        cin>>x[i][0]>>y[i][0]>>x[i][1]>>y[i][1];
    for(int i=1;i<=n;++i)
        a[i]=i;
    do{
        long double temp=0;
        long double prvx=0,prvy=0,curx=0,cury=0;
        for(int i=0;i<(1<<(n));i++){
            temp=0;
            // dbg(i);
            // if(a[1]==2&&a[2]==1&&a[3]==3&&i==5) 
            //     dbg(a[1],a[2],a[3],i,temp);
            for(int j=1;j<=n;++j){
                
                if(j==1) prvx=prvy=0;
                else if(i&(1<<(j-2))) prvx=x[a[j-1]][1],prvy=y[a[j-1]][1];
                else prvx=x[a[j-1]][0],prvy=y[a[j-1]][0];

                if(i&(1<<(j-1))) curx=x[a[j]][0],cury=y[a[j]][0];
                else curx=x[a[j]][1],cury=y[a[j]][1];
                temp+=calc(curx,cury,prvx,prvy)/s;
                temp+=calc(x[a[j]][1],y[a[j]][1],x[a[j]][0],y[a[j]][0])/t;
            }
            // 
            ans=min(ans,temp);
        }
    }while(next_permutation(a+1,a+n+1));
    cout.fixed;
    cout<<setprecision(26)<<ans;
}