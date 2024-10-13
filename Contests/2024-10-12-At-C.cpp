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
int n;
char a[N][N],g[N][N];
void display(){
    cout<<"\n";
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
}
void solve(int x){
    char y;
	if(x%4==1){
		for(int i=x+1;i<n-x+1;i++){
			y=a[x][i];
			a[x][i]=a[n-i+1][x];
			a[n-i+1][x]=a[n-x+1][n-i+1];
			a[n-x+1][n-i+1]=a[i][n-x+1];
			a[i][n-x+1]=y;
		}
		y=a[x][x];
		a[x][x]=a[n-x+1][x];
		a[n-x+1][x]=a[n-x+1][n-x+1];
		a[n-x+1][n-x+1]=a[x][n-x+1];
		a[x][n-x+1]=y;
	}
	if(x%4==2){
		for(int i=x;i<=n-x+1;i++){
			swap(a[x][i],a[n-x+1][n-i+1]);
			swap(a[i][x],a[n-i+1][n-x+1]);
		}
		swap(a[x][x],a[n-x+1][n-x+1]);
		swap(a[n-x+1][x],a[x][n-x+1]);
	}
	if(x%4==3){
		for(int i=x+1;i<n-x+1;i++){
			y=a[x][i];
			a[x][i]=a[i][n-x+1];
			a[i][n-x+1]=a[n-x+1][n-i+1];
			a[n-x+1][n-i+1]=a[n-i+1][x];
			a[n-i+1][x]=y;
		}
		y=a[x][x];
		a[x][x]=a[x][n-x+1];
		a[x][n-x+1]=a[n-x+1][n-x+1];
		a[n-x+1][n-x+1]=a[n-x+1][x];
		a[n-x+1][x]=y;
	}
}
int main(){
ios::sync_with_stdio(0);
    cin>>n;
    // for(int i=1;i<=n;++i)
    //     for(int j=1;j<=n;++j){
    //         cin>>a[i][j];
    //         g[i][j]=a[i][j];
    //     }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j){
    //         int temp=min(min(i,j),min(n-i+1,n-j+1)),x,y,x1=i,y1=j;
    //         dbg(i,j,temp%4);
    //         for(int i=1;i<=temp%4;++i){
    //             x=y1;
    //             y=n-x1+1;
    //             y1=y;
    //             x1=x;
    //         }
    //         g[i][j]=a[x1][y1];
    //     }
    // }
    for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n/2;i++)
		solve(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<a[i][j];
		cout<<"\n";
	}
		
}
/*
4
####
#...
#...
....
*/