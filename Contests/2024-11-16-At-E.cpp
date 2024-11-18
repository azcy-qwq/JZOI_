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
const int N=1e6+10;
int l[N],r[N],fa[N],c[N],n,q,op,opt,cnt[N],col;
int getfa(int id){
    if(id==fa[id]) return id;
    return fa[id]=getfa(fa[id]);
}
void combine(int x,int y){
    x=getfa(x),y=getfa(y);
    l[x]=min(l[x],l[y]);
    r[x]=max(r[x],r[y]);
    fa[y]=x;
}
int getlen(int id){
    id=getfa(id);
    return r[id]-l[id]+1;
}
int main(){
        auto_init();
//ios::sync_with_stdio(0);
    cin>>n>>q;
    // iota(fa+1,fa+n+1,1);
    for(int i=1;i<=n;++i)
        l[i]=r[i]=fa[i]=c[i]=i,cnt[i]=1;
    while(q--){
        cin>>op;
        if(op==1){
            cin>>opt>>col;
            opt=getfa(opt);
            cnt[c[opt]]-=getlen(opt);
            c[opt]=col;
            cnt[col]+=getlen(opt);
            int ll=getfa(l[opt]-1),rr=getfa(r[opt]+1);
            if(ll&&c[ll]==c[opt]){
                combine(ll,opt);
            }if(rr&&c[rr]==col){
                combine(rr,opt);
            }
        }else{
            cin>>opt;
            cout<<cnt[opt]<<'\n';
        }
    }
}