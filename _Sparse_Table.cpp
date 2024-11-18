#include<bits/stdc++.h>
using namespace std;
const int N=1.2e5+38;
namespace IN {
    // #define MAX_INPUT 25000003
    const int MAXINPUT = 2.5e6+10;
    #define getc()(p1 == p2 && (p2 = (p1 = buf) + inbuf -> sgetn(buf, MAXINPUT), p1 == p2) ? EOF : * p1++)
    char buf[MAXINPUT], * p1, * p2;
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
template<typename T>
class Sparce_Table_Max{
	private:
		T data_[N][__lg(N)+2];
		int maxn=0,Log_n;
	public:
		void insert(int x){
			data_[++maxn][0]=x;
		}
		void build(){
			Log_n=__lg(maxn);
			for(int j=1;j<=Log_n;++j){
				for(int i=1;i+(1<<j)-1<=maxn;++i){
					data_[i][j]=max(data_[i][j-1],data_[i+(1<<(j-1))][j-1]);
				}
			}
		}
		inline T query(int l,int r){
			//if(l>r) swap(l,r);
			int s=__lg(r-l+1);
			return max(data_[l][s],data_[r-(1<<s)+1][s]);
		}
};
template<typename T>
class Sparce_Table_Min{
	private:
		T data_[N][__lg(N)+2];
		int maxn=0,Log_n;
	public:
		void insert(int x){
			data_[++maxn][0]=x;
		}
		void build(){
			Log_n=__lg(maxn);
			for(int j=1;j<=Log_n;++j){
				for(int i=1;i+(1<<j)-1<=maxn;++i){
					data_[i][j]=min(data_[i][j-1],data_[i+(1<<(j-1))][j-1]);
				}
			}
		}
		T query(int l,int r){
			//if(l>r) swap(l,r);
			int s=__lg(r-l+1);
			return min(data_[l][s],data_[r-(1<<s)+1][s]);
		}
};
int n,m,x,x2;
Sparce_Table_Max<int> st;
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	// cin>>n>>m;
    redi(n,m);
	for(int i=1;i<=n;++i){
		// cin>>x;
        redi(x);
		st.insert(x);
	}
	st.build();
	for(int i=1;i<=m;++i){
		// cin>>x>>x2;
        redi(x,x2);
		cout<<st.query(x,x2)<<"\n";
	}
}
