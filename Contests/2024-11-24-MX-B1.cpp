#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
using namespace std;
inline int read()
{
    int a = 0, f = 1;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar())
        if (ch == '-')
            f = -1;
    for (; ch <= '9' && ch >= '0'; ch = getchar())
        a = a * 10 + ch - '0';
    return a * f;
}
inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}
const int N = 2e5 + 10;
vector<PII> e[N];
int T, n, q, a[N], b[N], dis[N], fa[N][20], ma[N][20], dp[N], dep[N];
void dfs(int u, int fat)
{
    dp[u] = a[u];
    for (auto ed : e[u])
    {
        if (ed.fi == fat)
            continue;
        dis[ed.fi] = dis[u] + ed.se;
        dfs(ed.fi, u);
        dp[u] = max(dp[u], dp[ed.fi] - 2 * ed.se);
    }
}
void df5(int u, int fat)
{
    vector<int> x;
    fa[u][0] = fat, ma[u][0] = dp[fat], dep[u] = dep[fat] + 1;
    for (int i = 1; i <= 17; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        ma[u][i] = max(ma[u][i - 1], ma[fa[u][i - 1]][i - 1]);
    }
    for (auto ed : e[u])
    {
        if (ed.fi == fat)
            continue;
        x.push_back(dp[ed.fi] - 2 * ed.se);
    }
    x.push_back(b[u]), x.push_back(a[u]);
    sort(x.begin(), x.end(), greater<int>());
    for (auto ed : e[u])
    {
        if (ed.fi == fat)
            continue;
        if (dp[ed.fi] - 2 * ed.se == x[0])
            b[ed.fi] = x[1] - 2 * ed.se;
        else
            b[ed.fi] = x[0] - 2 * ed.se;
    }
    for (auto ed : e[u])
        if (ed.fi != fat)
            df5(ed.fi, u);
}
PII lca(int x, int y)
{
    if (dep[x] < dep[y])
        swap(x, y);
    int ans = max(dp[x], dp[y]);
    for (int i = 17; i >= 0; i--)
        if (dep[fa[x][i]] >= dep[y])
            ans = max(ans, ma[x][i]), x = fa[x][i];
    if (x == y)
        return {x, ans};
    for (int i = 17; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            ans = max(ans, max(ma[x][i], ma[y][i])), x = fa[x][i], y = fa[y][i];
    ans = max(ans, max(ma[x][0], ma[y][0]));
    return {fa[x][0], ans};
}
signed main()
{
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, u, v, w; i < n; i++)
    {
        u = read(), v = read(), w = read();
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0), df5(1, 0);
    while (q--)
    {
        int x = read(), y = read();
        PII z = lca(x, y);
        int l = (dis[x] + dis[y] - 2 * dis[z.fi]), res = max(z.se + a[x] + a[y] - l, a[x] + a[y] + b[z.fi] - l);
        cout << res << "\n";
    }
    return 0;
}