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
        static std::streambuf * outbuf = cout.rdbuf();
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
        static std::streambuf * outbuf = cout.rdbuf();
        outbuf -> sputc(ch);
    }
    template < typename T > inline void put(const char ch, T x) {
        static std::streambuf * outbuf = cout.rdbuf();
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
        cout<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cout<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cout<<first<<" ";
        dbgo(rest...);
        cout<<"\n";
    }//made by _azcy
	template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    }
}using namespace azcy;
const int N=1e4+10;

long long ans,a,b,n,seed,inp,score;
int main(){
//	ios::sync_with_stdio(0);
    dbg("Input Count of Problems and Random-Seed.");
    cin>>n>>seed;
    mt19937 rnd(seed);
    system("pause");
    for(int i=1;i<=n;++i){
        system("cls");
        dbg(i,"/",n);
        a=rnd()%2000;
        b=rnd()%2200;
        dbg("Score:",score);
        dbg(a,"x",b,"=");
        ans=a*b;
        cin>>inp;
        if(inp==ans) ++score;
    }
    system("cls");
    _sleep(200);
    cout<<"\nFinal Score:"<<score<<endl;
    cout<<"Time:"<<(double)clock()/CLOCKS_PER_SEC<<endl;
    cout<<"MUltiScore:"<<(double)pow(0.98,(double)clock()/CLOCKS_PER_SEC/(double)n)*(double)score/n*100;
    system("pause");
    system("pause");
    system("pause");
}