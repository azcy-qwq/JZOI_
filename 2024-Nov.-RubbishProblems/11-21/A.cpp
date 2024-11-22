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
    template<typename T>
    inline T maxm(T a,T b){
        return (a>b)?a:b;
    }template<typename T1,typename T2>
    inline T1 maxm(T1 a,T2 b){
        return (a>b)?(a):(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First maxm(First first,Rest... rest){
        return maxm(first,maxm(rest...));
    }
    template<typename T>
    inline T minm(T a,T b){
        return (a<b)?a:b;
    }template<typename T1,typename T2>
    inline T1 minm(T1 a,T2 b){
        return (a<b)?a:(a=b,a);
    }
    template<typename First,typename... Rest>
    inline First minm(First first,Rest... rest){
        return minm(first,minm(rest...));
    }
}using namespace azcy;
const int N=1e4+10;
const int PCC=1e6+7;
bool m1;
typedef long long ll;
template<const int PCC>
class ModInt{
    public:
        long long data;
        ModInt(){data=0;}
        ModInt(const ModInt& x){data=x.data%PCC;}
        template<typename T> ModInt(T x) {data=(x%PCC+PCC)%PCC;}
        ModInt operator+(const ModInt& x){ModInt y;y.data=(x.data+this->data)%PCC;return y;}
        ModInt operator-(const ModInt& x){ModInt y;y.data=((this->data-x.data)%PCC+PCC)%PCC;return y;}
        ModInt operator*(const ModInt& x){ModInt y;y.data=((this->data*x.data)%PCC+PCC)%PCC;return y;}
        template<typename T> ModInt operator+(const T& x){ModInt y;y.data=(this->data+(x%PCC))%PCC;return y;}
                     ModInt operator+(const long long& x){ModInt y;y.data=(this->data+(x%PCC))%PCC;return y;}
        template<typename T> ModInt operator*(const T& x){ModInt y;y.data=(this->data*(x%PCC))%PCC;return y;}
                          void operator=(const ModInt& x){data=x.data;}
        template<typename T>   void operator=(const T& x){data=(x%PCC+PCC)%PCC;}
        template<typename T> ModInt operator/(const T& x){ModInt y=x;y.data/=x;return y;}
        friend ostream &operator<<(ostream &output,const ModInt &D ){ 
            output<<D.data%PCC;
            return output;            
        }friend istream &operator>>(istream &input,ModInt &x){
            input>>x.data;
            x.data%=PCC;
            return input;
        }template<typename T>
        void operator+=(const T& x)     {*this=*this+x;}template<typename T>
        void operator*=(const T& x)     {*this=*this*x;}template<typename T>
        void operator-=(const T& x)     {*this=*this-x;}
        bool operator< (const ModInt &x){return data<x.data;}template<typename T>
        bool operator< (const T &x)     {return data<x;}
        bool operator> (const ModInt &x){return data>x.data;}template<typename T>
        bool operator> (const T &x)     {return data>x;}
        bool operator==(const ModInt &x){return data==x.data;}template<typename T>
        bool operator==(const T &x)     {return data==x;}
        bool operator<=(const ModInt &x){return data<=x.data;}template<typename T>
        bool operator<=(const T &x)     {return data<=x;}
        bool operator>=(const ModInt &x){return data>=x.data;}template<typename T>
        bool operator>=(const T &x)     {return data>=x;}
        bool operator!=(const ModInt &x){return data!=x.data;}template<typename T>
        bool operator!=(const T &x)     {return data!=x;}
        void operator++(){++data;data%=PCC;}
        void operator--(){--data;data=(data+PCC)%PCC;}
        template<typename T> friend bool operator<(T x,ModInt y)  {return x<y.data; }
        template<typename T> friend bool operator>(T x,ModInt y)  {return x>y.data; }
        template<typename T> friend bool operator==(T x,ModInt y) {return x==y.data;}
        template<typename T> friend bool operator<=(T x,ModInt y) {return x<=y.data;}
        template<typename T> friend bool operator>=(T x,ModInt y) {return x>=y.data;}
};
ll n,q[N];
ModInt<(int)1e6+7> mx[N],dp[N],ans;
bool m2;
int main(){
ios::sync_with_stdio(0);
    // qfopen("maou3.in","maou.out");
    // cerr<<(double)(&m2-&m1)/1024/1024<<'\n';
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>q[i];
        mx[i]=maxm(mx[i-1],q[i]),dp[i]=1;
    }for(int i=n;i>=1;--i){
        for(int j=1;j<=minm(mx[i-1]+1,q[i]-1).data;++j)
            ans+=dp[maxm(mx[i-1]+1,j+1).data];
        for(int j=1;j<=i;++j)
            dp[j]=dp[j]*(j-1)+dp[j+1];
    }ans+=1;
    cout<<ans;
}//5 1 1 2 2 1