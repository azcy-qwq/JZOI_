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
const int N=1024;
#define ull unsigned long long
ull n,m,k;
ull a[N][N],miku[N][N],ans;
inline void init(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			miku[i][j]=miku[i-1][j]-miku[i-1][j-1]+miku[i][j-1]+a[i][j];
		}
	}
}
inline ull query(int x1,int x2,int y1,int y2){
	if(x1>x2) swap(x1,x2);
	if(y1>y2) swap(y1,y2);
	return miku[x2][y2]-miku[x1-1][y2]-miku[x2][y1-1]+miku[x1-1][y1-1];
}
inline ull qpow(ull x, ull y)
{
    ull t = x, ans = 1;
    while (y)
    {
        if (y & 1)
            ans *= t;
        t *= t;
        y >>= 1;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>a[i][j];
			}
		}
	
	init();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int o=i;o<=n;++o)
				for(int l=j;l<=n;++l)
					ans+=qpow(query(i,o,j,l),k);
	put(ans);
	return 0;
}
