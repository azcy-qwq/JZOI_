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
int t,k,r;
typedef unsigned int ui;
unsigned int kth[N],h1,kk[N],hh;
string s;
vector<char> v;
inline ui calc(char a,int b,int c){
    return (ui)a*(kth[c-b-1]);
}
inline ui calc2(char a,int b,int c){
    return (ui)a*(kk[c-b-1]);
}
bool dfs(int cur,ui h,int l,ui h2){
    if(cur==l){
        if(h==h1&&hh!=h2){
            // dbg(hh,h2);
            return true;
        }
            
        else
            return false; 
    }
        
    if(kth[l-cur-1]==0){
        if(dfs(cur+1,h,l,h2+calc2('A',cur,l))){
            v.push_back('A');
            return 1;
        }
        if(dfs(cur+1,h,l,h2+calc2('B',cur,l))){
            v.push_back('B');
            return 1;
        }
    }else
        for(char ch='A';ch<='Z';++ch)
            if(dfs(cur+1,h+calc(ch,cur,l),l,h2+calc2(ch,cur,l))){
                v.push_back(ch);
                return true;
            }
        
        
    return false;
}
void solve(){
    string s2;
    v.clear();
    h1=0,hh=0;
    cin>>s;
    for(int i=0;i<s.length();++i){
        h1+=(ui)s[i]*kth[s.length()-i-1];
        hh+=calc2(s[i],i,s.length());
    }
    for(int i=r;i>=1;--i){
        if(dfs(0,0,i,0)){
            for(int i=v.size()-1;i>=0;--i)
                cout<<v[i];
            cout<<"\n";
            return;
        }
            
    }
    cout<<"-1\n";
}
mt19937 rnd(time(0));
void init(){
    kth[0]=1;
    kth[1]=k;
    for(int i=2;i<=10;++i)
        kth[i]=kth[i-1]*k,kk[i]=rnd();
}
int main(){
    freopen("hash.in","r",stdin);
    freopen("hash.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t>>k>>r;
    init();
    while(t--){
        solve();
    }
}