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
const int N=1e6+10;
#define ll long long
pair<ll,ll> stone[N];
pair<int,int> consq[N];
ll n,m,s,decr[N],qzh[N],cnt[N];
ll calc(ll x){
    qzh[0]=cnt[0]=0;
    for(int i=1;i<=n;++i){
        qzh[i]=qzh[i-1]+(stone[i].first>=x)*stone[i].second;
        cnt[i]=cnt[i-1]+(stone[i].first>=x);
    }
    ll ans=0;
    for(int i=1;i<=m;++i){
        ans+=(cnt[consq[i].second]-cnt[consq[i].first-1])*(qzh[consq[i].second]-qzh[consq[i].first-1]);
    }
    return ans;
}
typedef pair<int,int> pii;
pair<pii,pii> piiii;
int main(){
//ios::sync_with_stdio(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;++i){
        cin>>stone[i].first>>stone[i].second;
        decr[i]=stone[i].first;
    }sort(decr+1,decr+n+1);
    decr[n+1]=INT_MAX;
    for(int i=1;i<=m;++i){
        cin>>consq[i].first>>consq[i].second;
    }int l=0,r=n+1,ans,mid;
    ll temp,res;
    while(r>=l){
        mid=(l+r)>>1;
        temp=decr[mid];
        res=calc(temp);
        if(res>s) l=mid+1,ans=mid;
        else if(res<s) r=mid-1,ans=mid;
        else {
            cout<<"0";
            return 0;
        }
    }
    // for(int i=0;i<=n+1;++i)
    //     cout<<i<<" "<<decr[i]<<" "<<calc(decr[i])<<" "<<calc(decr[i])-s<<"\n";
    // cout<<"\n";
    // dbg(calc()-s);
    res=min(min(abs(calc(decr[ans-1])-s),abs(calc(decr[ans])-s))
        ,abs(calc(decr[ans+1])-s));
    cout<<res;
}
/*
5 2 15
1 1
2 2
3 3
4 4
5 5

1 5
2 4
*/