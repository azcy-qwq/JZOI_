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
const int inf=LONG_LONG_MIN+1145;
class sgt_AS{
    public:
        long long a[N<<2];
    private:
        long long lazy[N<<2],tree[N<<2],lazy2[N<<2];
        int l[N<<2],r[N<<2];
        void build_tree(int id,int x,int y){
            lazy2[id]=inf;
            l[id]=x;
            r[id]=y;
            if(x==y){
                tree[id]=a[x];
                return;
            }
            int mid=(x+y)>>1;
            build_tree(id<<1,x,mid);
            build_tree(id<<1|1,mid+1,y);
            tree[id]=max(tree[id<<1],tree[id<<1|1]);
        }
        void push_down2(int id){
            if(lazy2[id]!=inf){
                // int mid=(r[id]+l[id])>>1;
                lazy[id<<1]=0;
                lazy2[id<<1]=lazy2[id];
                tree[id<<1]=lazy2[id];
                lazy [id<<1|1]=0;
                lazy2[id<<1|1]=lazy2[id];
                tree [id<<1|1]=lazy2[id];
                lazy2[id]=inf;
            }
        }
        void push_down(int id){
            push_down2(id);
            if(lazy[id]){
                // int mid=(r[id]+l[id])>>1;
                lazy[id<<1]+=lazy[id];
                tree[id<<1]+=lazy[id];
                lazy[id<<1|1]+=lazy[id];
                tree[id<<1|1]+=lazy[id];
                lazy[id]=0;
            }
        }void push_up(int id){
            tree[id]=max(tree[id<<1],tree[id<<1|1]);
        }void update(int id,int x,int y,long long v){
            if(l[id]>=x&&r[id]<=y){
                push_down2(id);
                tree[id]+=v;
                lazy[id]+=v;
                return ;
            }push_down(id);
            int mid=(l[id]+r[id])>>1;
            if(x<=mid) update(id<<1,x,y,v);
            if(y>mid) update(id<<1|1,x,y,v);
            push_up(id);
        }void update2(int id,int x,int y,long long v){
            if(l[id]>=x&&r[id]<=y){
                tree[id]=v;
                lazy2[id]=v;
                lazy[id]=0;
                return ;
            }push_down(id);
            int mid=(l[id]+r[id])>>1;
            if(x<=mid) update2(id<<1,x,y,v);
            if(y>mid) update2(id<<1|1,x,y,v);
            push_up(id);
        }
        
        long long query(int id,int x,int y){
            if(x<=l[id]&&y>=r[id]) return tree[id];
            push_down(id);
            long long ans=LONG_LONG_MIN;
            int mid=(l[id]+r[id])>>1;
            if(x<=mid) ans=max(ans,query(id<<1,x,y));
            if(y>mid) ans=max(ans,query(id<<1|1,x,y));
            return ans;
        }
    public:
        void BuildTree(int len){
            build_tree(1,1,len);
        }void Update(int L,int R,long long v){
            update(1,L,R,v);
        }long long Query(int L,int R){
            return query(1,L,R);
        }void Update2(int L,int R,long long v){
            update2(1,L,R,v);
        }
}miku;
pair<int,int> pii;
int n,m,q,op,x,y,xa,ya,temp1,temp2;
int main(){
//ios::sync_with_stdio(0);
    cin>>n>>m>>q;
    while(q--){
        cin>>op>>x>>y;
        if(op==1){
            
        }else{
            cin>>xa>>ya;
        }
    }
}