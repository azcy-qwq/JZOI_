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
const double eps=1e-9;
const int N=1e6+10;
struct car{
    long double d,a,v0;
}inp[N],cs[N];
int T,n,m,L,V,p[N],ans,top,stop,aa,bb,cc;
pair<int,int> seg[N];
long double calc(car ca,long double x){
    if(2*ca.a*(x-ca.d)+ca.v0*ca.v0<=0) return 0;
    return sqrt(2*ca.a*(x-ca.d)+ca.v0*ca.v0);
}
int main(){
ios::sync_with_stdio(0);
    // freopen("detect5.in","r",stdin);
    // freopen("detect5.out","w",stdout);
    cin>>T;
    while(T--){
        ans=stop=0;
        bool scflag=1;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;++i){
            // cin>>inp[i].d>>inp[i].v0>>inp[i].a;
            cin>>aa>>bb>>cc;
            inp[i].d=aa;
            inp[i].v0=bb;
            inp[i].a=cc;
            if(inp[i].a) scflag=0;
        }for(int i=1;i<=m;++i){
            cin>>aa;
            p[i]=aa;
            // cin>>p[i];
        }for(int i=1;i<=n;++i){
            if(inp[i].a>=0){
                // double temp=calc(inp[i],p[m]);
                double tempp=calc(inp[i],p[m]);
                if(calc(inp[i],p[m])-eps<=V||inp[i].d>p[m]) continue;
                if(inp[i].a==0) seg[++stop].first=lower_bound(p+1,p+m+1,inp[i].d)-p;
                else seg[++stop].first=upper_bound(lower_bound(p+1,p+m+1,inp[i].d),p+m+1,(V*V-inp[i].v0*inp[i].v0)/inp[i].a/2.0+inp[i].d)-p;
                seg[stop].second=m;
                ++ans;
            }else{
                // double temp=calc(inp[i],p[lower_bound(p+1,p+m+1,inp[i].d)-p]);
                if(calc(inp[i],p[lower_bound(p+1,p+m+1,inp[i].d)-p])-eps<=V||inp[i].d>p[m]) continue;
                seg[++stop].first=lower_bound(p+1,p+m+1,inp[i].d)-p;
                seg[stop].second=lower_bound(p+1,p+m+1,(V*V-inp[i].v0*inp[i].v0)/2.0/inp[i].a+inp[i].d)-p-1;
                ++ans;
            }
        }sort(seg+1,seg+stop+1);
        // dbg(stop);
        cout<<ans<<" ";
        ans=0;
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i=1,cur=1;i<=m;++i){
            while(i>=seg[cur].first&&cur<=stop){
                pq.push(seg[cur].second);
                cur++;
                if(cur>stop) break;
            }if((!pq.empty())&&pq.top()==i){
                ++ans;
                while(!pq.empty()) pq.pop();
            }
            // if(cur>m) break;
        }
        cout<<m-ans<<"\n";
    }
}