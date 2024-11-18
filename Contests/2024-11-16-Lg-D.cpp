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
int T,T2,p[N],n;
bitset<N> ansv,color;
int tim=0;
// bool ansv[N],color[N];
void dfs(int cz){
    // if(clock()-tim>990/T2){
    //     // tim=clock();
    //     return ;
    // }
    if(cz==(n-1)/2){
        for(int i=1;i<=n;++i)
            if(color[i]==0){
                ansv[p[i]]=1;
                break;
            }     
        return ;
    }
    for(int i=2;i<=n-1;++i){
        // dbg(i,color[i]);
        if(color[i]) 
            continue;
        int lb=-1,rb=-1;
        for(int j=i-1;j>=1;--j){
            // dbg(j,color[j]);
            if(!color[j]){
                lb=j;break;
            }
        }for(int j=i+1;j<=n;++j){
            if(!color[j]){
                rb=j;break;
            }
        }if(lb==-1||rb==-1) continue;
        color[i]=color[rb]=1;
        int temp=p[lb];
        p[lb]=maxm(p[i],p[lb],p[rb]);
        dfs(cz+1);
        p[lb]=minm(p[i],temp,p[rb]);
        dfs(cz+1);
        p[lb]=temp;
        color[i]=color[rb]=0;
    }
}
int main(){
//ios::sync_with_stdio(0);
    auto_init();
    cin>>T;
    T2=T;
    while(T--){
        bool flag=1;
        // tim=clock();
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>p[i];
            if(p[i]!=i) flag=0;
        }
        if(flag){
            for(int i=1;i<n;i+=2){
                cout<<"10";
            }
            cout<<"1\n";
            continue;
        }
        ansv.reset();
        color.reset();
        // memset(ansv,0,sizeof(ansv));
        // memset(color,0,sizeof(color));
        dfs(0);
        for(int i=1;i<=n;++i){
            cout<<ansv[i];
        }cout<<"\n";
    }
}
/*
1
5
1 2 3 4 5
*/