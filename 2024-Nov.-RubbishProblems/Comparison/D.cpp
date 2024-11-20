#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m, q, a[100011], b[100011];
ll a_maxz[400011], a_maxf[400011], a_minz[400011], a_minf[400011];
ll b_maxz[400011], b_maxf[400011], b_minz[400011], b_minf[400011];
int a_zero[400011], b_zero[400011];
ll a_maz, a_maf, a_miz, a_mif, b_maz, b_maf, b_miz, b_mif, a_ze, b_ze;
int ls(int x)
{
    return x << 1;
}
int rs(int x)
{
    return x << 1 | 1;
}
void pushupa(int x)
{
    a_zero[x] = a_zero[ls(x)] || a_zero[rs(x)];
    if (!a_maxz[ls(x)] || !a_maxz[rs(x)])
    {
        a_maxz[x] = a_maxz[ls(x)] + a_maxz[rs(x)];
        a_minz[x] = a_minz[ls(x)] + a_minz[rs(x)];
    }
    else
    {
        a_maxz[x] = max(a_maxz[ls(x)], a_maxz[rs(x)]);
        a_minz[x] = min(a_minz[ls(x)], a_minz[rs(x)]);
    }
    if (!a_maxf[ls(x)] || !a_maxf[rs(x)])
    {
        a_maxf[x] = a_maxf[ls(x)] + a_maxf[rs(x)];
        a_minf[x] = a_minf[ls(x)] + a_minf[rs(x)];
    }
    else
    {
        a_maxf[x] = max(a_maxf[ls(x)], a_maxf[rs(x)]);
        a_minf[x] = min(a_minf[ls(x)], a_minf[rs(x)]);
    }
}
void builda(int l, int r, int p)
{
    //	cout<<p<<" "<<l<<" "<<r<<endl;
    if (l == r)
    {
        if (a[l] == 0)
        {
            a_zero[p] = 1;
        }
        else if (a[l] > 0)
        {
            a_maxz[p] = a_minz[p] = a[l];
        }
        else
        {
            a_maxf[p] = a_minf[p] = a[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    builda(l, mid, ls(p));
    builda(mid + 1, r, rs(p));
    pushupa(p);
}
void pushupb(int x)
{
    b_zero[x] = b_zero[ls(x)] || b_zero[rs(x)];
    if (!b_maxz[ls(x)] || !b_maxz[rs(x)])
    {
        b_maxz[x] = b_maxz[ls(x)] + b_maxz[rs(x)];
        b_minz[x] = b_minz[ls(x)] + b_minz[rs(x)];
    }
    else
    {
        b_maxz[x] = max(b_maxz[ls(x)], b_maxz[rs(x)]);
        b_minz[x] = min(b_minz[ls(x)], b_minz[rs(x)]);
    }
    if (!b_maxf[ls(x)] || !b_maxf[rs(x)])
    {
        b_maxf[x] = b_maxf[ls(x)] + b_maxf[rs(x)];
        b_minf[x] = b_minf[ls(x)] + b_minf[rs(x)];
    }
    else
    {
        b_maxf[x] = max(b_maxf[ls(x)], b_maxf[rs(x)]);
        b_minf[x] = min(b_minf[ls(x)], b_minf[rs(x)]);
    }
}
void buildb(int l, int r, int p)
{
    //	cout<<p<<endl;
    if (l == r)
    {
        if (b[l] == 0)
        {
            b_zero[p] = 1;
        }
        else if (b[l] > 0)
        {
            b_maxz[p] = b_minz[p] = b[l];
        }
        else
        {
            b_maxf[p] = b_minf[p] = b[l];
        }
        return;
    }
    int mid = (l + r) >> 1;
    buildb(l, mid, ls(p));
    buildb(mid + 1, r, rs(p));
    pushupb(p);
}
void quary_a(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        a_maz = max(a_maz, a_maxz[p]);
        if (a_minz[p] != 0)
            a_miz = min(a_miz, a_minz[p]);
        if (a_maxf[p] != 0)
            a_maf = max(a_maf, a_maxf[p]);
        a_mif = min(a_mif, a_minf[p]);
        a_ze = a_ze || a_zero[p];
        return;
    }
    int mid = (nl + nr) >> 1;
    if (l <= mid)
    {
        quary_a(l, r, nl, mid, ls(p));
    }
    if (r > mid)
    {
        quary_a(l, r, mid + 1, nr, rs(p));
    }
}
void quary_b(int l, int r, int nl, int nr, int p)
{
    if (l <= nl && nr <= r)
    {
        b_maz = max(b_maz, b_maxz[p]);
        if (b_minz[p] != 0)
            b_miz = min(b_miz, b_minz[p]);
        if (b_maxf[p] != 0)
            b_maf = max(b_maf, b_maxf[p]);
        b_mif = min(b_mif, b_minf[p]);
        b_ze = b_ze || b_zero[p];
        return;
    }
    int mid = (nl + nr) >> 1;
    if (l <= mid)
    {
        quary_b(l, r, nl, mid, ls(p));
    }
    if (r > mid)
    {
        quary_b(l, r, mid + 1, nr, rs(p));
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    builda(1, n, 1);
    buildb(1, m, 1);
    //	for(int i=1;i<=4*n;i++){
    //		cout<<a_maxz[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<a_minz[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<a_maxf[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<a_minf[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<a_zero[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<b_maxz[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<b_minz[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<b_maxf[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<b_minf[i]<<" ";
    //	}
    //	cout<<endl;
    //	for(int i=1;i<=4*n;i++){
    //		cout<<b_zero[i]<<" ";
    //	}
    //	cout<<endl;
    int l1, l2, r1, r2;
    for (int i = 1; i <= q; i++)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        a_maz = 0;
        a_maf = -1e9;
        a_miz = 1e9;
        a_mif = 0;
        b_maz = 0;
        b_maf = -1e9;
        b_miz = 1e9;
        b_mif = 0;
        a_ze = 0;
        b_ze = 0;
        quary_a(l1, r1, 1, n, 1);
        quary_b(l2, r2, 1, m, 1);
        //		cout<<a_maz<<" "<<a_miz<<" "<<a_maf<<" "<<a_mif<<" "<<a_ze<<endl;
        //		cout<<b_maz<<" "<<b_miz<<" "<<b_maf<<" "<<b_mif<<" "<<b_ze<<endl;
        if (b_mif != 0 && b_miz == 1e9)
        {
            //		cout<<1;
            if (a_mif != 0)
            {
                if (b_ze != 0)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << a_mif * b_maf << endl;
                }
            }
            else
            {
                if (a_ze == 1)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << a_miz * b_mif << endl;
                }
            }
        }
        else if (b_mif == 0 && b_miz != 0)
        {
            //		cout<<2;
            if (a_miz != 1e9)
            {
                if (b_ze == 1)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << b_miz * a_maz << endl;
                }
            }
            else
            {
                if (a_ze == 1)
                {
                    cout << 0 << endl;
                }
                else
                {
                    cout << a_maf * b_maz << endl;
                }
            }
        }
        else
        {
            //		cout<<3;
            if (a_ze == 1)
            {
                cout << 0 << endl;
            }
            else if (a_mif != 0 && a_miz == 1e9)
            {
                cout << a_maf * b_maz << endl;
            }
            else if (a_mif == 0 && a_miz != 1e9)
            {
                cout << a_miz * b_mif << endl;
            }
            else
            {
                cout << max(a_miz * b_mif, a_maf * b_maz) << endl;
            }
        }
    }
    return 0;
}