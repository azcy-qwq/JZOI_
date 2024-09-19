#include<bits/stdc++.h>
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
        static std::streambuf *outbuf = cout.rdbuf();
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
        static std::streambuf *outbuf = cout.rdbuf();
        outbuf->sputc(ch);
    }
    template <typename T>
    inline void put(const char ch, T x)
    {
        static std::streambuf *outbuf = cout.rdbuf();
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
const int N = 3e3 + 10;
int n, m;
class POOL_
{
private:
    char cards[N];
    int top = 0, cur = 0;

public:
    void insert(char ch)
    {
        cards[++top] = ch;
    }
    char get()
    {
        if (cur < top)
            ++cur;
        return cards[cur];
    }
} pool;
template <typename T>
class chain_list
{
public:
    vector<T> data;
    vector<int> next;
    vector<int> head;
    int tail = 0;
    void push_back(T x)
    {
        // tail=data.size()-1;
        data.push_back(x);
        head.push_back(tail);
        if (next.size())
            next[tail] = next.size();
        next.push_back(next.size() - 1);
        tail = data.size() - 1;
    }
    chain_list()
    {
        push_back(0);
    }
    void del(int x)
    {
        if (x == 0)
        {
            cerr << "Error:Attempt to delete node 0\n";
            return;
        }
        if (tail == x)
            tail = head[x];
        next[head[x]] = next[x];
        head[next[x]] = head[x];
    }
    int get_head()
    {
        return next[0];
    }
    void get_next(int &x)
    {
        x = next[x];
    }
    void get_prv(int &x)
    {
        x = head[x];
    }
    int find(T x)
    {
        int u = get_head();
        while (next[u] != u)
        {
            if (data[u] == x)
                return u;
        }
        return -1;
    }
};
char out_ident[N];
class pig_
{
protected:
public:
	bool equip=0;
    int hp=4;
    char identity;
    // chain_list<char> cards;
    string cards;
} pig[N >> 2];
string s;
char ch;
int check(){
    int f=1;
    for(int i=1;i<=n;++i){
        if(pig[i].identity=='m'&&pig[i].hp<=0) return -1;
        if(pig[i].identity=='f'&&pig[i].hp>0){
            // return 1;
            f=0;
        }
    }
    return f;
}
bool alive(int id){
    return (pig[id].hp>0)?1:0;
}
int main()
{
    //	ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        
        if (s[0] == 'F')
            pig[i].identity = 'f';
        else if (s[0] == 'M')
            pig[i].identity = 'm';
        else
            pig[i].identity = 'z';
        // dbg(pig[i].identity);
        for (int j = 1; j <= 4; ++j)
        {
            cin >> ch;
            ch=ch-'A'+'a';
            pig[i].cards+=ch;
            // pig[i].cards.push_back(ch);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cin >> ch;
        pool.insert(ch);
    }
    // for(int i=1;i<=100;++i)
    //     cout<<pool.get();
    int cur;
    do{
        ++cur;
        cur=(cur-1)%n+1;
        if(!alive(cur)) continue;
        for(int i=1;i<=2;++i)
            pig[cur].cards+=pool.get();
        while(alive(cur)){
            if(pig[cur].cards.length()==0) break;
			for(int i=0;i<pig[cur].cards.length();++i){

			}
        }
    }while(check()==0);
}
