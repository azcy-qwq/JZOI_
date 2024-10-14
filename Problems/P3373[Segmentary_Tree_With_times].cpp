#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define int long long
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
        cout<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cout<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cout<<first<<" ";
        dbgo(rest...);
        cout<<"\n";
    }//made by _azcy
	template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    }
}using namespace azcy;
namespace IN {
    #define MAX_INPUT 100000003
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
        static std::streambuf * outbuf = cout.rdbuf();
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
        static std::streambuf * outbuf = cout.rdbuf();
        outbuf -> sputc(ch);
    }
    template < typename T > inline void put(const char ch, T x) {
        static std::streambuf * outbuf = cout.rdbuf();
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
const int N=4e5+10;
using namespace std;
#define ll int_fast64_t
ll tree[N],lazy[N],lazy2[N],a[N],pcc;
void build_tree(int id,int l,int r){
    lazy2[id]=1;
	if(l==r)
	{
        a[l]%=pcc;
		tree[id]=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build_tree(id<<1,l,mid);
	build_tree(id<<1|1,mid+1,r);
	tree[id]=(tree[id<<1]+tree[id<<1|1])%pcc; 
} 
inline void push_down(int id,int l,int r){
	if(lazy[id]||lazy2[id]!=1)
	{
		int mid=(l+r)>>1;
        tree[id<<1]  =(tree[id<<1]  *lazy2[id]+lazy[id]*(mid-l+1))%pcc;
		tree[id<<1|1]=(tree[id<<1|1]*lazy2[id]+lazy[id]*(r-mid)  )%pcc;
		lazy[id<<1]=lazy[id<<1]*lazy2[id]+lazy[id];
        lazy[id<<1]%=pcc;
		lazy[id<<1|1]=lazy[id<<1|1]*lazy2[id]+lazy[id];
        lazy[id<<1|1]%=pcc;
        lazy2[id<<1]*=lazy2[id];
        lazy2[id<<1|1]*=lazy2[id];
        lazy2[id<<1]%=pcc;       
        lazy2[id<<1|1]%=pcc;
		lazy[id]=0;
        lazy2[id]=1;
	}
}
inline void push_up(int id)
{
	tree[id]=tree[id<<1]+tree[id<<1|1];
    tree[id]%=pcc;
}
void update2(int id,int l,int r,int x,int y,int v){
    if(l>=x&&r<=y)
	{
        lazy2[id]*=v;
        lazy2[id]%=pcc;
		lazy[id]*=v;
        lazy[id]%=pcc;
		tree[id]*=v;
        tree[id]%=pcc;
		return;
	}
	push_down(id,l,r);
	int mid=(l+r)>>1;
	if(x<=mid) update2(id<<1,l,mid,x,y,v);
	if(y>mid) update2(id<<1|1,mid+1,r,x,y,v);
	push_up(id);
}
void update(int id,int l,int r,int x,int y,int v){
	if(l>=x&&r<=y)
	{
		lazy[id]+=v;
        lazy[id]%=pcc;
		tree[id]+=(v*((r-l+1)%pcc))%pcc;
        tree[id]%=pcc;
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
	if(x<=l&&r<=y)return tree[id]%pcc;
	push_down(id,l,r);
	int mid=(l+r)>>1;
	long long ans=0;
	if(x<=mid) ans=ans+find(id<<1,l,mid,x,y);
    ans%=pcc;
	if(y>mid) ans=ans+find(id<<1|1,mid+1,r,x,y);
	return ans%pcc; 
}
//fc "D:\cpp\Problems\P3373_2.out" "D:\cpp\Problems\P3373.out"
main()
{
    qfopen("P3373_2.in","P3373.out");
    // freopen("P3372_2.in","r",stdin);
    int n,m;
	ios::sync_with_stdio(0);
	cin.tie(0);
    redi(n,m,pcc);
    // pcc=INT_MAX;
	for(int i=1;i<=n;i++)
        redi(a[i]);
	build_tree(1,1,n);
	int op,A,b,c;
	for(int i=1;i<=m;i++)
	{
        redi(op,A,b);
        if(op==1){
            redi(c);
            c%=pcc;
            update2(1,1,n,A,b,c);
        }else if(op==2)
		{
            redi(c);
            c%=pcc;
			update(1,1,n,A,b,c);
		}
		else if(op==3)
		{
            put(find(1,1,n,A,b));
		}
	}
	return 0;
}
/*
5 5 38
1 5 4 2 3
2 1 4 1
3 1 5
1 1 5 2
3 1 5
3 1 4
*/