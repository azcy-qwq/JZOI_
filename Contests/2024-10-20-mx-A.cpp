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
const int N=8e5+10;
#define i128 long long
i128 tree[N],lazy[N],a[N];
void build_tree(int id,int l,int r){
	if(l==r)
	{
		tree[id]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build_tree(id<<1,l,mid);
	build_tree(id<<1|1,mid+1,r);
	tree[id]=tree[id<<1]+tree[id<<1|1]; 
} 
inline void push_down(int id,int l,int r){
	if(lazy[id])
	{
		int mid=(l+r)>>1;
		lazy[id<<1]+=lazy[id];
		lazy[id<<1|1]+=lazy[id];
		tree[id<<1]+=lazy[id]*(mid-l+1);
		tree[id<<1|1]+=lazy[id]*(r-mid);
		lazy[id]=0;
	}
}
inline void push_up(int id)
{
	tree[id]=tree[id<<1]+tree[id<<1|1];
}
void update(int id,int l,int r,int x,int y,i128 v){
	if(l>=x&&r<=y)
	{
		lazy[id]+=v;
		tree[id]+=v*(r-l+1);
		return;
	}
	push_down(id,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) update(id<<1,l,mid,x,y,v);
	if(y>mid) update(id<<1|1,mid+1,r,x,y,v);
	push_up(id);
}
i128 find(int id,int l,int r,int x,int y)
{
	if(x<=l&&r<=y) return tree[id];
	push_down(id,l,r);
	int mid=(l+r)>>1;
	i128 ans=0;
	if(x<=mid) ans=ans+find(id<<1,l,mid,x,y);
	if(y>mid) ans=ans+find(id<<1|1,mid+1,r,x,y);
	return ans; 
}
int n,q,l,r;
i128 d,w,qzh[N],rnd,sum,xs;
inline i128 calc(int x){
    if(x<=0) return 0;
    // if(x<l) return qzh[x]*xs;
    // if(x>r) return xs*(qzh[x]+(r-l+1)*d); 
    // return xs*(qzh[x]+(x-l+1)*d);
    return find(1,1,n,1,x)*xs;
}
constexpr long double LG2=0.69314718055994530942869047418498;
i128 bs(int id,int l,int r,i128 v){
    if(l==r) return l;
    push_down(id,l,r);
    i128 mid=(l+r)>>1;
    if(tree[id<<1]*xs>=v) return bs(id<<1,l,mid,v);
    else return bs(id<<1|1,mid+1,r,v-tree[id<<1]*xs);
}
int main(){
//   	qfopen("wxyt4.in","wxyt4.out");
//    cerr<<fixed<<setprecision(32)<<LG2;
	// freopen("wxyt3.in","r",stdin);
	// freopen("wxyt3.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    redi(n,q,w);
    for(int i=1;i<=n;++i){
        redi(a[i]);
    }
    sum=0;
    for(int i=1;i<=n;++i)
        qzh[i]=qzh[i-1]+a[i],sum+=a[i];
    build_tree(1,1,n);
    for(int i=1;i<=q;++i){
        redi(l,r,d);
        update(1,1,n,l,r,d);//Modify the data according to the statement.
        sum=find(1,1,n,1,n);
        rnd=floor(log((long double)w/(long double)sum+1)/LG2);
        //dbg((long double)w/(long double)sum,log((long double)w/(long double)sum+1)/log(2),__lg((int)((long double)w/(long double)sum+1.0)));
        int L=0,R=n,mid;
        xs=(((i128)1)<<rnd);
        i128 temp,last=w-(xs-1)*sum,ans=INT_MAX;
        // while(R>=L){
        //     mid=L+((R-L)>>1);
        //     temp=calc(mid);
        //     if(temp>last) R=mid-1,ans=mid;
        //     else if(temp<last) L=mid+1,ans=mid+1;
        //     else{
        //         ans=mid;
        //         break;
        //     }
        // }
        // if(calc(ans-1)>=last) ans--;
//        put(ans+rnd*n-1);
        if(last==0)cout<<rnd*n-1<<"\n";
        else cout<<(long long)(bs(1,1,n,last)+rnd*n-1)<<'\n';
//		cout<<ans%2<<"\n";
        sum-=(r-l+1)*d;
        // update(1,1,n,l,r,-1*d);//Unmodifization
    }
}