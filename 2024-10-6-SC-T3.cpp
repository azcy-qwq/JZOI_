#include <bits/stdc++.h>
using namespace std;
namespace IN
{
#define MAX_INPUT 25000003
#define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : *p1++)
    char buf[MAX_INPUT], *p1, *p2;
    template <typename T>
    inline bool redi(T &x)
    {
        static std::streambuf *inbuf = cin.rdbuf();
        x = 0;
        register int f = 0, flag = false;
        register char ch = getc();
        while (!std::isdigit(ch))
        {
            if (ch == '-')
                f = 1;
            ch = getc();
        }
        if (std::isdigit(ch))
            x = x * 10 + ch - '0', ch = getc(), flag = true;
        while (std::isdigit(ch))
        {
            x = x * 10 + ch - 48;
            ch = getc();
        }
        x = f ? -x : x;
        return flag;
    }
    template <typename T, typename... Args>
    inline bool redi(T &a, Args &...args)
    {
        return redi(a) && redi(args...);
    }
#undef getc
}
namespace OUT
{
    template <typename T>
    inline void put(T x)
    {
        static std::streambuf *outbuf = cerr.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0)
        {
            outbuf->sputc('-');
            x = -x;
        }
        if (!x)
        {
            outbuf->sputc('0');
            outbuf->sputc('\n');
            return;
        }
        while (x)
        {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top)
        {
            outbuf->sputc(stack[top]);
            --top;
        }
        outbuf->sputc('\n');
    }
    inline void putc(const char ch)
    {
        static std::streambuf *outbuf = cerr.rdbuf();
        outbuf->sputc(ch);
    }
    template <typename T>
    inline void put(const char ch, T x)
    {
        static std::streambuf *outbuf = cerr.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0)
        {
            outbuf->sputc('-');
            x = -x;
        }
        if (!x)
        {
            outbuf->sputc('0');
            outbuf->sputc(ch);
            return;
        }
        while (x)
        {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top)
        {
            outbuf->sputc(stack[top]);
            --top;
        }
        outbuf->sputc(ch);
    }
    template <typename T, typename... Args>
    inline void put(T a, Args... args)
    {
        put(a);
        put(args...);
    }
    template <typename T, typename... Args>
    inline void put(const char ch, T a, Args... args)
    {
        put(ch, a);
        put(ch, args...);
    }
}
using IN::redi;
using OUT::put;
using OUT::putc;
namespace azcy
{
    using namespace std;
    bool debug_switch = 1;
    void auto_init()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME, string OUTPUT_FILE_NAME)
    {
        freopen(INPUT_FILE_NAME.data(), "r", stdin);
        freopen(OUTPUT_FILE_NAME.data(), "w", stdout);
    }
    template <typename T>
    void dbgo(T x)
    {
        cerr << x << " ";
    }
    template <typename First, typename... Rest>
    void dbgo(First first, Rest... rest)
    {
        cerr << first << " ";
        dbgo(rest...);
    }
    template <typename First, typename... Rest>
    void dbg(First first, Rest... rest)
    {
        if (!debug_switch)
            return;
        cerr << first << " ";
        dbgo(rest...);
        cerr << "\n";
    } // made by _azcy
    template <typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cerr << x << "\n";
    }
}
using namespace azcy;
const int N = 2e6 + 10;
int n, m, a[N];
vector<int> nei[N];
int u, v, to[N], fr[N], qz[N], hz[N],dep[N];
bool flag_20 = 1;
bitset<N> vis;
void solve1()
{
    int starter=1, cur, top = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (nei[i].size() == 1)
        {
            starter = i;
            break;
        }
    }
    to[starter] = 1;
    vis[starter] = 1;
    fr[1] = starter;
    assert(nei[starter].size()==1);
    cur = nei[starter][0];
    while (nei[cur].size() == 2)
    {
        vis[cur] = 1;
        to[cur] = ++top;
        fr[top] = cur;
        for (auto u : nei[cur])
        {
            if (vis[u])
                continue;
            cur = u;
        }
    }
    fr[++top] = cur;
    to[cur] = top;

    qz[1] = a[fr[1]];
    for (int i = 2; i <= n; ++i)
    {
        qz[i] = min(qz[i - 1], a[fr[i]]);
    }
    hz[n + 1] = INT_MAX;
    for (int i = n; i >= 1; i--)
    {
        hz[i] = min(hz[i + 1], a[fr[i]]);
    }
    hz[n + 1] = 0;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v;
        u = to[u], v = to[v];
        if (u > v)
            swap(u, v);
        cout << qz[u - 1] + hz[v + 1] << "\n";
    }
}
int dp[N],fa[N];
int dfs(int id,int f){
	dp[id]=a[id];
    fa[id]=f;
    for(int u:nei[id]){
        if(u==f) continue;
        dp[id]=min(dp[id],dfs(u,id));
    }
    return dp[id];
}
void df5(int id,int dpth){
    dep[id]=dpth;
    for(int u:nei[id]){
        if(u==fa[id]) continue;
        df5(u,dpth+1);
    }
}
int dfs2(int id,int f){
    int temp=a[id];
    for(int t:nei[id]){
        if(t==f) continue;
        temp=min(temp,dfs2(t,id));
    }
    // dbg(id,temp,"_");
    return min(temp,a[id]);
}
int main()
{
    // freopen("valley.in","r",stdin);
    // freopen("valley.out","w",stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    cin >> n >> m;
    // dbg(n);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> u >> v;
        nei[u].push_back(v);
        nei[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i){
//        dbg(i,nei[i].size());
        if (nei[i].size() > 2)
        {
            flag_20 = 0;
            break;
        }
    }
//   dbg(flag_20);
//   return 0;
    // system("pause");
    if (flag_20)
    {
//    	cout<<"A";
        solve1();
/*
4 3
1 2 3 4
1 2
2 3
3 4
1 4
2 3
3 4
*/
    }else{
        dfs(1,1);
        df5(1,1);
        int ans;
        for(int i=1;i<=m;++i){
            vis.reset();
            ans=0;
            cin>>u>>v;
            if(dep[u]<dep[v]) swap(u,v);
            while(dep[u]>dep[v]){
//            	cout<<"a";
                vis[u]=1;
                for(int t:nei[u]){
                    if(vis[t]||t==fa[u]) continue;
                    ans+=dp[t];
                }
                u=fa[u];
            }
            while(u!=v){
                vis[u]=1;
                vis[v]=1;
                for(int t:nei[u]){
                    if(vis[t]||t==fa[u]) continue;
                    ans+=dp[t];
                }for(int t:nei[v]){
                    if(vis[t]||t==fa[v]) continue;
                    ans+=dp[t];
                }
                u=fa[u],v=fa[v];
            }
            for(int t:nei[u]){
                if(fa[u]==t) {
                   ans+=dfs2(t,u);
                   continue;
                }
                if(vis[t]) continue;
                ans+=dp[t];
            }
            cout<<ans<<"\n";
        }
    }
}