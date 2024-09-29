#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<bitset>
const int N=1e8+28;
using namespace std;
namespace IN {
    #define MAX_INPUT N<<1
    #define getc()(p1 == p2 && (p2 = (p1 = buf) + inbuf -> sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : * p1++)
    char buf[MAX_INPUT], * p1, * p2;
    template < typename T > inline bool redi(T & x) {
        static std::streambuf * inbuf = cin.rdbuf();
        x = 0;
//        register int f = 0, flag = false;
        register char ch = getc();
        while (!std::isdigit(ch)) {
//            if (ch == '-') f = 1;
            ch = getc();
        }
        if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc();
        while (std::isdigit(ch)) {
            x = x * 10 + ch - 48;
            ch = getc();
        }
//        x = f ? -x : x;
        return 1;
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
}
using IN::redi;
using OUT::put;
using OUT::putc;
int n,q,k,a[N/10],atop;
bitset<N> bs;
void init(){
	int temp=ceil(sqrt(n))+1;
	a[++atop]=2;
	for(int j=4;j<=n;j+=2){
			bs[j]=1;
	}
	for(int i=3;i<=n;i+=2){
		if(bs[i])continue;
		a[++atop]=i;
        if(i<=sqrt(n)+1)
		for(int j=i+i;j<=n;j+=i){
			bs[j]=1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	redi(n);
	redi(q);
	// ++q;
	init();
	while(q--){
		redi(k);
		put(a[k]);
	}
    put(atop);
    // put(a[atop-10]);
	return 0;
}
/*
100000000 5
1
2
3
4
5
*/