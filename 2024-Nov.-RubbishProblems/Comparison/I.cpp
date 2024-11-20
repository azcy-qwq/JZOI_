#include <bits/stdc++.h>
using namespace std;
const int mod = 10;
struct node
{
    int fir, sec, thi, fou, fif;
} a[mod + 1];
int dp[mod + 1][mod + 1][mod + 1][mod + 1][mod + 1];
int n, ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fir >> a[i].sec >> a[i].thi >> a[i].fou >> a[i].fif;
        for (int j = 1; j <= 9; j++)
        {
            dp[(a[i].fir + j) % mod][a[i].sec][a[i].thi][a[i].fou][a[i].fif]++;
            dp[a[i].fir][(a[i].sec + j) % mod][a[i].thi][a[i].fou][a[i].fif]++;
            dp[a[i].fir][a[i].sec][(a[i].thi + j) % mod][a[i].fou][a[i].fif]++;
            dp[a[i].fir][a[i].sec][a[i].thi][(a[i].fou + j) % mod][a[i].fif]++;
            dp[a[i].fir][a[i].sec][a[i].thi][a[i].fou][(a[i].fif + j) % mod]++;
            dp[(a[i].fir + j) % mod][(a[i].sec + j) % mod][a[i].thi][a[i].fou][a[i].fif]++;
            dp[a[i].fir][(a[i].sec + j) % mod][(a[i].thi + j) % mod][a[i].fou][a[i].fif]++;
            dp[a[i].fir][a[i].sec][(a[i].thi + j) % mod][(a[i].fou + j) % mod][a[i].fif]++;
            dp[a[i].fir][a[i].sec][a[i].thi][(a[i].fou + j) % mod][(a[i].fif + j) % mod]++;
        }
    }
    for (int a = 0; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            for (int c = 0; c < 10; c++)
            {
                for (int d = 0; d < 10; d++)
                {
                    for (int e = 0; e < 10; e++)
                    {
                        if (dp[a][b][c][d][e] == n)
                            ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}