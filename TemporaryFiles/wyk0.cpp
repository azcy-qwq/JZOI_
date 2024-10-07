#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <map>
#define int long long
using namespace std;
int n, ans;
const int N = 1e6 + 10;
const int M = 1e7 + 10;
int a[N], g[M], gu[M];
bool flag = true;
inline int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
signed main()
{
    freopen("gcd.in","r",stdin);
    freopen("gcd.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int maxn = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    for (int i = 1; i <= n; i++)
        gu[a[i]]++;
    for (int i = 1; i <= n; i++)
        if (gu[a[i]] >1&&g[a[i]]!=1){
            // cout<<a[i];
            ans++,g[a[i]]=1;
        }
            
    n = unique(a + 1, a + 1 + n) - a - 1;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int x = gcd(a[i], a[j]);
            if(g[x]) continue;
            g[x] = 1;
            ++ans;
        }
    // for (int i = 1; i <= maxn; i++)
        // if (g[i])
            // ans++;
    cout << ans;

    return 0;
}