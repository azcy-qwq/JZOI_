#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 38;
#define int long long
template <typename T, bool mode_>
class Sparce_Table
{
private:
    T data_[N][__lg(N) + 5];
    int maxn = 0, Log_n;

public:
    void insert(int x)
    {
        data_[++maxn][0] = x;
    }
    void build()
    {
        Log_n = __lg(maxn);
        for (int j = 1; j <= Log_n; ++j)
        {
            for (int i = 1; i + (1 << j) - 1 <= maxn; ++i)
            {
                if (mode_)
                    data_[i][j] = max(data_[i][j - 1], data_[i + (1 << (j - 1))][j - 1]);
                else
                    data_[i][j] = min(data_[i][j - 1], data_[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    inline T query(int l, int r)
    {
        if (l > r)
            swap(l, r);
        int s = __lg(r - l + 1);
        return mode_ ? max(data_[l][s], data_[r - (1 << s) + 1][s]) : min(data_[l][s], data_[r - (1 << s) + 1][s]);
    }
};
bool Legal(long long x)
{
    return (x >= INT_MAX || x <= INT_MIN) ? 0 : 1;
}
int n, m, l, r, a, b, t, res[2][5], q;
Sparce_Table<int, 1> sa1;
Sparce_Table<int, 0> sa2;
Sparce_Table<int, 1> sa3;
Sparce_Table<int, 0> sa4;
Sparce_Table<int, 1> sb1;
Sparce_Table<int, 0> sb2;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a;
        sa1.insert(a);
        sa2.insert(a);
        sa3.insert((a >= 0) ? INT_MIN : a);
        sa4.insert((a >= 0) ? a : INT_MAX);
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> b;
        sb1.insert(b);
        sb2.insert(b);
    }

    sa1.build(), sa2.build(), sa3.build(), sa4.build();
    sb1.build(), sb2.build();

    for (int k = 1; k <= q; ++k)
    {
        cin >> l >> r >> a >> b;

        res[0][1] = sa1.query(l, r);
        res[0][2] = sa2.query(l, r);
        res[0][3] = sa3.query(l, r);
        res[0][4] = sa4.query(l, r);
        res[1][1] = sb1.query(a, b);
        res[1][2] = sb2.query(a, b);

        t = LONG_LONG_MIN;
        for (int i = 1; i <= 4; ++i)
        {
            if (Legal(res[0][i]))
            {
                if (Legal(res[1][1]))
                    if (Legal(res[1][2]))
                        t = max(t, min(res[0][i] * res[1][1], res[0][i] * res[1][2]));
                    else
                        t = max(t, res[0][i] * res[1][1]);
                else if (Legal(res[1][2]))
                    t = max(t, res[0][i] * res[1][2]);
            }
        }

        cout << t << "\n";
    }
}