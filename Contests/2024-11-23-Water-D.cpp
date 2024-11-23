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
const int N=1e6+10;
struct Node{
	double tree;
	double lazy;
}sgt[N];
namespace sgtt
{
    #define lc(x) x<<1
    #define rc(x) x<<1|1
    void push_up(int id){
    	sgt[id].tree=minm(sgt[lc(id)].tree,sgt[rc(id)].tree);
    }
    void push_down(int id){
    	if(sgt[id].lazy!=0){
            sgt[lc(id)].tree+=sqrt(sgt[lc(id)].tree)*2*sgt[id].lazy+sgt[id].lazy*sgt[id].lazy;
            sgt[rc(id)].tree+=sqrt(sgt[rc(id)].tree)*2*sgt[id].lazy+sgt[id].lazy*sgt[id].lazy;
            sgt[lc(id)].lazy+=sgt[id].lazy;
            sgt[rc(id)].lazy+=sgt[id].lazy;
    		// sgt[lc(id)].tree2+=2*sgt[id].lazy*sgt[lc(id)].tree1
    		// 	+sgt[id].lazy*sgt[id].lazy*(x-x/2);
    		// sgt[lc(id)].tree1+=(x-x/2)*sgt[id].lazy;
    		// sgt[lc(id)].lazy+=sgt[id].lazy;
    
    		// sgt[rc(id)].tree2+=2*sgt[id].lazy*sgt[rc(id)].tree1
    		// 	+sgt[id].lazy*sgt[id].lazy*(x/2);
    		// sgt[rc(id)].tree1+=(x/2)*sgt[id].lazy;
    		// sgt[rc(id)].lazy+=sgt[id].lazy;
    		sgt[id].lazy=0;
    	}
    }

    double query(int id,int l,int r,int x,int y){
        if(l>=x&&r<=y)
            return sgt[id].tree;
        else{
            push_down(id);
            int mid=(l+r)>>1;
            double temp=LONG_LONG_MAX;
            if(mid>=x) temp=minm(temp,query(id<<1,l,mid,x,y));
            if(mid<y) temp=minm(temp,query(id<<1|1,mid+1,r,x,y));
            return temp;
        }
    }
    // double query1(int id,int l,int r,int x,int y){
    // 	if(l>=x&&r<=y)
    // 		return sgt[id].tree1;
    // 	else{
    // 		push_down(id,r-l+1);
    // 		int mid=(l+r)>>1;
    // 		double temp=0;
    // 		if(mid>=x) temp+=query1(id<<1,l,mid,x,y);
    // 		if(mid<y) temp+=query1(id<<1|1,mid+1,r,x,y);
    // 		return temp;
    // 	} 
    // }
    // double query2(int id,int l,int r,int x,int y){
    // 	if(l>=x&&r<=y)
    // 		return sgt[id].tree2;
    // 	else{
    // 		push_down(id,r-l+1);
    // 		int mid=(l+r)>>1;
    // 		double temp=0;
    // 		if(mid>=x) temp+=query2(id<<1,l,mid,x,y);
    // 		if(mid<y) temp+=query2(id<<1|1,mid+1,r,x,y);
    // 		return temp;
    // 	}
    // }
    void update(int id,int l,int r,int x,int y,double v){
    	if(l>=x&&r<=y)
    		sgt[id].lazy+=v,sgt[id].tree+=2*v*sqrt(sgt[id].tree)+v*v;
    	else{
    		push_down(id);
    		int mid=(l+r)>>1;
    		if(mid>=x)
    			update(id<<1,l,mid,x,y,v);
    		if(mid<y)
    			update(id<<1|1,mid+1,r,x,y,v);
    		push_up(id);
    	}
    }void update2(int id,int l,int r,int x,int y,int v){
        if(l>=x&&r<=y)
            sgt[id].tree=v*v;
        else{
            push_down(id);
    		int mid=(l+r)>>1;
    		if(mid>=x)
    			update(id<<1,l,mid,x,y,v);
    		if(mid<y)
    			update(id<<1|1,mid+1,r,x,y,v);
    		push_up(id);
        }
    }
} // namespace sgtt
using namespace sgtt;
int n,prv[N],a[N],dp[N],been[N],minn;
map<int,int> mp;
int main(){
//ios::sync_with_stdio(0);
    cin>>n;
    if(n>=2000){
        for(int i=1;i<=n;++i){
        cin>>a[i];
        // if(mp[a[i]]==0) mp[a[i]]=-1;
        prv[i]=mp[a[i]];
        mp[a[i]]=i;
        }
        // dp[1]=1;
        // been[0]=1;
        for(int i=1;i<=n;++i){
            for(int j=maxm(prv[i]+1,j-10);j<=i;++j)
                been[j]+=1;
            minn=INT_MAX;
            for(int j=maxm(prv[i]+1,j-10);j<=i;++j)
                minn=minm(minn,been[j]*been[j]+dp[j]);
            dp[i+1]=minn;

        }cout<<dp[n+1];
        return 0;
    }
    for(int i=1;i<=n;++i){
        cin>>a[i];
        // if(mp[a[i]]==0) mp[a[i]]=-1;
        prv[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    // dp[1]=1;
    // been[0]=1;
    for(int i=1;i<=n;++i){
        for(int j=prv[i]+1;j<=i;++j)
            been[j]+=1;
        minn=INT_MAX;
        for(int j=1;j<=i;++j)
            minn=minm(minn,been[j]*been[j]+dp[j]);
        dp[i+1]=minn;
        
    }cout<<dp[n+1];
}