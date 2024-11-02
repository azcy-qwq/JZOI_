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
#define int long long
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
Sparce_Table_Max<int> dat;
int n,m,year[N],sum[N],top,l,r,ll,rr,temp;
map<int,int> to;
signed main(){
    // freopen("P2471_1.in","r",stdin);
    // freopen("awa.out","w",stdout);
ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>year[i]>>sum[i];
        dat.insert(sum[i]);
        to[year[i]]=i;
    }
    cin>>m;
    dat.build();
    for(int i=1;i<=m;++i){
        cin>>l>>r;
        // if(to[r]==0){
        //     cout<<"maybe\n";
        //     continue;
        // } 
        bool b1=(to[l]!=0),b2=(to[r]!=0);
        ll=lower_bound(year+1,year+n+1,l+1)-year;
        rr=lower_bound(year+1,year+n+1,r)-1-year;
        if(rr<ll) temp=0;
        else temp=dat.query(ll,rr);
        if((to[r]!=0&&temp>=sum[to[r]])||(to[l]!=0&&temp>=sum[to[l]])||
           (to[l]!=0&&to[r]!=0&&(sum[to[l]]<=sum[to[r]]))){
            cout<<"false\n";
        }else if((rr-ll+2!=r-l)||(to[r]==0)||(to[l]==0)){
            cout<<"maybe\n";
        }else{
            cout<<"true\n";
        }
    }
}