#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int t, n;
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
    } // made by _azcy
    template <typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    }
}
using namespace azcy;
int main()
{
    // 	ios::sync_with_stdio(0);
    auto_init();
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        if (n % 2)
        {
            cout << 1 << " " << n + 2 << " " << 2 << "\n";
        }
        else
        {
            // dbg(n,n*2,n*3);
            int x=n;
            while(x%2==0)
            {
                x/=2;
                // x*=2;
            }
            cout<<n/x<<" "<<n/x*2<<" "<<n/x*(x+2)<<"\n";
        }
    }
}