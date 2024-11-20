#include <bits/stdc++.h>
#define lc (p) << 1
#define rc (p) << 1 | 1
using namespace std;
const int N = 1e5 + 10;
int n, m, q;
struct Tree
{
    int l, r, maz, miz, maf, mif, ma, mi;
} t[N << 2], t2[N];
struct Node
{
    int maz, miz, maf, mif;
};
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
void pushup(int p)
{
    t[p].maf = max(t[lc].maf, t[rc].maf);
    t[p].maz = max(t[lc].maz, t[rc].maz);
    t[p].mif = min(t[lc].mif, t[rc].mif);
    t[p].miz = min(t[lc].miz, t[rc].miz);
    return;
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        int a = read();
        t[p].l = l, t[p].r = r;
        if (a < 0)
            t[p].maf = t[p].mif = a;
        else
            t[p].maz = t[p].miz = a;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}
Node query(int p, int l, int r)
{
    if (l <= t[p].l && t[p].r <= r)
        return {t[p].maz, t[p].maf, t[p].miz, t[p].mif};
    int mid = t[p].l + t[p].r >> 1;
    Node ans;
    if (mid >= l)
        ans = query(lc, l, r);
    if (mid < r)
    {
        Node res = query(rc, l, r);
        ans.maz = max(ans.maz, res.maz);
        ans.miz = min(ans.miz, res.miz);
        ans.maf = (ans.maf == 0 ? res.maf : max(ans.maf, res.maf));
        ans.mif = min(ans.mif, res.mif);
    }
    return ans;
}
void pushup(int p)
{
    t2[p].ma = max(t2[lc].ma, t2[rc].ma);
    t2[p].mi = min(t2[lc].mi, t2[rc].mi);
    return;
}
void build(int p, int l, int r)
{
    if (l == r)
    {
        int a = read();
        t2[p].l = l, t2[p].r = r;
        if (a < 0)
            t2[p].maf = t2[p].mif = a;
        else
            t2[p].maz = t2[p].miz = a;
    }
    int mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}
Node query(int p, int l, int r)
{
    if (l <= t2[p].l && t2[p].r <= r)
        return {t2[p].maz, t2[p].maf, t2[p].miz, t2[p].mif};
    int mid = t2[p].l + t2[p].r >> 1;
    Node ans;
    if (mid >= l)
        ans = query(lc, l, r);
    if (mid < r)
    {
        Node res = query(rc, l, r);
        ans.maz = max(ans.maz, res.maz);
        ans.miz = min(ans.miz, res.miz);
        ans.maf = (ans.maf == 0 ? res.maf : max(ans.maf, res.maf));
        ans.mif = min(ans.mif, res.mif);
    }
    return ans;
}
int main()
{
    cin >> n >> m >> q;
    build(1, 1, n);
    // Uncompleted
    return 0;
}