#include<bits/stdc++.h>
#pragma GCC optimize(2)
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
    template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }template<typename T1,typename T2>
    inline T1 maxm(T1 a,T2 b){
        return (a>b)?(a):(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }template<typename T1,typename T2>
    inline T1 minm(T1 a,T2 b){
        return (a<b)?a:(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=1e4+10;
typedef long long ll;
int tim;
int n;
ll x;
ll ans;
// template<typename T>
// T read(T &x){
//     cin>>x;
//     return x;
// }
// inline int read(){//Original
//     int x;
//     cin>>x;
//     return x;
// }
inline ll read(){
	ll a=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch<='9'&&ch>='0';ch=getchar())a=a*10+ch-'0';
	return a*f;
}
// namespace Read{
// 	const ll S=(1<<20)+5;char B[S],*H,*T;
// 	inline ll gc(){ 
// 		if(H==T) T=(H=B)+fread(B,1,S,stdin);
// 		return (H==T)?EOF:*H++; 
// 	}
// 	inline ll read(){ 
// 		ll x,ch;
// 		while((ch=gc())<'0'||ch>'9');x=ch^'0';
// 		while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');
// 		return x; 
// 	}
// }using Read::read;

char tmp[100000],*p(0),*top(0);
#define gtc() (p==top && (top=(p=tmp)+fread(tmp,1,100000,stdin)),*p++)
ll fr(){
    ll x;
	char c;
	bool f=0;
	while((c=gtc())<'0')if(c=='-'){f=1;}
	x=c^'0';
	while((c=gtc())>='0')x=x*10+(c^'0');
	return f?(~x+1):x;
}

void solve1(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        ans+=x;
    }
}
void solve2(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        ans+=x;
    }
}
void solve3(){
    auto_init();
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x;
        ans+=x;
    }
}
void solve4(){
    n=read();
    for(int i=1;i<=n;++i){
        x=read();
        ans+=x;
    }
}
void solve5(){
    auto_init();
    redi(n);
    for(int i=1;i<=n;++i){
        redi(x);
        ans+=x;
    }
}void solve6(){
    n=fr();
    for(int i=1;i<=n;++i){
        x=fr();
        ans+=x;
    }
}
int main(){
//ios::sync_with_stdio(0);
    qfopen("data.in","data.out");
    tim=clock();
    // solve1();
    // solve2();
    // solve3();
    // solve4();
    // solve5();
    // solve6();
    cerr<<clock()-tim<<'\n';
    cout<<ans;
}