#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

namespace IN
{
#define MAX_INPUT 25000003
#define getc() (p1 == p2 && (p2 = (p1 = buf) + inbuf->sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : *p1++)
    char buf[MAX_INPUT], *p1, *p2;
    template <typename T>
    inline bool redi(T &x)
    {
        static std::streambuf *inbuf = cin.rdbuf();
        x = 0;
        register int f = 0, flag = false;
        register char ch = getc();
        while (!std::isdigit(ch))
        {
            if (ch == '-')
                f = 1;
            ch = getc();
        }
        if (std::isdigit(ch))
            x = x * 10 + ch - '0', ch = getc(), flag = true;
        while (std::isdigit(ch))
        {
            x = x * 10 + ch - 48;
            ch = getc();
        }
        x = f ? -x : x;
        return flag;
    }
    template <typename T, typename... Args>
    inline bool redi(T &a, Args &...args)
    {
        return redi(a) && redi(args...);
    }
#undef getc
}

namespace OUT
{
    template <typename T>
    inline void put(T x)
    {
        static std::streambuf *outbuf = cerr.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0)
        {
            outbuf->sputc('-');
            x = -x;
        }
        if (!x)
        {
            outbuf->sputc('0');
            outbuf->sputc('\n');
            return;
        }
        while (x)
        {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top)
        {
            outbuf->sputc(stack[top]);
            --top;
        }
        outbuf->sputc('\n');
    }
    inline void putc(const char ch)
    {
        static std::streambuf *outbuf = cerr.rdbuf();
        outbuf->sputc(ch);
    }
    template <typename T>
    inline void put(const char ch, T x)
    {
        static std::streambuf *outbuf = cerr.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0)
        {
            outbuf->sputc('-');
            x = -x;
        }
        if (!x)
        {
            outbuf->sputc('0');
            outbuf->sputc(ch);
            return;
        }
        while (x)
        {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top)
        {
            outbuf->sputc(stack[top]);
            --top;
        }
        outbuf->sputc(ch);
    }
    template <typename T, typename... Args>
    inline void put(T a, Args... args)
    {
        put(a);
        put(args...);
    }
    template <typename T, typename... Args>
    inline void put(const char ch, T a, Args... args)
    {
        put(ch, a);
        put(ch, args...);
    }
}
using IN::redi;
using OUT::put;
using OUT::putc;
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
        cerr << x << " ";
    }
    template <typename First, typename... Rest>
    void dbgo(First first, Rest... rest)
    {
        cerr << first << " ";
        dbgo(rest...);
    }
    template <typename First, typename... Rest>
    void dbg(First first, Rest... rest)
    {
        if (!debug_switch)
            return;
        cerr << first << " ";
        dbgo(rest...);
        cerr << "\n";
    } // made by _azcy
    template <typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cerr << x << "\n";
    }
}
using namespace azcy;
const int N = (1 << 18) + 10;
int n, a[N], q, l, r, x;
template <typename T>
class Sparce_Table_Max
{
private:
    T data_[N][__lg(N) + 2];
    int maxn = 0, Log_n;

public:
    inline void insert(int x)
    {
        data_[++maxn][0] = x;
    }
    inline void build()
    {
        Log_n = __lg(maxn);
        for (int j = 1; j <= Log_n; ++j)
        {
            for (int i = 1; i + (1 << j) - 1 <= maxn; ++i)
            {
                data_[i][j] = max(data_[i][j - 1], data_[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    inline T query(int l, int r)
    {
        // if(l>r) swap(l,r);
        int s = __lg(r - l + 1);
        return max(data_[l][s], data_[r - (1 << s) + 1][s]);
    }
};
Sparce_Table_Max<int> st[16];

int main()
{
    // qfopen("qwq.in","qwq.out");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n > 2000)
    {
        for (int i = 1; i <= n; ++i)
        {
            // cin >> a[i];
            redi(a[i]);
            for (int j = 0; j < 16; ++j)
            {
                st[j].insert((a[i] | j));
            }
        }
        for (int j = 0; j < 16; ++j)
            st[j].build();
        cin >> q;
        for (int oo = 1; oo <= q; ++oo)
        {
            // cin >> l >> r >> x;
            redi(l,r,x);
            // cout << st[x].query(l, r)<<"\n";
            put(st[x].query(l, r));
        }
    }else{
        for(int i=1;i<=n;++i)
            cin>>a[i];
        cin>>q;
        for(int op=1;op<=q;++op){
            cin>>l>>r>>x;
            int ans=INT_MIN;
            for(int i=l;i<=r;++i){
                ans=max(ans,a[i]|x);
            }
            cout<<ans<<"\n";
        }
    }
//    cerr<<(double)clock()/CLOCKS_PER_SEC;
}
