#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int solve(int x, int y)
{
    // dbg(x,y);
    return (int)floor(pow(floor(sqrt(1.0 * y / x)), 8.0 / 7));
}
int q, x, y;
int main()
{
    // freopen("ex_biggraph2.in","r",stdin);
//    qfopen("ex_biggraph2.in","ex_biggraph.out");
    ios::sync_with_stdio(0);
    cin >> q;
    for (int i = 1; i <= q; ++i)
    {
        cin >> x >> y;
        cout << exp(log(solve(x, y))) << "\n";
    }
}