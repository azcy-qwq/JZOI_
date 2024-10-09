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
long long a[8][9],n,m;
int main(){
//ios::sync_with_stdio(0);
cin>>n>>m;
    if(n>m)swap(n,m);
    a[1][1]=0;
    a[1][2]=2;
    a[1][3]=4;
    a[1][4]=6;
    a[1][5]=8;
    a[1][6]=10;
    a[1][7]=12;
    a[1][8]=14;
    a[2][2]=12;
    a[2][3]=30;
    a[2][4]=56;
    a[2][5]=90;
    a[2][6]=132;
    a[2][7]=182;
    a[2][8]=240;
    a[3][3]=104;
    a[3][4]=286;
    a[3][5]=700;
    a[3][6]=1598;
    a[3][7]=3488;
    a[3][8]=7390;
    a[4][4]=1228;
    a[4][5]=4862;
    a[4][6]=18368;
    a[4][7]=67206;
    a[4][8]=240180;
    a[5][5]=32000;
    a[5][6]=204294;
    a[5][7]=1274660;
    a[5][8]=7807790;
    a[6][6]=2228788;
    a[6][7]=23896710;
    a[6][8]=252488208;
    a[7][7]=441524056;
    a[7][8]=8056291934;
    cout<<a[n][m];
}