#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
namespace IN {
    #define MAX_INPUT 25000003
    #define getc()(p1 == p2 && (p2 = (p1 = buf) + inbuf -> sgetn(buf, MAX_INPUT), p1 == p2) ? EOF : * p1++)
    char buf[MAX_INPUT], * p1, * p2;
    template < typename T > inline bool redi(T & x) {
        static std::streambuf * inbuf = cin.rdbuf();
        x = 0;
        register int f = 0, flag = false;
        register char ch = getc();
        while (!std::isdigit(ch)) {
            if (ch == '-') f = 1;
            ch = getc();
        }
        if (std::isdigit(ch)) x = x * 10 + ch - '0', ch = getc(), flag = true;
        while (std::isdigit(ch)) {
            x = x * 10 + ch - 48;
            ch = getc();
        }
        x = f ? -x : x;
        return flag;
    }
    template < typename T, typename...Args > inline bool redi(T & a, Args & ...args) {
        return redi(a) && redi(args...);
    }
    #undef getc
}

namespace OUT {
    template < typename T > inline void put(T x) {
        static std::streambuf * outbuf = cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf -> sputc('-');
            x = -x;
        }
        if (!x) {
            outbuf -> sputc('0');
            outbuf -> sputc('\n');
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf -> sputc(stack[top]);
            --top;
        }
        outbuf -> sputc('\n');
    }
    inline void putc(const char ch) {
        static std::streambuf * outbuf = cout.rdbuf();
        outbuf -> sputc(ch);
    }
    template < typename T > inline void put(const char ch, T x) {
        static std::streambuf * outbuf = cout.rdbuf();
        static char stack[21];
        static int top = 0;
        if (x < 0) {
            outbuf -> sputc('-');
            x = -x;
        }
        if (!x) {
            outbuf -> sputc('0');
            outbuf -> sputc(ch);
            return;
        }
        while (x) {
            stack[++top] = x % 10 + '0';
            x /= 10;
        }
        while (top) {
            outbuf -> sputc(stack[top]);
            --top;
        }
        outbuf -> sputc(ch);
    }
    template < typename T, typename...Args > inline void put(T a, Args...args) {
        put(a);
        put(args...);
    }
    template < typename T, typename...Args > inline void put(const char ch, T a, Args...args) {
        put(ch, a);
        put(ch, args...);
    }
}
using IN::redi;
using OUT::put;
using OUT::putc;
namespace azcy{
    using namespace std;
    bool debug_switch=1;
    void auto_init(){
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
    }
    void qfopen(string INPUT_FILE_NAME,string OUTPUT_FILE_NAME){
        freopen(INPUT_FILE_NAME.data(),"r",stdin);
        freopen(OUTPUT_FILE_NAME.data(),"w",stdout);
    }
    template<typename T>
    void dbgo(T x){
        cout<<x<<" ";
    }
    template<typename First,typename... Rest>
    void dbgo(First first,Rest... rest){
        cout<<first<<" ";
        dbgo(rest...);
    }  
    template<typename First,typename... Rest>
    void dbg(First first,Rest... rest){
        if(!debug_switch)return ;
        cout<<first<<" ";
        dbgo(rest...);
        cout<<"\n";
    }//made by _azcy
	template<typename T>
    void dbg(T x)
    {
        if (!debug_switch)
            return;
        cout << x << "\n";
    }
}using namespace azcy;
const int N=4e6+10;

#define int long long
mt19937 rnd(time(0));
struct node{
    int val,key,size,l,r;
}trp[N];
int cnt,root;
int newnode(int v){
    trp[++cnt].key=rnd();
    trp[cnt].val=v;
    trp[cnt].size=1;
    return cnt;
}
inline void update(int id){
    trp[id].size=trp[trp[id].l].size+trp[trp[id].r].size+1;
}
void split(int id,int v,int &x,int &y){
    if(!id) x=y=0;
    else{
        if(trp[id].val<=v){
            x=id;
            split(trp[id].r,v,trp[id].r,y);
        }else{
            y=id;
            split(trp[id].l,v,x,trp[id].l);
        }
        update(id);
    }
}
int merge(int a,int b){
    if(!a||!b) return a+b;
    if(trp[a].key>trp[b].key){
        trp[a].r=merge(trp[a].r,b);
        update(a);
        return a;
    }else{
        trp[b].l=merge(a,trp[b].l);
        update(b);
        return b;
    }
    throw runtime_error("RE___");
    
}
void insert(int v){
    int a,b;
    split(root,v,a,b);
    root=merge(merge(a,newnode(v)),b);
}
void query(int v){
    int x,y;
    split(root,v-1,x,y);
    dbg(trp[x].size+1);
    root=merge(x,y);
}
void getnum(int v){
    int cur=root;
    while(cur){
        if(trp[trp[cur].l].size+1==v) break;
        if(trp[trp[cur].l].size>=v) cur=trp[cur].l;
        else v-=trp[trp[cur].l].size+1,cur=trp[cur].r;
    }
    dbg(trp[cur].val);
}
void del(int v){
    int a,b,c;
    split(root,v,a,c);
    split(a,v-1,a,b);
    b=merge(trp[b].l,trp[b].r);
    root=merge(merge(a,b),c);
}
void pre(int v){
    int x,y;
    split(root,v-1,x,y);
    int id=x;
    while(trp[id].r)
        id=trp[id].r;
    dbg(trp[id].val);
    root=merge(x,y);
}
void nxt(int v){
    int x,y;
    split(root,v,x,y);
    int id=y;
    while(trp[id].l)
        id=trp[id].l;
    dbg(trp[id].val);
    root=merge(x,y);
}
int n,op,x;
main(){
	// ios::sync_with_stdio(0);
    auto_init();
    cin>>n;
    while(n--){
        cin>>op>>x;
        switch (op)
        {
        case 1:
            insert(x);
            break;
        case 2:
            del(x);
            break;
        case 3:
            query(x);
            break;
        case 4:
            getnum(x);
            break;
        case 5:
            pre(x);
            break;
        case 6:
            nxt(x);
            break;
        default:
            break;
        }
    }
    // system("pause");
}