#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define int int_fast32_t
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
ll tree[N],lazy[N],a[N];
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
void update(int id,int l,int r,int x,int y,int v){
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
long long find(int id,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return tree[id];
	push_down(id,l,r);
	int mid=(l+r)>>1;
	long long ans=0;
	if(x<=mid) ans=ans+find(id<<1,l,mid,x,y);
	if(y>mid) ans=ans+find(id<<1|1,mid+1,r,x,y);
	return ans; 
}
main()
{
	int n,m;
	ios::sync_with_stdio(0);
	cin.tie(0);
    redi(n,m);
	for(int i=1;i<=n;i++)
        redi(a[i]);
	build_tree(1,1,n);
	int op,a,b,c;
	for(int i=1;i<=m;i++)
	{
        redi(op,a,b);
		if(op==1)
		{
            redi(c);
			update(1,1,n,a,b,c);
		}
		else
		{
            put(find(1,1,n,a,b));
		}
	}
	return 0;
}