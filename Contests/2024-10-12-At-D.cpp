#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+10;
#define sz(a) ((int)a.size())
struct SGT
{
    int l[N << 2], r[N << 2];
    ll val[N << 2], tag[N << 2];
#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)
    void Pushup(int p) { val[p] = val[ls(p)] + val[rs(p)]; }
    void Add(int p, ll v)
    {
        tag[p] += v;
        val[p] += v * (r[p] - l[p] + 1);
    }
    void Pushdown(int p)
    {
        if (tag[p])
            Add(ls(p), tag[p]), Add(rs(p), tag[p]), tag[p] = 0;
    }
    void Build(int p, int x, int y)
    {
        l[p] = x, r[p] = y;
        if (x == y)
        {
            val[p] = 0;
            return;
        }
        int mid = (x + y) >> 1;
        Build(ls(p), x, mid), Build(rs(p), mid + 1, y);
        Pushup(p);
    }
    void Update(int p, int x, int y, ll v)
    {
        if (l[p] >= x && r[p] <= y)
        {
            Add(p, v);
            return;
        }
        Pushdown(p);
        int mid = (l[p] + r[p]) >> 1;
        if (x <= mid)
            Update(ls(p), x, y, v);
        if (y > mid)
            Update(rs(p), x, y, v);
        Pushup(p);
    }
    ll Query(int p, int x, int y)
    {
        if (l[p] >= x && r[p] <= y)
            return val[p];
        Pushdown(p);
        int mid = (l[p] + r[p]) >> 1;
        ll res = 0;
        if (x <= mid)
            res += Query(ls(p), x, y);
        if (y > mid)
            res += Query(rs(p), x, y);
        return res;
    }
} T[26];
ll ans;
string s;
int main()
{
    // ios::sync_with_stdio(0);
    cin >> s;
    int n = sz(s),ch;
    s = '#' + s;
    for (int i = 0; i < 26; ++i)
        T[i].Build(1, 1, n);
    for (int i = 1; i <= n; ++i)
    {
        ch = s[i] - 'A';
        ans += T[ch].Query(1, 1, max(1, i - 1));
        T[ch].Update(1, min(i + 1, n), n, 1);
    }
    cout << ans;
}