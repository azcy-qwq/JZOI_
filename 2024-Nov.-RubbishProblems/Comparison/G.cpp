#include <bits/stdc++.h>
using namespace std;
long long to[2000020];
long long dp[2000020];
char a[2000020];
int main()
{
    long long n, i, j;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i <= n; i++)
    {
        to[i] = i - 1;
        while (a[i] != a[to[i]])
        {
            if (to[i] < 1 || to[to[i]] - 1 < 1)
            {
                to[i] = 0;
                break;
            }
            to[i] = to[to[i]] - 1;
        }
        if (to[i] == 0)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[to[i] - 1] + 1;
        }
    }
    long long ans = 0;
    for (i = 1; i <= n; i++)
    {
        ans += dp[i];
    }
    cout << ans << endl;
    return 0;
}