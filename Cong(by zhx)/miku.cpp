#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3,"Ofast","inline")
namespace IN {
    #define MAX_INPUT 25000003
    #define getc()(p1 == p2 && (p2 = (p1 = buf) + inbuf -> sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : * p1++)
    char buf[MAX_INPUT], * p1, * p2;
    template < typename T > inline bool redi(T & x) {
        static std::streambuf * inbuf = cin.rdbuf();
        x = 0;
        int f = 0, flag = false;
        char ch = getc();
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
const int N=3e3+10;
int n,m;
int w[N][N],a[N],b[N],prvans,anss;
struct data{
    int v[N],p[N];
}cur,prv,ansp;
mt19937 rnd(time(0)+rand());
double urp(){
    return (double)rnd()/2/INT_MAX;
}double rp(){
    return ((double)rnd()-INT_MAX)/INT_MAX;
}
double t;
void display(){
//    for(int i=1;i<=n;++i)
//        cerr<<ansp.p[i]<<"\n";
    cerr<<"\n"<<(double)clock()/CLOCKS_PER_SEC<<"\n";
    cerr<<"Ans:"<<anss<<"\nTemperature:"<<t<<"\nCurrent Answer: "<<prvans<<"\n";
}
void output(){
    for(int i=1;i<=50;++i) cout<<"_";
    cout<<"\n";
    for(int i=1;i<=n;++i)
        cout<<ansp.p[i]<<"\n";
//    cout<<"Ans:"<<anss<<"\nTemperature:"<<t<<"\n"<<prvans<<"\n";
}
int calc(){
    int temp=0;
    for(int i=1;i<=n;++i){
        temp+=w[i][cur.p[i]];
    }
    return temp;
}
double limit__=0.01;
int main(){
    srand(time(0));
    freopen("drawer4.in","r",stdin);
    freopen("drawer4.out","w",stdout);
    // ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
        cin>>b[i];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>w[i][j];
    long long tim=clock(),tim2=clock();
    t=0.99;
    // b[0]=INT_MAX;
    while(clock()/CLOCKS_PER_SEC<6000){
        for(int i=1;i<=n;++i){
            int pian_yi=rnd()%m,k;
            bool flag=false;
            for(int j=0;j<=m;++j){
                k=j+pian_yi;
                k%=(m);
                ++k;
                if(urp()<=t){
                    if(b[k]-cur.v[k]>=a[i]){
                        cur.v[k]+=a[i];
                        cur.v[cur.p[i]]-=a[i];
                        cur.p[i]=k;
                        flag=true;
                        break;
                    }
                }
            }if(flag==0){
                if(urp()<=t){
                    cur.v[0]+=a[i];
                    cur.v[cur.p[i]]-=a[i];
                    cur.p[i]=0;
                }
            }
        }
        int temp=calc();
        if(exp((prvans-temp)/t)<urp()){
            prv=cur;
            prvans=temp;
        }else cur=prv;
        if(t>limit__)
            t*=0.9999;
        // if(t<=1e-8){
            
            if(clock()-tim>CLOCKS_PER_SEC*1){
                display(),tim=clock();
                if(prvans>anss)
                    ansp=prv,anss=prvans,output();
            }
            if(clock()-tim2>CLOCKS_PER_SEC*40){
                tim2=clock(),output();
            }
            // t=0.99,prvans=0;
        // }
    }
    output();
}
/*
大葱是我国自古以来的美食，像我国传统美食北京烤鸭，用鸭子点缀出大葱的香味，令人赞不绝口。民间也流传着有「每天一棵葱，不当单身狗」的说法。
然而，大葱要发挥出独属于自己的神力，也是有条件的。
自然小葱同学希望获得尽量多的神力，但是抽屉有着容积的限制，大葱也有着自己的体积。
一个抽屉里面装着的大葱的体积之和不能超过这个抽屉的容积，一棵大葱不能拆分放到两个抽屉中。
小葱同学现在想知道，在这样的条件下，这些大葱最多会产生多少的神力？
第一行两个整数 N,M代表大葱的个数和抽屉的个数。
接下来一行N个整数，代表每棵大葱的体积。
接下来一行M个整数，代表每个抽屉的容积。
接下来N行每行 M个整数，第i行第 j个数代表第i棵大葱放到第j个抽屉中会产生的神力。
*/