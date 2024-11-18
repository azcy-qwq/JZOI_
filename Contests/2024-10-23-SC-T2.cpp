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
const int N=1e2+10;
struct rect{
    int lx=INT_MAX,rx=INT_MIN,ly=INT_MAX,ry=INT_MIN;
    bool used=0;
    void update(int x,int y){
        used=1;
        lx=min(x,lx);
        ly=min(y,ly);
        rx=max(x,rx);
        ry=max(y,ry);
    }
}a[N];
int n,k,ans=INT_MAX;
pair<int,int> pt[N];
inline int calc(){
    int temp=0;
    for(int i=1;i<=k;++i){
        if(a[i].used==0) continue;
        temp+=(a[i].rx-a[i].lx)*(a[i].ry-a[i].ly);
    }
    return temp;
}
inline bool cd(int x1,int x2,int y1,int y2){
    return (!(x2>y1||x1>y2));
}
bool check(){
    for(int i=1;i<=k;++i){
        for(int j=i+1;j<=k;++j){
            if(cd(a[i].lx,a[j].lx,a[i].rx,a[j].rx)&&cd(a[i].ly,a[j].ly,a[i].ry,a[j].ry))
                return 1;
        }
    }
    return 0;
}
void dfs(int id){
    if(clock()>(double)CLOCKS_PER_SEC*0.95) return;
    if(check()||calc()>=ans) return;
    if(id>n){
        ans=min(ans,calc());
        return ;
    }
    rect b;
    for(int i=1;i<=k;++i){
        b=a[i];
        a[i].update(pt[id].first,pt[id].second);
        // dbg(id,i,ans,"1:",a[1].lx,a[1].rx,a[1].ly,a[1].ry,"2:",a[2].lx,a[2].rx,a[2].ly,a[2].ry);
        if(check()){
            a[i]=b;
            continue;
        } 
        dfs(id+1);
        a[i]=b;
    }
}
int main(){
ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>pt[i].first>>pt[i].second;
    sort(pt+1,pt+n+1);
    dfs(1);
    cout<<ans;
}