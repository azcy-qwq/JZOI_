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
const int N=3e5+10;
typedef long long ll;
typedef pair<int,ll> PII;
vector<PII> g[N];
int n,k; 
ll val,sum,cnt;
struct node
{
	int c; ll v;
    bool operator<(const node &x)const{
        return v<x.v||(v==x.v&&c<x.c);
    }
    node operator+(const node &x){
        node y;
        y.c=c+x.c,y.v=v+x.v;
        return y;
    }
}dp[N][3],tmp[3];
void dfs(int u,int fa)
{
	for(PII h:g[u])
	{
		int v=h.first; ll w=h.second;
		if(v==fa) continue; 
        dfs(v,u);
		dp[u][2]=max(dp[u][2]+dp[v][0],dp[u][1]+dp[v][1]+(node){1,w-val});
		dp[u][1]=max(dp[u][0]+dp[v][1]+(node){0,w},dp[u][1]+dp[v][0]);
		dp[u][0]=dp[u][0]+dp[v][0];
	}
	dp[u][0]=max(dp[u][0],max(dp[u][1]+(node){1,-val},dp[u][2]));
}
void check(ll x)
{
	val=x;
	for(int i=1;i<=n;++i)	
		dp[i][0]={0,0},dp[i][1]={0,0},dp[i][2]={1,-val};
	dfs(1,0);
	sum=dp[1][0].v,cnt=dp[1][0].c;
}
int main()
{
	auto_init();
	cin>>n>>k; k++;
	ll ans=0,l=0,r=0;
	for(int i=2;i<=n;++i)
	{
		int u,v,w; cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
		r+=(w>0?w:-w);
	}
	l=-r; 
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		check(mid);
		if(cnt>=k) l=mid+1,ans=mid;
		else r=mid-1;
	}
	check(ans);
	cout<<sum+ans*k<<'\n';
}