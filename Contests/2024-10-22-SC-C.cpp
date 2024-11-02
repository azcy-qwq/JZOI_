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
const int N=4e6+10;
#define int long long
struct seg{
    int l,r;
    bool operator<(const seg x)const{
        return r-l>x.r-x.l;
    }
    int d(){
        return r-l+1;
    }
}a[N];
#define ll long long
ll tree[N],lazy[N];
inline void push_down(int id,int l,int r){
	if(lazy[id])
	{
		int mid=(l+r)>>1;
		lazy[id<<1]+=lazy[id];
		lazy[id<<1|1]+=lazy[id];
		tree[id<<1]+=lazy[id];
		tree[id<<1|1]+=lazy[id];
		lazy[id]=0;
	}
}
inline void push_up(int id)
{
	tree[id]=max(tree[id<<1],tree[id<<1|1]);
}
void update(int id,int l,int r,int x,int y,int v){
	if(l>=x&&r<=y)
	{
		lazy[id]+=v;
		tree[id]+=v;
		return;
	}
	push_down(id,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) update(id<<1,l,mid,x,y,v);
	if(y>mid) update(id<<1|1,mid+1,r,x,y,v);
	push_up(id);
}
long long find(int id,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return tree[id];
	push_down(id,l,r);
	int mid=(l+r)>>1;
	long long ans=INT_MIN;
	if(x<=mid) ans=max(ans,find(id<<1,l,mid,x,y));
	if(y>mid) ans=max(ans,find(id<<1|1,mid+1,r,x,y));
	return ans; 
}
int n,m,ans,dt[N],dtop;
unordered_map<int,int> to;
signed main(){
    freopen("P1712_10.in","r",stdin);
ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i].l>>a[i].r;
        dt[++dtop]=a[i].l;
        dt[++dtop]=a[i].r;
    }
    sort(dt+1,dt+dtop+1);
    dtop=unique(dt+1,dt+dtop+1)-dt+1;
    for(int i=1;i<=dtop;++i){
        if(to[dt[i]]) break;
        to[dt[i]]=i;
    }
    sort(a+1,a+n+1);
    ans=LONG_LONG_MAX;
    // dbg(n);
    for(int i=1,j=0;i<=n;++i){
        // int x;
        while(find(1,1,dtop,1,dtop)<m){
            ++j;
            if(j>n) break;
            update(1,1,dtop,to[a[j].l],to[a[j].r],1);
        }if(j>n) break;
        ans=min(ans,a[i].d()-a[j].d());
        update(1,1,dtop,to[a[i].l],to[a[i].r],-1);
    }
    if(ans==LONG_LONG_MAX) cout<<"-1";
    else cout<<ans;
}