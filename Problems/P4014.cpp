#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        cout << x << " ";
    }
    template <typename First, typename... Rest>
    void dbgo(First first, Rest... rest)
    {
        cout << first << " ";
        dbgo(rest...);
    }
    template <typename First, typename... Rest>
    void dbg(First first, Rest... rest)
    {
        if (!debug_switch)
            return;
        cout << first << " ";
        dbgo(rest...);
        cout << "\n";
    }
    template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    } // made by _azcy

}
using namespace azcy;
const int N=1e3+10;
int n, m, s, t, u, v, inpw ,ans ,incf[N];
pair<int,int> prv[N];
struct node
{
    int dis;
    vector<int> w;
    vector<int> to;
    vector<int> addr;
    vector<int> cost;
} a[1020];
void add_edge(int x,int y,int v,int c){
    a[x].addr.push_back(a[y].to.size());
    a[y].addr.push_back(a[x].to.size());
    a[x].cost.push_back(c);
    a[y].cost.push_back(-c);
    a[x].to.push_back(y);
    a[y].to.push_back(x);
    a[x].w.push_back(v);
    a[y].w.push_back(0);
}
bitset<5020> vis;
int cur[N];
bool spfa(){
    for(int i=1;i<=n;++i)
        a[i].dis=INT_MAX;
    vis.reset();
    a[s].dis=0;
    vis[0]=1;
    incf[s]=INT_MAX;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<a[temp].to.size();++i)
        {
            int to=a[temp].to[i];
            if(a[to].dis>a[temp].dis+a[temp].cost[i]&&a[temp].w[i]){
                a[to].dis=a[temp].dis+a[temp].cost[i];
                incf[to]=min(incf[temp],a[temp].w[i]);
                prv[to]=make_pair(temp,i);
                if(vis[to]) continue;
                vis[to]=1;
                q.push(to);
            }
        }
        vis[temp]=0;
    }
    return (a[t].dis!=INT_MAX);
}
int maxw,minc,inpc;
main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for (int i = 1; i <= m; ++i)
    {
        cin >> u >> v >> inpw>>inpc;
        add_edge(u,v,inpw,inpc);
    }
    s=1,t=n;
    int temp;
    while(spfa()){
        int x=t;
        maxw+=incf[t];
        minc+=a[t].dis*incf[t];
        int temp;
        while(x!=s){
            int f_=prv[x].first,t_=prv[x].second,g_=a[f_].to[t_];
            a[f_].w[t_]-=incf[t];
            a[g_].w[a[f_].addr[t_]]+=incf[t];
            x=f_;
        }
    }
    cout<<maxw<<"\n";
    return 0;
}